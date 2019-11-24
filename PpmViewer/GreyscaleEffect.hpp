#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class GreyscaleEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int rgbAvg = (p.red + p.green + p.blue) / 3;
				p.red = rgbAvg;
				p.green = rgbAvg;
				p.blue = rgbAvg;

				doc[i][j] = p;
			}
		}
	}
};

/*
for (int i = 0; i < project.getPixelCount(); i++)
	{
		int currentRed = editedPixelData[i].getRed();
		int currentGreen = editedPixelData[i].getGreen();
		int currentBlue = editedPixelData[i].getBlue();

		int rgbAverage = (currentRed + currentGreen + currentBlue) / 3;
		editedPixelData[i].setRGB(rgbAverage, rgbAverage, rgbAverage);
	}*/