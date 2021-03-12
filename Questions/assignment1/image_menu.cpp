 #include <iostream>
 #include <string>
 #include "image_menu.h"



std::string getString( std::istream& is, std::ostream& os, const std::string& prompt ){

    std::string ans;

    os << prompt;
    is >> ans;

    return ans;
}

int getInteger( std::istream& is, std::ostream& os, const std::string& prompt ){

    int ansInt;

    os << prompt;
    is >> ansInt;

    return ansInt;
} 

double getDouble( std::istream& is, std::ostream& os, const std::string& prompt ){

    double ansDouble;

    os << prompt;
    is >> ansDouble;

    return ansDouble;

} 


int assignment1( std::istream& is, std::ostream& os ){

    int i;

    std::string favcolor = getString(is,os,"What's your favorite color? ");
    int num = getInteger(is,os, "What's your favorite integer? ");
    double num2 = getDouble(is,os, "What's your favorite number? ");

    for(i = 0; i < num; i++){
        
        os << i + 1 <<" " << favcolor <<" "  << num2 << std::endl;

    };

    return num;
} 


