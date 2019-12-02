#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RotateNinetyEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		PpmDocument rotated{ doc.getImageFormat(), doc.getHeight(), doc.getWidth(),
			doc.getColorDepth() };
		int iCount = 0;
		int width = doc.getWidth() - 1;
		int height = doc.getHeight();

		for (int i = width; i >= 0; i--)
		{
			for (int j = 0; j < height; j++)
			{
				rotated[iCount][j] = doc[j][i];
			}
			iCount++;
		}

		doc.setDuplicate(rotated);
	}
};


/*


for (int m = project.getWidth() - 1; m >= 0; m--)
{
	for (int l = 0; l < project.getHeight(); l++)
	{
		dataYX_rotated[x][l] = dataYX[l][m];
	}
	x++;
}*/