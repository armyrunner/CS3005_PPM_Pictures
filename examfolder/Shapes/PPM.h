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

    // added the following to functions to the file on 9/18/2019
    void grayFromChannel(PPM& dst, const int& src_channel) const;
    void grayFromRed(PPM& dst) const;
    void grayFromGreen(PPM& dst) const;
    void grayFromBlue(PPM& dst) const;
    double linearColorimetricPixelValue(const int& row, const int& column) const;
    void grayFromLinearColorimetric(PPM& dst) const;
    
    // added the following to function to the file on 9/25/2019
    bool operator==(const PPM& rhs ) const;
    bool operator!=(const PPM& rhs ) const;
    bool operator<(const PPM& rhs ) const;
    bool operator<=(const PPM& rhs) const;
    bool operator>(const PPM& rhs ) const;
    bool operator>=(const PPM& rhs) const;
	
	PPM& operator+=(const PPM& rhs);
	PPM& operator-=(const PPM& rhs);
	PPM& operator*=(const double& rhs);
	PPM& operator/=(const double& rhs);

    PPM operator+( const PPM& rhs ) const;
    PPM operator-( const PPM& rhs ) const;
    PPM operator*( const double& rhs ) const;
    PPM operator/( const double& rhs ) const;
	
    // added new funcitons on 9/30/19
	int edgePixelValue( const int& row1, const int& column1, const int& row2, const int& column2 ) const;
	void findVerticalEdges( PPM& dst ) const;
	void findHorizontalEdges( PPM& dst ) const;
   
//    // exam practice
//    double linearColorimetricPixelSephia(const int& row, const int &column) const;
        

private:

    int mWidth;
    int mHeight;
    int mMaxColorValue;

    std::vector<double> mData;


};

std::ostream& operator<<( std::ostream& os, const PPM& rhs );
std::istream& operator>>(std::istream& is, PPM& rhs);


#endif /*_PPM_H_*/
