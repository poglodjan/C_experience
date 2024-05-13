// .h
using namespace std;
#include <string.h>
#include <iostream>
#include <iomanip>
#include <exception>

// class Sensor
class Sensor
{
public:
    enum class SensorState{
        inactive,
        active,
        damaged,
        violated
    };
protected:
    SensorState state;
    int sensor_sn;
    string series_name;
    static int sensor_numbers;
public:
    Sensor();
    Sensor(string series_name);
    Sensor(const Sensor& s);

    virtual ~Sensor();
    SensorState sensor_state() const {return state;}
    void on();
    void off();
    bool violation();
    bool violation(string message);
    void reset();
    virtual Sensor* clone_sensor() const = 0;
	virtual ostream& info(ostream&) const = 0;
	virtual ostream& general_info(ostream&) const final;
	friend ostream& operator<<(ostream& out, const Sensor& s);
	friend bool operator==(const Sensor& s1, const Sensor& s2);
};

// class MoveSensor

class MoveSensor : public Sensor
{
    int move_sensor_sn;
    static int move_sensor_numbers;
public:
    MoveSensor();
    MoveSensor(string series_name);
    MoveSensor(const MoveSensor& ms);

    virtual MoveSensor* clone_sensor() const override;

    virtual ~MoveSensor();
    double temperature() const;
    bool violation();
    bool violation(string message);
	virtual ostream& info(ostream& out) const override;
};

class WindowSensor : public Sensor
{
    int window_sensor_sn;
    static int window_sensor_number;
public:
    WindowSensor();
    virtual ~WindowSensor();
    WindowSensor(const WindowSensor& ws);
    virtual WindowSensor* clone_sensor() const override;
    WindowSensor(string seriees_name);
    using Sensor::violation;
    bool violation(string message);
    virtual ostream& info(ostream& out) const override;
};

class AlarmSystem
{
    static const int max_sensor_no = 8;
    Sensor** sensors;
    int sensors_number;
public:
    AlarmSystem();
    ~AlarmSystem();
    AlarmSystem(const AlarmSystem& as);
    AlarmSystem& operator=(const AlarmSystem& as);
    void add_sensor(Sensor* s);
    void activate();
    void deactivate();
    void activate_all_window();
    void system_status() const;
};

class AdvancedAlarmSystem : public AlarmSystem
{
    static const int reserve_sensor_no=2;
    Sensor** reserve_sensors;
public:
    AdvancedAlarmSystem();
    ~AdvancedAlarmSystem();
    AdvancedAlarmSystem(const AdvancedAlarmSystem& as);
    AdvancedAlarmSystem& operator=(const AdvancedAlarmSystem& as);
};

class MaxSensorException : public std::exception {
	string Reason;
public: 
	MaxSensorException(const char* why) : Reason(why) {} 
	virtual const char* what() const noexcept override { return Reason.c_str(); }
};

//
// ****************** Sensor ******************
//

int Sensor::sensor_numbers = 0;
int MoveSensor::move_sensor_numbers = 0;
int WindowSensor::window_sensor_number = 0;

Sensor::Sensor() : sensor_sn(++sensor_numbers),
series_name("Basic line"), state(SensorState::inactive)
{
    if(!(sensor_numbers %3 )) state = Sensor::SensorState::damaged;
} // every third is damaged

Sensor::Sensor(string series_name) : sensor_sn(++sensor_numbers), 
series_name(series_name), state(SensorState::inactive)
{
	if (!(sensor_numbers % 3)) state = Sensor::SensorState::damaged;
}

Sensor::~Sensor(){}

void Sensor::on()
{
	if (state != SensorState::damaged)
		state = SensorState::active;
}

bool Sensor::violation()
{
    if(state == SensorState::active)
    {
        state = SensorState::violated;
        return true;
    }
    return false;
}
bool Sensor::violation(string message)
{
	if (violation())
	{
		cout << message << " Sensor " << sensor_sn << " violated !!!" << endl;
		return true;
	}
	return false;
}

void Sensor::reset()
{
	if (state == SensorState::violated)
		state = SensorState::inactive;
}

ostream& Sensor::general_info(ostream& out) const
{
    out<< "Model: " << series_name << " SN: " << sensor_sn <<
    "State: " << static_cast<int>(state) << endl;
    return out;
}

ostream& operator<<(ostream& out, const Sensor& s)
{
	s.info(out);
	return out;
}

bool operator==(const Sensor& s1, const Sensor& s2)
{
	return s1.state == s2.state;
}

// ****************** Move ******************

MoveSensor::MoveSensor() : move_sensor_sn(++move_sensor_numbers){}
MoveSensor::~MoveSensor(){}
MoveSensor::MoveSensor(string series_name) : Sensor(series_name), move_sensor_sn(++move_sensor_numbers){}

double MoveSensor::temperature() const
{
	return (double)rand() / RAND_MAX * 80.0 - 40.0;
}

bool MoveSensor::violation(string message)
{
    return Sensor::violation();
}

bool MoveSensor::violation(string message)
{
	if (violation()) //  Sensor::violation()
	{
		cout << message << " Move Sensor " << 
        move_sensor_sn << " (" << sensor_sn << ") "
        << "violated !!!" << endl;
		return true;
	}
	return false;
}

ostream& MoveSensor::info(ostream& out) const
{
	out << "Move Sensor SN: " << move_sensor_sn << " ";
	Sensor::general_info(out);
	return out;
}

MoveSensor* MoveSensor::clone_sensor() const
{
	return new MoveSensor(*this);
}

// ******************** WindowSensor ********************
WindowSensor::WindowSensor() : window_sensor_sn(++window_sensor_number){}

WindowSensor::~WindowSensor(){}

WindowSensor::WindowSensor(string series_name) : 
Sensor(series_name), window_sensor_sn(++window_sensor_number){}

ostream& WindowSensor::info(ostream& out) const
{
	out << "Window Sensor SN: " << window_sensor_sn << " ";
	Sensor::general_info(out);
	return out;
}

bool WindowSensor::violation(string message)
{
	if (violation())
	{
		cout << message << " Window Sensor " << window_sensor_sn << 
        " (" << sensor_sn << ") violated !!!" << endl;
	}
	return false;
}

WindowSensor* WindowSensor::clone_sensor() const
{
	return new WindowSensor(*this);
}

// ******************** AlarmSystem ********************
AlarmSystem::AlarmSystem() : sensors_number(0), sensors(nullptr)
{
    sensors = new Sensor * [max_sensor_no];
    for(int i=0; i<max_sensor_no; i++)
        sensors[i] = nullptr;
}

AlarmSystem::~AlarmSystem()
{
    for(int i=0; i<sensors_number; i++)
        delete sensors[i];
    delete[] sensors;
}

void AlarmSystem::add_sensor(Sensor* s)
{
    if(sensors_number >= max_sensor_no)
        throw MaxSensorException("Max Sensor");
    sensors[sensors_number] = s;
    sensors_number++;
}

void AlarmSystem::activate()
{
    for(int i=0; i<sensors_number; i++)
        sensors[i]->on();
}
void AlarmSystem::deactivate()
{
    for(int i=0; i<sensors_number; i++)
        sensors[i]->off();
}

void AlarmSystem::system_status() const
{
    if(!sensors_number)
        cout<<"No Sensors!" <<endl;
    else
    {
        cout<<"Sensors status: ";
        for(int i=0; i<sensors_number; i++)
            cout << 
            static_cast<int>(sensors[i]->sensor_state())
            << " ";
        cout << endl;
        cout << "Sensor details: " << endl;
        for(int i=0; i<sensors_number; i++)
            cout<<*sensors[i];
    }
}

void AlarmSystem::activate_all_window()
{
    WindowSensor* s = nullptr;
    for(int i=0; i<sensors_number; i++)
        if(s = dynamic_cast<WindowSensor*>(sensors[i]))
            s->on();
}

AlarmSystem& AlarmSystem::operator=(const AlarmSystem& as)
{
    if (this==&as)
        return *this;
    
    for(int i=0; i<sensors_number; i++)
    {
        delete sensors[i];
        sensors[i] = nullptr;
    }
    sensors_number = 0;

    sensors_number = as.sensors_number;
    for(int i=0; i<sensors_number; i++)
        sensors[i] = as.sensors[i]->clone_sensor();
    return *this;
}

AdvancedAlarmSystem::AdvancedAlarmSystem()
{
    reserve_sensors = new Sensor * [reserve_sensor_no];
    reserve_sensors[0] = new MoveSensor();
    reserve_sensors[1] = new WindowSensor();
}

AdvancedAlarmSystem::~AdvancedAlarmSystem()
{
	for (int i = 0; i < reserve_sensor_no; i++)
		delete reserve_sensors[i];
	delete[] reserve_sensors;
}

AdvancedAlarmSystem::AdvancedAlarmSystem(const AdvancedAlarmSystem& as)
: AlarmSystem(as)
{
	reserve_sensors = new Sensor * [reserve_sensor_no];
	reserve_sensors[0] = new MoveSensor();
	reserve_sensors[1] = new WindowSensor();
}

AlarmSystem::AlarmSystem(const AlarmSystem& as) 
: sensors_number(as.sensors_number), sensors(nullptr)
{
	sensors = new Sensor * [max_sensor_no];
	for (int i = 0; i < max_sensor_no; i++)
		sensors[i] = nullptr;
	for (int i = 0; i < sensors_number; i++)
		//!  sensors[i] = as.sensors[i]; // shalow copy
		//!  sensors[i] = new Sensor(*as.sensors[i]); //not virtual
		sensors[i] = as.sensors[i]->clone_sensor();
}

AdvancedAlarmSystem& AdvancedAlarmSystem::operator=(const AdvancedAlarmSystem& as)
{
	if (this == &as)
		return *this;

	for (int i = 0; i < reserve_sensor_no; i++)
		delete reserve_sensors[i];
	reserve_sensors[0] = as.reserve_sensors[0]->clone_sensor();
	reserve_sensors[1] = as.reserve_sensors[1]->clone_sensor();

	(AlarmSystem&)(*this) = as; 
	return *this;
}

Sensor::Sensor(const Sensor& s) 
: sensor_sn(++sensor_numbers), series_name(s.series_name), 
state(s.state)
{
	if (!(sensor_numbers % 3)) 
		state = Sensor::SensorState::damaged;
}

MoveSensor::MoveSensor(const MoveSensor& ms) : 
Sensor(ms), move_sensor_sn(++move_sensor_numbers)
{
}

WindowSensor::WindowSensor(const WindowSensor& ws) : 
Sensor(ws), window_sensor_sn(++window_sensor_number)
{
}

//
// ******************** _main_ ********************
//
int main()
{
	try {

	AlarmSystem as;
	as.add_sensor(new MoveSensor());
	as.add_sensor(new WindowSensor());
	as.add_sensor(new MoveSensor());
	as.add_sensor(new WindowSensor());
	as.add_sensor(new MoveSensor());
	as.add_sensor(new WindowSensor());

	as.system_status();

	as.activate();
	cout << endl;
	as.system_status();
	
		as.add_sensor(new WindowSensor());
		as.add_sensor(new WindowSensor());
		as.add_sensor(new WindowSensor());
	}
	catch (bad_alloc& e)
	{
		cout << "Bad alloc Exception!" << endl;
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << "Exception" << endl;
		cout << e.what() << endl;
	}
	catch (int& e)
	{
		cout << "Max number of sensors " << e << " reached!" << endl;
	}
	catch (...)
	{
		cout << "Unnkown Exception!" << endl;
	}

	return 0;
}


