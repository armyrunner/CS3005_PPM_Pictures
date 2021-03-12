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

    int newvalue;
    if (row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3){
        newvalue = mData[(row * mWidth *3) + (column * 3) + channel];
    } else {

        return -1;
    }
    
    return newvalue;

}


bool PPM::indexValid(const int& row, const int& column, const int& channel) const{

    if(row >= 0 && row < mHeight && column >= 0 && column < mWidth && channel >= 0 && channel < 3){
        return true;

    } else{

        
     return false;

    }
    

}

int PPM::index(const int& row, const int& column, const int& channel) const{

    return (row * mWidth *3) + (column * 3) + channel;

}

bool PPM::valueValid(const int& value) const{

    if( value >=  0 &&  value <= mMaxColorValue) {

        return true;
    } else {

        return false;

    }
    

}

void PPM::setHeight(const int& height){

    if( height >= 0){

        mHeight = height;

        mData.resize(mWidth * mHeight * 3);
        
    } 

}

void PPM::setWidth(const int& width){

     if( width >= 0){

        mWidth = width;

        mData.resize(mWidth * mHeight * 3);
    } 

}

void PPM::setMaxColorValue(const int& max_color_value){

     if( max_color_value >= 0 && max_color_value <= 255 ){

        mMaxColorValue = max_color_value;
    } 

}

void PPM::setChannel(const int& row, const int& column, const int& channel, const int& Value){

    
    if (indexValid(row,column,channel)){
        mData[(row * mWidth *3) + (column * 3) + channel] = Value;
    }

}

void PPM::setPixel(const int& row, const int& column, const int& red, const int& blue, const int& green){

        setChannel(row,column,0,red);
        setChannel(row,column,1,green);
        setChannel(row,column,2,blue);

}
/*
std::ostream& operator<<( std::ostream& os, const PPM& rhs ){
    int i;
    PPM myppm = rhs
    // us for loop to loop through all values in the array 
    for(i = 0; rhs->getWidth();i++){
        for(j){
            for(k)
        }
    }

    unsigned char x = getChannel();
    os.write( &x, sizeof(x));

}*/