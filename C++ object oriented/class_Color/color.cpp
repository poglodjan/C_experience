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

Color Color::toRGB() {
	if (isRGB == false) {
		float c = channelY * channelZ;
		float x = c * (1.0f - abs((int)(channelX / 60) % 2 - 1));
		float m = channelZ - c;
		float r, g, b;
		if (channelY < 60) {
			r = c;
			g = x;
			b = 0;
		}
		else if (channelY < 120) {
			r = x;
			g = c;
			b = 0;
		}
		else if (channelY < 180) {
			r = 0;
			g = c;
			b = x;
		}
		else if (channelY < 240) {
			r = 0;
			g = x;
			b = c;
		}
		else if (channelY < 300) {
			r = x;
			g = 0;
			b = c;
		}
		else {
			r = c;
			g = 0;
			b = x;
		}
		return Color(r + m, g + m, b + m);
	}
	else return Color(channelX, channelY, channelZ);
}

Color Color::toHSV() {
	if (isRGB == true) {
		float cmax = max(max(channelX, channelY), channelZ);
		float cmin = min(min(channelX, channelY), channelZ);
		float delta = cmax - cmin;
		float hue = 0;
		if (delta != 0) {
			if (cmax == channelX)
				hue = 60 * (int((channelY - channelZ) / delta) % 6);
			else if (cmax == channelY)
				hue = 60 * (((channelZ - channelX) / delta) + 2);
			else if (cmax == channelZ)
				hue = 60 * (((channelX - channelY) / delta) + 4);
			if (hue < 0)
				hue += 360;
		}
		float saturation = cmax == 0 ? 0 : delta / cmax;
		float value = cmax;
		return Color(hue, saturation, value);
	}
	else return Color(channelX, channelY, channelZ);
}

Color Color::addColor(Color& c) {
	if (this->isRGB) {
		Color colorOther = c.toRGB();
		this->channelX += colorOther.channelX;
		this->channelY += colorOther.channelY;
		this->channelZ += colorOther.channelZ;
		return *this;
	}
	else {
		Color colorOther = c.toHSV();
		this->channelX += colorOther.channelX;
		this->channelY += colorOther.channelY;
		this->channelZ += colorOther.channelZ;
		return *this;
	}
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
