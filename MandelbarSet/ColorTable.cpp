
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ColorTable.h"
#include "math.h"
#include <cstdlib>


Color::Color(){
    
    mRed = 0;
    mGreen = 0;
    mBlue = 0;

}

Color::Color(const int& red,const int& green,const int& blue){

    mRed = red;
    mGreen = green;
    mBlue = blue;

}

int Color::getRed() const{

    return mRed;

}

int Color::getGreen() const{

    return mGreen;

}

int Color::getBlue() const{

    return mBlue;

}

int Color::getChannel(const int& channel) const{

    if (channel == 0){
        return getRed();
    }else if(channel == 1){
        return getGreen();
    }else if (channel == 2){
        return getBlue();
    }else{
        return -1;
    }

}

void Color::setRed(const int& value){

    if(value >= 0 ){
        
        mRed = value;
    }

}

void Color::setGreen(const int& value){

    if(value >= 0 ){
        
        mGreen = value;
    }

}

void Color::setBlue(const int& value){
    
    if(value >= 0 ){
        
        mBlue = value;
    }

}

void Color::setChannel(const int& channel, const int& value){

    if(channel >= 0 && channel < 3 && value >= 0){

        if (channel == 0){

            setRed(value);
        }
        if (channel == 1){
            
            setGreen(value);
        }
        if (channel == 2){

            setBlue(value);
        }
    }
}

void Color::invert(const int& max_color_value){

    if(max_color_value >= mRed && max_color_value >= mGreen && max_color_value >= mBlue){

        mRed = max_color_value - mRed;
        mGreen = max_color_value - mGreen;
        mBlue = max_color_value - mBlue;
    }

}

bool Color::operator==(const Color& rhs) const{

    if( (*this).getRed() == rhs.getRed() && (*this).getGreen() == rhs.getGreen() && (*this).getBlue() == rhs.getBlue()){

        return true;
    }else{

        return false;
    }

}


std::ostream& operator<<(std::ostream& os, const Color& color){


    os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();

    return os;

}


ColorTable::ColorTable(const size_t& num_color){

    
    mColor.resize(num_color);

}

size_t ColorTable::getNumberOfColors()const{

    return mColor.size();
    
}

void ColorTable::setNumberOfColors(const size_t& num_color){

     mColor.resize(num_color);

}

const Color& ColorTable::operator[](const int& i) const{

    unsigned long c = i;

    if( c >= mColor.size()){

        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;

    }else{

        return mColor[c];
    }
    
}


Color& ColorTable::operator[](const int& i){

    unsigned long c = i;

    if( c >= mColor.size()){

        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;

    }else{

        return mColor[c];
    }
    
}
void ColorTable::setRandomColor(const int & max_color_value, const size_t& position){

    if(position < getNumberOfColors() && max_color_value >= 0){
        unsigned int i = max_color_value;
        int random1 = std::rand() % (i+1);
        mColor[position].setRed(random1);
        int random2 = std::rand() % (i+1);
        mColor[position].setGreen(random2);
        int random3 = std::rand() % (i+1);
        mColor[position].setBlue(random3);
    }
    
}

void ColorTable::insertGradient(const Color& color1, const Color& color2, const size_t& position1,const size_t& position2){
    
    if(position1  < position2 && position1 < getNumberOfColors() && position2 < getNumberOfColors()){

        double gapRed,gapBlue,gapGreen, step_next_position;
        int i;
        unsigned long p;
        
        for(p=position1, i = 0; p <=position2; p++,i++){

            step_next_position = position2 - position1;
            gapRed = (color2.getRed() - color1.getRed())/step_next_position;
            gapGreen = (color2.getGreen() - color1.getGreen())/step_next_position;
            gapBlue = (color2.getBlue() - color1.getBlue())/step_next_position; 

            int i_value_red = color1.getRed() + i * gapRed;
            int i_value_green = color1.getGreen() + i * gapGreen;
            int i_value_blue = color1.getBlue() + i * gapBlue;
            Color c (i_value_red,i_value_green,i_value_blue);
        
            mColor[p] = c;
        }
    }
    
}

int ColorTable::getMaxChannelValue()const{

    unsigned long i;
    int largest = 0 ;
    for (i= 0; i < mColor.size(); i++){
        int redvalue = mColor[i].getRed();
        int greenvalue = mColor[i].getGreen();
        int bluevalue = mColor[i].getBlue();
        if(redvalue > largest){
            largest = redvalue;
        }
        if(greenvalue > largest){
            largest = greenvalue;
        }
        if(bluevalue > largest){
            largest = bluevalue;
        }

    }

    return largest;
    
}

