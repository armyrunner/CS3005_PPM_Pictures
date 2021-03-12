#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

#include <iostream>
#include <string>
#include <cmath>
#include "PPM.h"


std::string getString( std::istream& is, std::ostream& os, const std::string& prompt );
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt );
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt );
int assignment1( std::istream& is, std::ostream& os );

// add to the file on 9/6/2019  to include the following new functions
void writeUserImage ( std::istream& is, std::ostream& os, const PPM& p);
int assignment2( std::istream& is, std::ostream& os);

// add the following on 9/9/2019 to include the following new functions
void showMenu(std::ostream& os);
std::string getChoice(std::istream& is, std::ostream& os);
void commentLine(std::istream& is);

// add the following on 9/12/2019 to include the following new fuctions
void setSize(std::istream& is, std::ostream& os, PPM& src);
void setMaxColorValue(std::istream& is, std::ostream& os, PPM& src);
void setChannel(std::istream& is, std::ostream& os, PPM& src);
void setPixel(std::istream& is, std::ostream& os, PPM& src);

void clearAll (PPM& src);
void drawDiamond(std::istream& is, std::ostream& os, PPM& src);
void drawCircle(std::istream& is, std::ostream& os, PPM& src);
void drawBox(std::istream& is, std::ostream& os, PPM& src);

// add the following on 9/13/2019 to include the following new functions
void takeAction(std::istream& is, std::ostream& os, const std::string& choice, PPM& input_image1,PPM& input_image2,PPM& output_image);
int imageMenu(std::istream& is, std::ostream& os);

#endif /*_IMAGE_MENU_H_*/