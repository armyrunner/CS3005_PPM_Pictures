#include "PPM.h"
#include <iostream>
#include <string>
#include <vector>

PPM::PPM(){

mWidth = 0;
mHeight = 0;
mMaxColorValue = 0;

mData.resize(mWidth * mHeight * 3);

}

PPM::PPM( const int& height, const int& width){

mWidth = width;
mHeight = height;   
mMaxColorValue = 0;

mData.resize(mWidth * mHeight * 3);
}


// Getting and returning values
int PPM::getHeight() const{
    return mHeight;
}

int PPM::getWidth() const{
    return mWidth;
}

int PPM::getMaxColorValue() const{
    return mMaxColorValue;
}


int PPM::getChannel( const int& row, const int& column, const int& channel) const{

    if (row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3){
         return mData[(row * mWidth *3) + (column * 3) + channel];
    } else { return -1;}

}


// validate the user input

bool PPM::indexValid(const int& row, const int& column, const int& channel) const{

    if(row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3){
        return true;

    } else{
     return false;
    }
}

int PPM::index(const int& row, const int& column, const int& channel) const{

    return (row * mWidth * 3) + (column * 3) + channel;
}


// validate the user input


bool PPM::valueValid(const int& value) const{

    if( value >=  0 &&  value <= mMaxColorValue) {

        return true;
    } else {

        return false;
    }

}

// set the height on the ppm and resize the array

void PPM::setHeight(const int& height){

    if( height >= 0 ){

        mHeight = height;

        mData.resize(mWidth * mHeight * 3);
        
    } 

}

// set the width and resize the array

void PPM::setWidth(const int& width){

     if( width >= 0){

        mWidth = width;

        mData.resize(mWidth * mHeight * 3);
    } 

}

//set max color value somewhere between 2 to 255

void PPM::setMaxColorValue(const int& max_color_value){

     if( max_color_value >= 0 && max_color_value <= 255 ){

        mMaxColorValue = max_color_value;
    } 

}

void PPM::setChannel(const int& row, const int& column, const int& channel, const int& Value){
    
    if (indexValid(row,column,channel) && valueValid(Value)){
        mData[(row * mWidth *3) + (column * 3) + channel] = Value;
    }

}

void PPM::setPixel(const int& row, const int& column, const int& red, const int& green, const int& blue){

        setChannel(row,column,0,red);
        setChannel(row,column,1,green);
        setChannel(row,column,2,blue);

}

std::ostream& operator<<( std::ostream& os, const PPM& rhs ){
    int row, column, channel;
    os << "P6 " << rhs.getWidth() << " " << rhs.getHeight() << " " << rhs.getMaxColorValue() << "\n";
    for(row = 0; row < rhs.getHeight(); row++){
        for(column = 0; column < rhs.getWidth(); column++ ){
            for(channel = 0; channel < 3; channel++){
                int v;
                v = rhs.getChannel( row, column, channel);
                unsigned char c = v;
                os.write((char*)&c, 1);
            }
        }
    }

    return os;

}
