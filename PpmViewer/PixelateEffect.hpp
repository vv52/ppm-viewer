#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class PixelateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int pixelDiv = 3;

		while (doc.getHeight() % pixelDiv != 0)
		{
			pixelDiv++;
		}

		for (int i = 0; i < doc.getHeight(); i += pixelDiv)
		{
			for (int j = 0; j < doc.getWidth(); j += pixelDiv)
			{
				for (int k = 0; k < pixelDiv; k++)
				{
					for (int l = 0; l < pixelDiv; l++)
					{
						if ((i + k) > doc.getHeight() || (j + l) > doc.getWidth())
						{
							break;
						}
						else {
							doc[i + k][j + l].setRed(doc[i][j].getRed());
							doc[i + k][j + l].setGreen(doc[i][j].getGreen());
							doc[i + k][j + l].setBlue(doc[i][j].getBlue());
						}
					}
				}
			}
		}
	}
};
