#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class AddNoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int noiseValue = 0;

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				noiseValue = ((rand() % 21) - 10);
				Pixel& p = doc[i][j];
				
				int redTemp = p.red;
				redTemp += noiseValue;
				if (redTemp < 0) {
					redTemp = 0;
				}
				else if (redTemp > 255) {
					redTemp = 255;
				}
				p.red = redTemp;

				int greenTemp = p.green;
				greenTemp += noiseValue;
				if (greenTemp < 0) {
					greenTemp = 0;
				}
				else if (greenTemp > 255) {
					greenTemp = 255;
				}
				p.green = greenTemp;

				int blueTemp = p.blue;
				blueTemp += noiseValue;
				if (blueTemp < 0) {
					blueTemp = 0;
				}
				else if (blueTemp > 255) {
					blueTemp = 255;
				}
				p.blue = blueTemp;

				doc[i][j] = p;
			}
		}
	}
};