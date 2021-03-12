 #include <iostream>
 #include <fstream>
 #include <string>
 #include "image_menu.h"
 #include "PPM.h"




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
void writeUserImage ( std::istream& is, std::ostream& os, const PPM& p){
    std::string output = getString(is, os, "Output filename? ");
    std::ofstream fout(output);
    fout<<p;
    fout.close();
    
}

int assignment2( std::istream& is, std::ostream& os ){
    int height=getInteger(is,os,"Image height? ");
    int width=getInteger(is,os,"Image width? ");
    PPM p(height,width);
    p.setMaxColorValue((height+width)/3);

    for (int row=0; row<p.getHeight();row++){
        for(int column=0; column<p.getWidth();column++){
            for(int channel=0;channel<3;channel++){
                if(row<height/2){
                    p.setChannel(row,column,0,0);
                }
                else{
                    p.setChannel(row,column,0,p.getMaxColorValue());
                }
            }
        }
    }
    
    for (int row=0; row<p.getHeight();row++){
        for(int column=0; column<p.getWidth();column++){
            for(int channel=0;channel<3;channel++){
                if(column<p.getWidth()/2){
                    p.setChannel(row,column,1,0);
                }
                else{
                    p.setChannel(row,column,2,p.getMaxColorValue());
                }
            }
        }
    }
    for (int =0; row<p.getHeight();row++){
            for(int column=0; column<p.getWidth();column++){
                for(int channel=0;channel<3;channel++){
                    int green=(row+column)%(p.getMaxColorValue()+1);
                    p.setChannel(row,column,1,green);
                }
            }
        }

    writeUserImage(is,os,p);
    return 0;
}

