#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class BlurImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		PpmDocument blurred{ doc.getImageFormat(), doc.getWidth(), doc.getHeight(),
			doc.getColorDepth() };
		int imgH = doc.getHeight() - 1;
		int imgW = doc.getWidth() - 1;
		int tempRed = 0;
		int tempGreen = 0;
		int tempBlue = 0;

		for (int irow = 0; irow < imgH; irow++)
		{
			for (int icol = 0; icol < imgW; icol++)
			{
				if (irow == 0 && icol == 0)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow + 1][icol].getRed()
						+ doc[irow][icol + 1].getRed()) / 3;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow + 1][icol].getGreen()
						+ doc[irow][icol + 1].getGreen()) / 3;
					tempBlue - (doc[irow][icol].getBlue() + doc[irow + 1][icol].getBlue()
						+ doc[irow][icol + 1].getBlue()) / 3;
				}
				else if (irow == 0 && icol != 0 && icol != imgW)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow + 1][icol].getRed()
						+ doc[irow][icol - 1].getRed() + doc[irow][icol].getRed()) / 4;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow + 1][icol].getGreen()
						+ doc[irow][icol - 1].getGreen() + doc[irow][icol + 1].getGreen()) / 4;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow + 1][icol].getBlue()
						+ doc[irow][icol - 1].getBlue() + doc[irow][icol + 1].getBlue()) / 4;
				}
				else if (icol == 0 && irow != 0 && irow != imgH)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow][icol + 1].getRed()
						+ doc[irow - 1][icol].getRed() + doc[irow + 1][icol].getRed()) / 4;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow][icol + 1].getGreen()
						+ doc[irow - 1][icol].getGreen() + doc[irow + 1][icol].getGreen()) / 4;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow][icol + 1].getBlue()
						+ doc[irow - 1][icol].getBlue() + doc[irow + 1][icol].getBlue()) / 4;
				}
				else if (irow == 0 && icol == imgW)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow + 1][icol].getRed()
						+ doc[irow][icol - 1].getRed()) / 3;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow + 1][icol].getGreen()
						+ doc[irow][icol - 1].getGreen()) / 3;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow + 1][icol].getBlue()
						+ doc[irow][icol - 1].getBlue()) / 3;
				}
				else if (icol == 0 && irow == imgH)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow - 1][icol].getRed()
						+ doc[irow][icol + 1].getRed()) / 3;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow - 1][icol].getGreen()
						+ doc[irow][icol + 1].getGreen()) / 3;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow - 1][icol].getBlue()
						+ doc[irow][icol + 1].getBlue()) / 3;
				}
				else if (icol == imgH && irow == imgW)
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow - 1][icol].getRed()
						+ doc[irow][icol - 1].getRed()) / 3;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow - 1][icol].getGreen()
						+ doc[irow][icol - 1].getGreen()) / 3;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow - 1][icol].getBlue()
						+ doc[irow][icol - 1].getBlue()) / 3;
				}
				else if ((irow == imgH) && (icol != 0) && (icol != imgW))
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow - 1][icol].getRed()
						+ doc[irow][icol + 1].getRed() + doc[irow][icol - 1].getRed()) / 4;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow - 1][icol].getGreen()
						+ doc[irow][icol + 1].getGreen() + doc[irow][icol - 1].getGreen()) / 4;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow - 1][icol].getBlue()
						+ doc[irow][icol + 1].getBlue() + doc[irow][icol - 1].getBlue()) / 4;
				}
				else if ((icol == imgW) && (irow != 0) && (irow != imgH))
				{
					tempRed = (doc[irow][icol].getRed() + doc[irow][icol - 1].getRed()
						+ doc[irow + 1][icol].getRed() + doc[irow - 1][icol].getRed()) / 4;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow][icol - 1].getGreen()
						+ doc[irow + 1][icol].getGreen() + doc[irow - 1][icol].getGreen()) / 4;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow][icol - 1].getBlue()
						+ doc[irow + 1][icol].getBlue() + doc[irow][icol - 1].getBlue()) / 4;
				}
				else {
					tempRed = (doc[irow][icol].getRed() + doc[irow - 1][icol].getRed()
						+ doc[irow][icol - 1].getRed() + doc[irow + 1][icol].getRed()
						+ doc[irow][icol + 1].getRed()) / 5;
					tempGreen = (doc[irow][icol].getGreen() + doc[irow - 1][icol].getGreen()
						+ doc[irow][icol - 1].getGreen() + doc[irow + 1][icol].getGreen()
						+ doc[irow][icol + 1].getGreen()) / 5;
					tempBlue = (doc[irow][icol].getBlue() + doc[irow - 1][icol].getBlue()
						+ doc[irow][icol - 1].getBlue() + doc[irow + 1][icol].getBlue()
						+ doc[irow][icol + 1].getBlue()) / 5;
				}

				blurred[irow][icol].setRed(tempRed);
				blurred[irow][icol].setGreen(tempGreen);
				blurred[irow][icol].setBlue(tempBlue);
			}
		}

		doc.setDuplicate(blurred);
	}
};