#include "PPM.h"
#include <iostream>
#include <string>
#include <vector>

PPM::PPM()
{

    mWidth = 0;
    mHeight = 0;
    mMaxColorValue = 0;

    mData.resize(mWidth * mHeight * 3);
}

PPM::PPM(const int &height, const int &width)
{

    mWidth = width;
    mHeight = height;
    mMaxColorValue = 0;

    mData.resize(mWidth * mHeight * 3);
}

// Getting and returning values
int PPM::getHeight() const
{
    return mHeight;
}

int PPM::getWidth() const
{
    return mWidth;
}

int PPM::getMaxColorValue() const
{
    return mMaxColorValue;
}

int PPM::getChannel(const int &row, const int &column, const int &channel) const
{

    if (row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3)
    {
        return mData[(row * mWidth * 3) + (column * 3) + channel];
    }
    else
    {
        return -1;
    }
}

// validate the user input

bool PPM::indexValid(const int &row, const int &column, const int &channel) const
{

    if (row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int PPM::index(const int &row, const int &column, const int &channel) const
{

    return (row * mWidth * 3) + (column * 3) + channel;
}

// validate the user input

bool PPM::valueValid(const int &value) const
{

    if (value >= 0 && value <= mMaxColorValue)
    {

        return true;
    }
    else
    {

        return false;
    }
}

// set the height on the ppm and resize the array

void PPM::setHeight(const int &height)
{

    if (height >= 0)
    {

        mHeight = height;

        mData.resize(mWidth * mHeight * 3);
    }
}

// set the width and resize the array

void PPM::setWidth(const int &width)
{

    if (width >= 0)
    {

        mWidth = width;

        mData.resize(mWidth * mHeight * 3);
    }
}

//set max color value somewhere between 2 to 255

void PPM::setMaxColorValue(const int &max_color_value)
{

    if (max_color_value >= 0 && max_color_value <= 255)
    {

        mMaxColorValue = max_color_value;
    }
}

void PPM::setChannel(const int &row, const int &column, const int &channel, const int &Value)
{

    if (indexValid(row, column, channel) && valueValid(Value))
    {
        mData[(row * mWidth * 3) + (column * 3) + channel] = Value;
    }
}

void PPM::setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue)
{

    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}

std::ostream &operator<<(std::ostream &os, const PPM &rhs)
{
    int row, column, channel;
    os << "P6 " << rhs.getWidth() << " " << rhs.getHeight() << " " << rhs.getMaxColorValue() << "\n";
    for (row = 0; row < rhs.getHeight(); row++)
    {
        for (column = 0; column < rhs.getWidth(); column++)
        {
            for (channel = 0; channel < 3; channel++)
            {
                int v;
                v = rhs.getChannel(row, column, channel);
                unsigned char c = v;
                os.write((char *)&c, 1);
            }
        }
    }

    return os;
}
// add new functions onf 9/18/2019

void PPM::grayFromChannel(PPM &dst, const int &src_channel) const
{

    int h = this->getHeight();
    dst.setHeight(h);

    int w = this->getWidth();
    dst.setWidth(w);

    int mcv = this->getMaxColorValue();
    dst.setMaxColorValue(mcv);

    for (int row = 0; row < h; row++)
    {
        for (int column = 0; column < w; column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {

                int gh = this->getChannel(row, column, src_channel);
                dst.setChannel(row, column, channel, gh);
            }
        }
    }
}

void PPM::grayFromRed(PPM &dst) const
{

    grayFromChannel(dst, 0);
}

void PPM::grayFromGreen(PPM &dst) const
{

    grayFromChannel(dst, 1);
}

void PPM::grayFromBlue(PPM &dst) const
{

    grayFromChannel(dst, 2);
}

double PPM::linearColorimetricPixelValue(const int &row, const int &column) const
{
    int r = this->getChannel(row, column, 0);
    int g = this->getChannel(row, column, 1);
    int b = this->getChannel(row, column, 2);

    double brightness = .2126 * r + .7152 * g + .0722 * b;

    return brightness;
}


void PPM::grayFromLinearColorimetric(PPM &dst) const
{

    int h = this->getHeight();
    dst.setHeight(h);

    int w = this->getWidth();
    dst.setWidth(w);

    int mcv = this->getMaxColorValue();
    dst.setMaxColorValue(mcv);

    for (int row = 0; row < h; row++)
    {
        for (int column = 0; column < w; column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {

                double linearColor = this->linearColorimetricPixelValue(row, column);
                dst.setChannel(row, column, channel, linearColor);
            }
        }
    }
}

std::istream &operator>>(std::istream &is, PPM &rhs)
{
    std::string a;
    int width, height, mcv;

    unsigned char c, t;

    is >> a >> width >> height >> mcv;
    is.read((char *)&c, 1);

    rhs.setWidth(width);
    rhs.setHeight(height);
    rhs.setMaxColorValue(mcv);

    for (int row = 0; row < height; row++)
    {

        for (int column = 0; column < width; column++)
        {

            for (int channel = 0; channel < 3; channel++)
            {

                is.read((char *)&t, 1);
                rhs.setChannel(row, column, channel, t);
            }
        }
    }

    return is;
}

bool PPM::operator==(const PPM &rhs) const
{
    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 == pix2)
    {
        return true;
    }
    return false;
}

bool PPM::operator!=(const PPM &rhs) const
{
    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 != pix2)
    {
        return true;
    }
    return false;
}
bool PPM::operator<(const PPM &rhs) const
{
    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 < pix2)
    {
        return true;
    }
    return false;
}
bool PPM::operator<=(const PPM &rhs) const
{
    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 <= pix2)
    {
        return true;
    }
    return false;
}
bool PPM::operator>(const PPM &rhs) const
{

    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 > pix2)
    {
        return true;
    }
    return false;
}
bool PPM::operator>=(const PPM &rhs) const
{
    int pix1, pix2;
    pix1 = mHeight * mWidth;
    pix2 = rhs.getHeight() * rhs.getWidth();

    if (pix1 >= pix2)
    {
        return true;
    }
    return false;
}

PPM &PPM::operator+=(const PPM &rhs)
{
    int h, w, row, column, channel, Cchannel, Rchannel;
    int total, mcv;

    h = (*this).getHeight();
    w = (*this).getWidth();
    mcv = (*this).getMaxColorValue();

    for (row = 0; row < h; row++)
    {
        for (column = 0; column < w; column++)
        {
            for (channel = 0; channel < 3; channel++)
            {

                Cchannel = (*this).getChannel(row, column, channel);
                Rchannel = rhs.getChannel(row, column, channel);
                total = Cchannel + Rchannel;

                if (total > mcv)
                {
                    (*this).setChannel(row, column, channel, mcv);
                }
                else
                {
                    (*this).setChannel(row, column, channel, total);
                }
            }
        }
    }

    return (*this);
}

PPM &PPM::operator-=(const PPM &rhs)
{
    int h, w, row, column, channel, Cchannel, Rchannel;
    int total;

    h = (*this).getHeight();
    w = (*this).getWidth();

    for (row = 0; row < h; row++)
    {
        for (column = 0; column < w; column++)
        {
            for (channel = 0; channel < 3; channel++)
            {

                Cchannel = (*this).getChannel(row, column, channel);
                Rchannel = rhs.getChannel(row, column, channel);
                total = Cchannel - Rchannel;

                if (total < 0)
                {
                    (*this).setChannel(row, column, channel, 0);
                }
                else
                {
                    (*this).setChannel(row, column, channel, total);
                }
            }
        }
    }

    return (*this);
}

PPM &PPM::operator*=(const double &rhs)
{

    int h, w, row, column, channel, Cchannel;
    int total, mcv;

    h = (*this).getHeight();
    w = (*this).getWidth();
    mcv = (*this).getMaxColorValue();

    for (row = 0; row < h; row++)
    {
        for (column = 0; column < w; column++)
        {
            for (channel = 0; channel < 3; channel++)
            {

                Cchannel = (*this).getChannel(row, column, channel);
                total = Cchannel * rhs;

                if (total < 0)
                {
                    (*this).setChannel(row, column, channel, 0);
                }
                if (total > mcv)
                {
                    (*this).setChannel(row, column, channel, mcv);
                }
                else
                {
                    (*this).setChannel(row, column, channel, total);
                }
            }
        }
    }

    return (*this);
}

PPM &PPM::operator/=(const double &rhs)
{

    int h, w, row, column, channel, Cchannel;
    int total, mcv;

    h = (*this).getHeight();
    w = (*this).getWidth();
    mcv = (*this).getMaxColorValue();

    for (row = 0; row < h; row++)
    {
        for (column = 0; column < w; column++)
        {
            for (channel = 0; channel < 3; channel++)
            {

                Cchannel = (*this).getChannel(row, column, channel);
                total = Cchannel / rhs;

                if (total < 0)
                {
                    (*this).setChannel(row, column, channel, 0);
                }
                if (total > mcv)
                {
                    (*this).setChannel(row, column, channel, mcv);
                }
                else
                {
                    (*this).setChannel(row, column, channel, total);
                }
            }
        }
    }

    return (*this);
}

PPM PPM::operator+(const PPM &rhs) const
{
    PPM newobject = (*this);
    newobject.operator+=(rhs);
    return newobject;
}

PPM PPM::operator-(const PPM &rhs) const
{
    PPM newobject = (*this);
    newobject.operator-=(rhs);
    return newobject;
}

PPM PPM::operator*(const double &rhs) const
{
    PPM newobject = (*this);
    newobject.operator*=(rhs);
    return newobject;
}

PPM PPM::operator/(const double &rhs) const
{
    PPM newobject = (*this);
    newobject.operator/=(rhs);
    return newobject;
}

int PPM::edgePixelValue( const int& row1, const int& column1, const int& row2, const int& column2 ) const
{
    double linearColor1, linearColor2, total;

    linearColor1 = linearColorimetricPixelValue(row1,column1);
    linearColor2 = linearColorimetricPixelValue(row2,column2);

    double mcv = getMaxColorValue();

    total = abs((linearColor2 - linearColor1));

    if (total >= (mcv * .10)){

        return mcv;

    }

    return 0;
}

void PPM::findVerticalEdges( PPM& dst ) const
{
    int row,col;
    

    int w = this->getWidth();
    dst.setWidth(w);

    int h = this->getHeight();
    dst.setHeight(h);

	int mcv = this->getMaxColorValue();
	dst.setMaxColorValue(mcv);	

    for (row = 0; row < h; row++ )
    {
        for (col = 0; col < w; col++)
        {
             if(col == 0)
			 {
			   dst.setPixel(row,col,0,0,0);
			 
			 } else
			 {

				dst.setChannel(row,col,0,this->edgePixelValue(row,col,row,col-1));
				dst.setChannel(row,col,1,this->edgePixelValue(row,col,row,col-1));
				dst.setChannel(row,col,2,this->edgePixelValue(row,col,row,col-1));
			 }
				
        }
           
    }
        
}

void PPM::findHorizontalEdges( PPM& dst ) const
{
    int row,col;
    

    int w = this->getWidth();
    dst.setWidth(w);

    int h = this->getHeight();
    dst.setHeight(h);

	int mcv = this->getMaxColorValue();
	dst.setMaxColorValue(mcv);
    
	for (row = 0; row < h; row++ )
    {
        for (col = 0; col < w; col++)
        {

             if(row == 0)
			 {
			   dst.setPixel(row,col,0,0,0);
			 
			 } else
			 {

					dst.setChannel(row,col,0,this->edgePixelValue(row,col,row-1,col));
					dst.setChannel(row,col,1,this->edgePixelValue(row,col,row-1,col));
					dst.setChannel(row,col,2,this->edgePixelValue(row,col,row-1,col));
			 }
        }
           
    }
        
}

void PPM::crop(PPM& dst,const int& left, const int& right, const int& top, const int& bottom) const{

    dst.setHeight(bottom - top +1);
    dst.setWidth(right - left + 1);
    dst.setMaxColorValue(mMaxColorValue);

    int row,column,channel;

    for(row=0;row<mHeight;row++){
        for(column = 0;column < mWidth;column++){
            for(channel = 0; channel<3;channel++){
                int v = getChannel(row+top,column+left,channel);
                dst.setChannel(row,column,channel,v);
            }
        }
    }
}





