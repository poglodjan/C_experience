#include <iostream>
#include <iomanip>  // strings manipulating
using namespace std;
#include "Sensor.h"

int Sensor::sensor_numbers=0;

Sensor::Sensor() : sensor_sn(++sensor_numbers),
series_name("Basic Line"), state(SensorState::inactive)
{
  cout << "Sensor " << sensor_sn << " - c-tor!" << endl;
  if(!(sensor_numbers%3)) //every third is broken
  {
    state = Sensor::SensorState::damaged;
  }
}

Sensor::Sensor(string series_name) : sensor_sn(++sensor_numbers), 
series_name(series_name), state(SensorState::inactive)
{
  out << "Sensor " << sensor_sn << " - c-tor!" << endl;
  if(!(sensor_numbers%3)) //every third is broken
  {
    state = Sensor::SensorState::damaged;
  }
}

Sensor::~Sensor()
{
	cout << "Sensor " << sensor_sn << " - d-tor!" << endl;
}

void Sensor::on()
{
  if (state != SensorState::damaged)
  {
    state = SensorState::active;
  }
}

void Sensor::off()
{
  if (state != SensorState::damaged)
  {
    state = SensorState::inactive;
  }
}

bool Sensor::violation()
{
  if (state != SensorState::damaged)
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

ostream& Sensor::info(ostream& out) const
{
	cout << "Model: " << series_name << " SN: " << sensor_sn << " State: " << static_cast<int>(state) << endl;
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
