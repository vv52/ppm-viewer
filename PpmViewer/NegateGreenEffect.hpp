#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class NegateGreenEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int greenTemp = p.green;
				p.green = (255 - greenTemp);

				doc[i][j] = p;
			}
		}
	}
};