#include <iostream>
#include <iomanip>  // strings manipulating
using namespace std;
#include "Sensor.h"

int MoveSensor::move_sensor_numbers=0;

MoveSensor::MoveSensor() : move_sensor_sn(++move_sensor_numbers)
{
  cout << "Move Sensor " << sensor_sn << 
  " " << move_sensor_sn << " - default c-tor!" << endl;
}

MoveSensor::~MoveSensor()
{
	cout << "Move Sensor " << sensor_sn << 
  " " << move_sensor_sn << " - d-tor!" << endl;
}

MoveSensor::MoveSensor(string series_name) : Sensor(series_name), 
move_sensor_sn(++move_sensor_numbers)
{
	this->series_name = series_name;
}

ostream& MoveSensor::info(ostream& out) const
{
	out << "Move Sensor SN: " << move_sensor_sn << " ";
	Sensor::info(out);
	return out;
}

ostream& operator<<(ostream& out, const MoveSensor& s)
{
	s.info(out);
	return out;
}

double MoveSensor::temperature() const
{
	return (double)rand() / RAND_MAX * 80.0 - 40.0; //double in range -40 to 40
}
