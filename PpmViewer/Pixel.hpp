#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
private:
	int _red = -1;
	int _green = -1;
	int _blue = -1;
public:

	Pixel()
	{
	}

	Pixel(int setRed, int setGreen, int setBlue)
	{
		_red = setRed;
		_green = setGreen;
		_blue = setBlue;
	}

	/*Pixel(Pixel& p)
	{
		_red = p.getRed();
		_green = p.getGreen();
		_blue = p.getBlue();
	}*/
	
	int getRed()
	{
		return _red;
	}

	int getGreen()
	{
		return _green;
	}

	int getBlue()
	{
		return _blue;
	}

	void setRed(int newRed)
	{
		_red = newRed;
	}

	void setGreen(int newGreen)
	{
		_green = newGreen;
	}

	void setBlue(int newBlue)
	{
		_blue = newBlue;
	}

	friend istream& operator>>(istream& stream, Pixel& pixel);
	friend ostream& operator<<(ostream& stream, const Pixel& pixel);
};

istream& operator>>(istream& stream, Pixel& pixel)
{
	stream >> pixel._red >> pixel._green >> pixel._blue;
	return stream;
}

ostream& operator<<(ostream& stream, const Pixel& pixel)
{
	stream << pixel._red << " " << pixel._green << " " << pixel._blue;
	return stream;
}

#endif // !PIXEL_H
