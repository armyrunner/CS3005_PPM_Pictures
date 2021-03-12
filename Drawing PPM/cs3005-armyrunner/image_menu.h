#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

#include <iostream>
#include <string>
#include "PPM.h"


std::string getString( std::istream& is, std::ostream& os, const std::string& prompt );
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt );
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt );
int assignment1( std::istream& is, std::ostream& os );

// add to the file on 9/6/2019  to include the following new commands
void writeUserImage ( std::istream& is, std::ostream& os, const PPM& p);
int assignment2( std::istream& is, std::ostream& os);

#endif /*_IMAGE_MENU_H_*/