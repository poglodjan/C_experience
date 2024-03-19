#include <iostream>
using namespace std;
#include "color.h"

Color::Color() : channelX(0), channelY(0), channelZ(0), isRGB(true) {}

Color::Color(int channelX, int channelY, int channelZ) : channelX(channelX), channelY(channelY), channelZ(channelZ) {
	this->channelX = clampedValue(channelX / 255, 0, 1);
	this->channelY = clampedValue(channelY / 255, 0, 1);
	this->channelZ = clampedValue(channelZ / 255, 0, 1);
	this->isRGB = true;
}
Color::Color(float channelX, float channelY, float channelZ, bool isRGB) : channelX(channelX), channelY(channelY), channelZ(channelZ), isRGB(isRGB) {
	this->channelX = clampedValue(channelX, 0, 360);
	this->channelY = clampedValue(channelY, 0, 1);
	this->channelZ = clampedValue(channelZ, 0, 1);
	this->isRGB = false;
}


Color::Color(float channelX, float channelY, float channelZ) : channelX(channelX), channelY(channelY), channelZ(channelZ) {
	channelX = clampedValue(channelX, 0, 1);
	channelY = clampedValue(channelY, 0, 1);
	channelZ = clampedValue(channelZ, 0, 1);
	this->isRGB = true;
}

bool& Color::SetFormat(bool displayFormat) {
	format = displayFormat;
	return format;
}

float Color::clampedValue(float value, float minValue, float maxValue)
{
	return std::max(minValue, std::min(maxValue, value));
}

Color::Color(const char* hex_color) {
	float chX = 0, chY = 0, chZ = 0;
	bool isValid=true;
	int r1, r2, g1, g2, b1, b2;
	tryPraseColorChannel(hex_color[0], r1);
	tryPraseColorChannel(hex_color[1], r2);
	tryPraseColorChannel(hex_color[2], g1);
	tryPraseColorChannel(hex_color[3], g2);
	tryPraseColorChannel(hex_color[4], b1);
	tryPraseColorChannel(hex_color[5], b2);

	if (!tryPraseColorChannel(hex_color[0], r1) || 
		!tryPraseColorChannel(hex_color[1], r2) || 
		!tryPraseColorChannel(hex_color[2], g1) || 
		!tryPraseColorChannel(hex_color[3], g2) || 
		!tryPraseColorChannel(hex_color[4], b1) || 
		!tryPraseColorChannel(hex_color[5], b2)){
		isValid=false;
		cout << "Invalid color!";
	}

	chX = 16*r1 + r2;
	chY = 16*g1 + g2;
	chZ = 16*b1 + b2;
	
	this->channelX = clampedValue(chX / 255, 0, 1);
	this->channelY = clampedValue(chY / 255, 0, 1);
	this->channelZ = clampedValue(chZ / 255, 0, 1);
	if(isValid==true) this->isRGB = true;
}

bool Color::tryPraseColorChannel(char c, int& channelValue) {
	if ('0' <= c && c <= '9') {
		channelValue = c - '0';
		return true;
	}
	else if ('A' <= c && c <= 'F') {
		channelValue = c - 'A' + 10;
		return true;
	}
	else if ('a' <= c && c <= 'f') {
		channelValue = c - 'a' + 10;
		return true;
	}
	else return false;
}

ostream& operator<<(ostream& out, const Color& c) {
	if (c.isRGB == true) {
		if (c.format == false) {
			out << "Color RGB : (" << c.channelX << "," << c.channelY << "," << c.channelZ << ")" << endl;
			return out;
		}
		if (c.format == true) {
			out << "Color RGB : (" << c.channelX * 255 << "," << c.channelY * 255 << "," << c.channelZ * 255 << ")" << endl;
			return out;
		}
	}

	if (c.isRGB == false) {
		if (c.format == false) {
			out << "Color HSV : (" << c.channelX << "," << c.channelY << "," << c.channelZ << ")" << endl;
			return out;
		}
		if (c.format == true) {
			out << "Color HSV : (" << c.channelX << "," << c.channelY * 100 << "%," << c.channelZ * 100 << "%)" << endl;
			return out;
		}
	}
	return out; 
}
