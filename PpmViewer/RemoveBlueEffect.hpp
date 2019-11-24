#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RemoveBlueEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				p.blue = 0;

				doc[i][j] = p;
			}
		}
	}
};