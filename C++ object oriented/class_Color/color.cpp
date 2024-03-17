#include <iostream>
using namespace std;
#include "color.h"

Color::Color(){
	this->channelX = 0;
	this->channelY = 0;
	this->channelZ = 0;
	this->isRGB = true;
}

Color::Color(int channelX, int channelY, int channelZ) : channelX(channelX), channelY(channelY), channelZ(channelZ){
	this->channelX = clampedValue(channelX / 255, 0, 1);
	this->channelY = clampedValue(channelY / 255, 0, 1);
	this->channelZ = clampedValue(channelZ / 255, 0, 1);
	this->isRGB = true;
}
Color::Color(float channelX, float channelY, float channelZ, bool isRGB) : channelX(channelX), channelY(channelY), channelZ(channelZ), isRGB(isRGB){
	this->channelX = clampedValue(channelX, 0, 360);
	this->channelY = clampedValue(channelY, 0, 1);
	this->channelZ = clampedValue(channelZ, 0, 1);
	this->isRGB = true;
}


Color::Color(float channelX, float channelY, float channelZ) : channelX(channelX), channelY(channelY), channelZ(channelZ){
	channelX = clampedValue(channelX,0,1);
	channelY = clampedValue(channelY,0,1);
	channelZ = clampedValue(channelZ,0,1);
	this->isRGB = true;
}

bool& Color::SetFormat() {
	return format;
}

float Color::clampedValue(float value, float minValue, float maxValue)
{
	return std::max(minValue, std::min(maxValue, value));
}

Color::Color(const char* hex_color) {
	int chX=0, chY=0, chZ=0;
	char c;
	int channelValue=0;
	for (int i = 0; i < 6; i++)
	{
		switch (i) {
		case 0:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chX += 16 * channelValue;
			}
			continue;
		case 1:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chX += channelValue;
			}
			continue;
		case 2:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chY += 16 * channelValue;
			}
			continue;
		case 3:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chY += channelValue;
			}
			continue;
		case 4:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chZ += 16 * channelValue;
			}
			continue;
		case 5:
			c = hex_color[i];
			if (tryPraseColorChannel(c, channelValue)) {
				chZ += channelValue;
			}
			continue;
		}
	}
	this->channelX = clampedValue(chX / 255, 0, 1);
	this->channelY = clampedValue(chY / 255, 0, 1);
	this->channelZ = clampedValue(chZ / 255, 0, 1);
}

bool Color::tryPraseColorChannel(char c, int& channelValue) {
	if (c == '0' or c == '1' or c == '2' or c == '3' or c == '4' or
		c == '5' or c == '6' or c == '7' or c == '8' or c == '9') {
		channelValue = int(c);
		return true;
	}
	else if (c == 'A' or c == 'B' or c == 'C' or c == 'D' or c == 'E' or c == 'F') {
		switch (c) {
		case 'A':channelValue = 10;
		case 'B':channelValue = 11;
		case 'C':channelValue = 12;
		case 'D':channelValue = 13;
		case 'E':channelValue = 14;
		case 'F':channelValue = 15;
		default: channelValue = 1;
		}
		return true;
	}
	else return false;
}

ostream& operator<<(ostream& out, const Color& c) {
	if (c.format == true) {
		if (c.isRGB == true) {
			out << "Color RGB : (" << c.channelX << "," << c.channelY << "," << c.channelZ << ")" << endl;
			return out;
		}
		if (c.isRGB == false) {
			out << "Color HSV : (" << c.channelX << "," << c.channelY << "," << c.channelZ << ")" << endl;
			return out;
		}
	}
	if (c.format == true) {
		if (c.isRGB == true) {
			out << "Color RGB : (" << c.channelX*255 << "," << c.channelY*255 << "," << c.channelZ*255 << ")" << endl;
			return out;
		}
		if (c.isRGB == false) {
			out << "Color HSV : (" << c.channelX << "," << c.channelY*100 << "%," << c.channelZ*100 << "%)" << endl;
			return out;
		}
	}
}
