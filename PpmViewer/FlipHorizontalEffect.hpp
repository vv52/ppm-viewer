#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class FlipHorizontalEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		Pixel temp;
		Pixel temp2;

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < (doc.getWidth() / 2); j++)
			{
				int widthTemp = doc.getWidth() - 1 - j;
				temp = doc[i][j];
				temp2 = doc[i][widthTemp];
				doc[i][j] = temp2;
				doc[i][widthTemp] = temp;
			}
		}
	}
};