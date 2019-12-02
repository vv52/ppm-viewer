#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class FlipVerticalEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		Pixel temp;
		Pixel temp2;

		for (int i = 0; i < doc.getWidth(); i++)
		{
			for (int j = 0; j < (doc.getHeight() / 2); j++)
			{
				int heightTemp = doc.getHeight() - 1 - j;
				temp = doc[j][i];
				temp2 = doc[heightTemp][i];
				doc[j][i] = temp2;
				doc[heightTemp][i] = temp;
			}
		}
	}
};