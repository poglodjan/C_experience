#pragma once
#include <iostream>
using namespace std;

class Color {
private:
	float channelX;
	float channelY;
	float channelZ;
	bool isRGB;
	bool format;

public:
	Color();
	Color(float channelX, float channelY, float channelZ);
	Color(float channelX, float channelY, float channelZ, bool isRGB);
	Color(int channelX, int channelY, int channelZ);
	Color(const char* hex_color);
	bool tryPraseColorChannel(char c, int& channelValue);

	bool& SetFormat();
	float clampedValue(float value, float minValue, float maxValue);
	friend ostream& operator<<(ostream& out, const Color&);
};
