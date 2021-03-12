#include "NumberGrid.h"
#include "PPM.h"
#include <iostream>
#include <string>
#include <vector>


NumberGrid::NumberGrid()
{

	mWidth = 300;
	mHeight = 200;
	mMaxNumber = 255;

	mData.resize(mWidth * mHeight);
}

NumberGrid::NumberGrid(const int &height, const int &width)
{
	mWidth = width;
	mHeight = height;
	mMaxNumber = 255;

	mData.resize(mWidth * mHeight);
	
}

int NumberGrid::getHeight() const
{
	return mHeight;
}

int NumberGrid::getWidth() const
{
	return mWidth;
}

int NumberGrid::getMaxNumber() const
{
	return mMaxNumber;
}

void NumberGrid::setGridSize(const int &height, const int &width)
{
	if (height >= 2 && width >= 2)
	{
		mHeight = height;
		mWidth = width;
		mData.resize(mHeight * mWidth);
	}
}


void NumberGrid::calculateAllNumbers( ){

	int i, num, k;

	for(i = 0; i < mHeight; i++)
	{
		for (k = 0; k < mWidth; k++)
		{
			num = calculateNumber(i,k);
			setNumber(i,k,num);
		}

	}


}

void NumberGrid::setMaxNumber(const int &number)
{
	if (number >= 0)
	{
		mMaxNumber = number;
	}
}

const std::vector<int> &NumberGrid::getNumbers() const
{

	return mData;
}

int NumberGrid::index(const int &row, const int &column) const
{

	int indx = row * mWidth + column;

	return indx;
}

bool NumberGrid::indexValid(const int &row, const int &column) const
{

	if (row >= 0 && row < mHeight && column >= 0 && column < mWidth)
	{
		return true;
	}
	return false;
}

bool NumberGrid::numberValid(const int &number) const
{

	if (number >= 0 && number <= mMaxNumber)
	{
		return true;
	}
	return false;
}

int NumberGrid::getNumber(const int &row, const int &column) const
{  	
	if (indexValid(row, column))
	{
		int indx;
		indx = this->index(row, column);
		
		return mData[indx];
	}

	return -1;
}

void NumberGrid::setNumber(const int &row, const int &column, const int &number)
{
	if(numberValid(number) && indexValid(row,column))
	{
		int i;
		i = index(row, column);
		mData[i] = number;	
	}
}

void NumberGrid::setPPM(PPM &ppm) const
{
	int row, column;
	ppm.setMaxColorValue(63);
	ppm.setHeight(mHeight);
	ppm.setWidth(mWidth);


	for (row = 0; row < mHeight; row++)
	{
		for (column = 0; column < mWidth; column++)
		{
			int ind;
			int num;
			ind = index(row,column);
			num = mData[ind];

			if (num == 0 )
			{
				ppm.setPixel(row, column, 0, 0, 0);
			}
			else if (num == mMaxNumber)
			{
				ppm.setPixel(row, column, 63, 31, 31);
			}
			else if (num % 8 == 0)
			{
				ppm.setPixel(row, column, 63, 63, 63);
			}
			else if (num % 8 == 1)
			{
				ppm.setPixel(row, column, 63, 31, 31);
			}
			else if (num % 8 == 2)
			{			
				ppm.setPixel(row, column, 63, 63, 31);
			}
			else if (num % 8 == 3)
			{
				ppm.setPixel(row, column, 31, 63, 31);
			}
			else if (num % 8 == 4)
			{
				ppm.setPixel(row, column, 0, 0, 0);
			}
			else if (num % 8 == 5)
			{
				ppm.setPixel(row, column, 31, 63, 63);
			}
			else if (num % 8 == 6)
			{
				ppm.setPixel(row, column, 31, 31, 63);
			}
			else if (num % 8 == 7)
			{
				ppm.setPixel(row, column, 63, 31, 63);
			}
		}
	}
}

NumberGrid::~NumberGrid(){}

void NumberGrid::setPPM ( PPM& ppm, const ColorTable& colors) const {

	if(colors.getNumberOfColors()>=3){

		ppm.setHeight(mHeight);
		ppm.setWidth(mWidth);
		int maxColor = colors.getMaxChannelValue();
		ppm.setMaxColorValue(maxColor);

		int i,j;
		for(i=0; i<mHeight; i++){
			for(j=0; j<mWidth; j++){

				int gridNumber = index(i,j);

				if(mData[gridNumber] == mMaxNumber){

					ppm.setPixel(i,j,colors[colors.getNumberOfColors()-1].getRed(),colors[colors.getNumberOfColors()-1].getGreen(),colors[colors.getNumberOfColors()-1].getBlue());
				
				}else if(mData[gridNumber] == 0){
					
					ppm.setPixel(i,j,colors[colors.getNumberOfColors()-2].getRed(),colors[colors.getNumberOfColors()-2].getGreen(),colors[colors.getNumberOfColors()-2].getBlue());

				}else{

					int k = mData[gridNumber] % (colors.getNumberOfColors()-2);
					
					ppm.setPixel(i,j,colors[k].getRed(),colors[k].getGreen(),colors[k].getBlue());
				}

			}

		}
	}

}

