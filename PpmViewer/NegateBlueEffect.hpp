#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class NegateBlueEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int blueTemp = p.getBlue();
				p.setBlue(255 - blueTemp);

				doc[i][j] = p;
			}
		}
	}
};