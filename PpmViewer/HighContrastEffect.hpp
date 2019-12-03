#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];

				int tempRed = p.getRed();
				if (tempRed > 127) {
					tempRed = 255;
				}
				else {
					tempRed = 0;
				}

				int tempGreen = p.getGreen();
				if (tempGreen > 127) {
					tempGreen = 255;
				}
				else {
					tempGreen = 0;
				}

				int tempBlue = p.getBlue();
				if (tempBlue > 127) {
					tempBlue = 255;
				}
				else {
					tempBlue = 0;
				}
				
				p.setRed(tempRed);
				p.setGreen(tempGreen);
				p.setBlue(tempBlue);
				doc[i][j] = p;
			}
		}
	}
};