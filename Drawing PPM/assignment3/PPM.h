#ifndef _PPM_H_
#define _PPM_H_

#include <iostream>
#include <string>
#include <vector>


class PPM{

public:
    PPM();
    PPM( const int& height, const int& width);

    int getHeight() const;
    int getWidth() const;
    int getMaxColorValue() const;

    int getChannel( const int& row, const int& column, const int& channel) const;
    bool indexValid(const int& row, const int& column, const int& channel) const;
    int index(const int& row, const int& column, const int& channel) const;

    bool valueValid(const int& value) const;
    void setHeight(const int& height);
    void setWidth(const int& width);
    
    void setMaxColorValue(const int& max_color_value);
    void setChannel(const int& row, const int& column, const int& channel, const int& Value);
    void setPixel(const int& row, const int& column, const int& red, const int& green, const int& blue);


private:

    int mWidth;
    int mHeight;
    int mMaxColorValue;

    std::vector<double> mData;


};

std::ostream& operator<<( std::ostream& os, const PPM& rhs );


#endif