#pragma once

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
  ~Sensor();
  void on();
  void off();
  bool violation();
  void reset();
  friend ostream& operator<<(ostream& out, const Sensor& s);
  friend bool operator==(const Sensor& s1, const Sensor& s2);
};

class MoveSensor : public Sensor
{
  int move_sensor_sn;
  static int move_sensor_numbers;
public:
  MoveSensor();
  ~MoveSensor();
  MoveSensor(string series_name);
  double temperature() const;
  ostream& info(ostream& out) const;
	friend ostream& operator<<(ostream& out, const MoveSensor& s);
}
