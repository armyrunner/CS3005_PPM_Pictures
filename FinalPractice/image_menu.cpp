#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "image_menu.h"
#include "PPM.h"
#include "NumberGrid.h"
#include "MandelbrotSet.h"


std::string getString(std::istream &is, std::ostream &os, const std::string &prompt)
{

    std::string ans;

    os << prompt;
    is >> ans;

    return ans;
}

int getInteger(std::istream &is, std::ostream &os, const std::string &prompt)
{

    int ansInt;

    os << prompt;
    is >> ansInt;

    return ansInt;
}

double getDouble(std::istream &is, std::ostream &os, const std::string &prompt)
{

    double ansDouble;

    os << prompt;
    is >> ansDouble;

    return ansDouble;
}

int assignment1(std::istream &is, std::ostream &os)
{

    int i;

    std::string favcolor = getString(is, os, "What's your favorite color? ");
    int num = getInteger(is, os, "What's your favorite integer? ");
    double num2 = getDouble(is, os, "What's your favorite number? ");

    for (i = 0; i < num; i++)
    {

        os << i + 1 << " " << favcolor << " " << num2 << std::endl;
    };

    return num;
}
void writeUserImage(std::istream &is, std::ostream &os, const PPM &p)
{
    std::string output = getString(is, os, "Output filename? ");
    std::ofstream fout(output);
    fout << p;
    fout.close();
}

int assignment2(std::istream &is, std::ostream &os)
{
    int height = getInteger(is, os, "Image height? ");
    int width = getInteger(is, os, "Image width? ");
    PPM p(height, width);
    p.setMaxColorValue((height + width) / 3);

    for (int row = 0; row < p.getHeight(); row++)
    {
        for (int column = 0; column < p.getWidth(); column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                if (row < height / 2)
                {
                    p.setChannel(row, column, 0, 0);
                }
                else
                {
                    p.setChannel(row, column, 0, p.getMaxColorValue());
                }
            }
        }
    }

    for (int row = 0; row < p.getHeight(); row++)
    {
        for (int column = 0; column < p.getWidth(); column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                if (column < p.getWidth() / 2)
                {
                    p.setChannel(row, column, 1, 0);
                }
                else
                {
                    p.setChannel(row, column, 2, p.getMaxColorValue());
                }
            }
        }
    }
    for (int row = 0; row < p.getHeight(); row++)
    {
        for (int column = 0; column < p.getWidth(); column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                int green = (row + column) % (p.getMaxColorValue() + 1);
                p.setChannel(row, column, 1, green);
            }
        }
    }

    writeUserImage(is, os, p);
    return 0;
}

void showMenu(std::ostream &os)
{
    os << "\nActions available:\n";
    os << "\n";
    os << "read1) Read file into input image 1.\n";
    os << "read2) Read file into input image 2.\n";
    os << "write) Write output image to file.\n";
    os << "copy) Copy input image 1 to output image.\n";
    os << "red-gray) Set output image from input image 1's grayscale from red.\n";
    os << "green-gray) Set output image from input image 1's grayscale from green.\n";
    os << "blue-gray) Set output image from input image 1's grayscale from blue.\n";
    os << "linear-gray) Set output image from input image 1's grayscale from linear colorimetric.\n";
    os << "v-edge) Set output image from input image 1's vertical edge detection\n";
    os << "h-edge) Set output image from input image 1's horizontal edge detection\n";
    os << "+) Set output image from sum of input image 1 and input image 2\n";
    os << "+=) Set input image 1 by adding in input image 2\n";
    os << "-) Set output image from difference of input image 1 and input image 2\n";
    os << "-=) Set input image 1 by subtracting input image 2\n";
    os << "*) Set output image from input image 1 multiplied by a number\n";
    os << "*=) Set input image 1 by multiplying by a number\n";
    os << "/) Set output image from input image 1 divided by a number\n";
    os << "/=) Set input image 1 by dividing by a number\n";
    os << "#) Comment to end of line\n";
    os << "size) Set the size of input image 1\n";
    os << "fractal-plane-size) Set the dimensions of the grid in the complex plane.\n";
    os << "fractal-calculate) Calculate the escape values for the fractal.\n";
 	os << "fractal-calculate-single-thread) Calculate the escape values for a single fractal thread.\n";
   	os << "julia) Choose to make a Julia set.\n";
    os << "julia-parameters) Set the parameters of the Julia Set function.\n";
    os << "mandelbrot) Choose to make a Mandelbrot set.\n";
    os << "burningship) Choose to make a Burningship\n";
    os << "grid-apply-color-table) Use the grid values to set colors in the output image using the color table.\n";
    os << "set-color-table-size) Change the number of slots in the color table.\n";
    os << "set-color) Set the RGB values for one slot in the color table.\n";
    os << "set-random-color) Randomly set the RGB values for one slot in the color table.\n";
    os << "set-color-gradient) Smoothly set the RGB values for a range of slots in the color table.\n";
    os << "set-crop) Crop your image\n";
    os << "hsv) Change RGB to HSV\n";
    os << "max) Set the max color value of input image 1\n";
    os << "channel) Set a channel value in input image 1\n";
    os << "pixel) Set a pixel's 3 values in input image 1\n";
    os << "clear) Set all pixels to 0,0,0 in input image 1\n";
    os << "grid) Configure the grid.\n";
    os << "grid-set) Set a single value in the grid.\n";
    os << "grid-apply) Use the grid values to set colors in the output image.\n";
    os << "diamond) Draw a diamond shape in input image 1\n";
    os << "circle) Draw a circle shape in input image 1\n";
    os << "box) Draw a box shape in input image 1\n";
    os << "quiet) Toggle output quieting\n";
    os << "run) Run commands from another file\n";
    os << "quit) Quit\n\n";
}

std::string getChoice(std::istream &is, std::ostream &os)
{

    std::string ans = getString(is, os, "Choice? ");

    return ans;
}

void commentLine(std::istream &is)
{
    unsigned char c;
	c = '#';

    while (c != '\n' and !is.eof())
    {

        is.read((char *)&c, 1);
    }
}

void setSize(std::istream &is, std::ostream &os, PPM &src)
{

    src.setHeight(getInteger(is, os, "Height? "));
    src.setWidth(getInteger(is, os, "Width? "));
}

void setMaxColorValue(std::istream &is, std::ostream &os, PPM &src)
{

    src.setMaxColorValue(getInteger(is, os, "Max color value? "));
}

void setChannel(std::istream &is, std::ostream &os, PPM &src)
{

    int row = getInteger(is, os, "Row? ");
    int column = getInteger(is, os, "Column? ");
    int channel = getInteger(is, os, "Channel? ");
    int value = getInteger(is, os, "Value? ");

    src.setChannel(row, column, channel, value);
}

void setPixel(std::istream &is, std::ostream &os, PPM &src)
{

    int row = getInteger(is, os, "Row? ");
    int column = getInteger(is, os, "Column? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");

    src.setPixel(row, column, red, green, blue);
}

void clearAll(PPM &src)
{

    for (int row = 0; row < src.getHeight(); row++)
    {
        for (int column = 0; column < src.getWidth(); column++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                src.setPixel(row, column, 0, 0, 0);
            }
        }
    }
}

void drawDiamond(std::istream &is, std::ostream &os, PPM &src)
{

    int centerRow = getInteger(is, os, "Center Row? ");
    int centerColumn = getInteger(is, os, "Center Column? ");
    int size = getInteger(is, os, "Size? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");

    for (int row = 0; row < src.getHeight(); row++)
    {
        for (int column = 0; column < src.getWidth(); column++)
        {
            int dist = std::abs(centerColumn - column) + std::abs(centerRow - row);

            if (dist <= size)
            {
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}

void drawCircle(std::istream &is, std::ostream &os, PPM &src)
{

    int centerRow = getInteger(is, os, "Center Row? ");
    int centerColumn = getInteger(is, os, "Center Column? ");
    int radius = getInteger(is, os, "Radius? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");

    for (int row = 0; row < src.getHeight(); row++)
    {
        for (int column = 0; column < src.getWidth(); column++)
        {
            double dist = std::sqrt(abs(pow((centerColumn - column), 2)) + abs(pow((centerRow - row), 2)));

            if (dist <= radius)
            {
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}

void drawBox(std::istream &is, std::ostream &os, PPM &src)
{

    int topRow = getInteger(is, os, "Top Row? ");
    int leftColumn = getInteger(is, os, "Left Column? ");
    int bottomRow = getInteger(is, os, "Bottom Row? ");
    int rightColumn = getInteger(is, os, "Right Column? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");

    for (int row = 0; row < src.getHeight(); row++)
    {
        for (int column = 0; column < src.getWidth(); column++)
        {

            if (row >= topRow && row <= bottomRow && column >= leftColumn && column <= rightColumn)
            {
                src.setPixel(row, column, red, green, blue);
            }
        }
    }
}

void takeAction(std::istream &is, std::ostream &os, const std::string &choice, PPM &input_image1, PPM &input_image2, PPM &output_image, NumberGrid &grid, ColorTable& table)
{

    if (choice == "write")
    {
        writeUserImage(is, os, output_image);
    }
    else if (choice == "copy")
    {
        output_image = input_image1;
    }
    else if (choice == "#")
    {
        commentLine(is);
    }
    else if (choice == "size")
    {
        setSize(is, os, input_image1);
    }
    else if (choice == "max")
    {
        setMaxColorValue(is, os, input_image1);
    }
    else if (choice == "channel")
    {
        setChannel(is, os, input_image1);
    }
    else if (choice == "pixel")
    {
        setPixel(is, os, input_image1);
    }
    else if (choice == "clear")
    {
        clearAll(input_image1);
    }
    else if (choice == "diamond")
    {
        drawDiamond(is, os, input_image1);
    }
    else if (choice == "circle")
    {
        drawCircle(is, os, input_image1);
    }
    else if (choice == "box")
    {
        drawBox(is, os, input_image1);
    }
    else if (choice == "read1")
    {
        readUserImage(is, os, input_image1);
    }
    else if (choice == "red-gray")
    {
        input_image1.grayFromRed(output_image);
    }
    else if (choice == "green-gray")
    {
        input_image1.grayFromGreen(output_image);
    }
    else if (choice == "blue-gray")
    {
        input_image1.grayFromBlue(output_image);
    }
    else if (choice == "linear-gray")
    {
        input_image1.grayFromLinearColorimetric(output_image);
    }
    else if (choice == "read2")
    {
        readUserImage(is, os, input_image2);
    }
    else if (choice == "+")
    {
        plus(is, os, input_image1, input_image2, output_image);
    }
    else if (choice == "+=")
    {
        plusEquals(is, os, input_image1, input_image2);
    }
    else if (choice == "-")
    {
        minus(is, os, input_image1, input_image2, output_image);
    }
    else if (choice == "-=")
    {
        minusEquals(is, os, input_image1, input_image2);
    }
    else if (choice == "*")
    {
        times(is, os, input_image1, output_image);
    }
    else if (choice == "*=")
    {
        timesEquals(is, os, input_image1);
    }
    else if (choice == "/")
    {
        divide(is, os, input_image1, output_image);
    }
    else if (choice == "/=")
    {
        divideEquals(is, os, input_image1);
    }
    else if (choice == "quit")
    {
        return;
    }
    else if (choice == "julia")
    {
        return;
    }
    else if (choice == "mandelbrot")
    {
        return;
    }
    else if (choice == "burningship")
    {
        return;
    }
    else if (choice == "v-edge")
    {
        input_image1.findVerticalEdges(output_image);
    }
    else if (choice == "h-edge")
    {
        input_image1.findHorizontalEdges(output_image);
    }
    else if (choice == "quiet")
    {
    }
    else if (choice == "run")
    {
        runFile(is, os, input_image1, input_image2, output_image);
    }
    else if (choice == "grid")
    {
        configureGrid(is, os, grid);
    }
    else if (choice == "grid-apply")
    {
        applyGrid(is, os, grid, output_image);
    }
    else if (choice == "grid-set")
    {
        setGrid(is, os, grid);
    }
    else if (choice == "fractal-plane-size")
    {
        setFractalPlaneSize(is, os, grid);
    }
    else if (choice == "fractal-calculate-single-thread")
    {
        calculateFractalSingleThread(is, os, grid);
    }
    else if (choice == "fractal-calculate")
    {
        calculateFractal(is, os, grid);
	}
	else if (choice == "julia-parameters")
    {
        setJuliaParameters(is, os, grid);
    }
    else if (choice == "grid-apply-color-table")
    {
        applyGridColorTable(is, os, grid,table,output_image);
    }
    else if(choice == "set-crop")
    {
        setcrop(is,os,input_image1,output_image);
    }
    else if (choice == "set-color-table-size")
    {
        setColorTableSize(is, os, table);
    }
    else if(choice == "hsv"){
        
        setColorToHSV(is,os,table);
    }
    else if (choice == "set-color")
    {
        setColor(is, os, table);
    }
    else if (choice == "set-random-color")
    {
        setRandomColor(is, os,table);
    }
    else if (choice == "set-color-gradient")
    {
        setColorGradient(is, os,table); 
    }
    else
    {
        os << "Unknown action '" << choice << "'." << std::endl;
    }
}

int imageMenu(std::istream &is, std::ostream &os)
{
    PPM input_image1;
    PPM input_image2;
    PPM output_image;
    NumberGrid *gptr = new JuliaSet();
    ColorTable table = ColorTable(16);
    Color c1(0,255,0);
    Color c2(255,0,255);
    table.insertGradient(c1,c2,0,15);

    bool quiet = false;

    showMenu(os);
    std::string choice = getChoice(is, os);



    if (choice == "quiet")
    {
        quiet = true;
    }

    std::stringstream sstream;
    while (choice != "quit")
    {

        if (!quiet)
        {
            takeAction(is, os, choice, input_image1, input_image2, output_image, *gptr, table);
            showMenu(os);

            choice = getChoice(is, os);
            if (choice == "quiet")
            {
                quiet = true;
            }
            else if ( choice == "julia"){
                
                setJuliaFractal(is, os, gptr);
            }
            else if( choice == "mandelbrot"){

                setMandelbrotFractal(is, os, gptr);
            }
            else if( choice == "burningship"){

                setBurningshipFractal(is, os, gptr);
            }

        }
        else
        {
            takeAction(is, sstream, choice, input_image1, input_image2, output_image, *gptr, table);
            choice = getChoice(is, sstream);
            if (choice == "quiet")
            {
                quiet = false;
            }
            else if ( choice == "julia"){
                
                setJuliaFractal(is, os, gptr);
            }
            else if( choice == "mandelbrot"){

                setMandelbrotFractal(is ,os ,gptr);
            }
            else if( choice == "burningship"){

                setBurningshipFractal(is, os, gptr);
            }
        }
    }

    return 0;
}

void readUserImage(std::istream &is, std::ostream &os, PPM &ppm)
{

    std::string input_image1 = getString(is, os, "Input filename? ");
    std::ifstream fin(input_image1);
    fin >> ppm;
    fin.close();
}

void plusEquals(std::istream &is, std::ostream &os, PPM &src1, const PPM &src2)
{

    (void)is;
    (void)os;

    src1.operator+=(src2);
}

void minusEquals(std::istream &is, std::ostream &os, PPM &src1, const PPM &src2)
{

    (void)is;
    (void)os;

    src1.operator-=(src2);
}

void timesEquals(std::istream &is, std::ostream &os, PPM &src)
{
    double value;
    value = getDouble(is, os, "Factor? ");

    src.operator*=(value);
}
void divideEquals(std::istream &is, std::ostream &os, PPM &src)
{

    double value;
    value = getDouble(is, os, "Factor? ");

    src.operator/=(value);
}

void plus(std::istream &is, std::ostream &os, const PPM &src1, const PPM &src2, PPM &dst)
{

    (void)is;
    (void)os;

    dst = src1.operator+(src2);
}

void minus(std::istream &is, std::ostream &os, const PPM &src1, const PPM &src2, PPM &dst)
{

    (void)is;
    (void)os;

    dst = src1.operator-(src2);
}

void times(std::istream &is, std::ostream &os, const PPM &src, PPM &dst)
{

    double value = getDouble(is, os, "Factor? ");

    dst = src.operator*(value);
}

void divide(std::istream &is, std::ostream &os, const PPM &src, PPM &dst)
{

    double value = getDouble(is, os, "Factor? ");

    dst = src.operator/(value);
    ;
}

int runFile(std::istream &is, std::ostream &os, PPM &input_image1, PPM &input_image2, PPM &output_image)
{

    std::string namefile = getString(is, os, "File? ");
    std::ifstream myfile;
    myfile.open(namefile);
    std::stringstream stream1;
    NumberGrid *gptr = new JuliaSet();

    ColorTable table = ColorTable(16);
    Color c1(0,255,0);
    Color c2(255,0,255);
    table.insertGradient(c1,c2,0,15);

    if (!myfile.good())
    {
        return 1;
    }

    std::string choice = "";
    while (choice != "quit" && myfile.good())
    {

        std::string choice = getChoice(myfile, stream1);
        takeAction(myfile, stream1, choice, input_image1, input_image2, output_image, *gptr,table);
    }
    return 0;
}

void configureGrid(std::istream &is, std::ostream &os, NumberGrid &grid)
{
    int height = getInteger(is, os, "Grid Height? ");
    int width = getInteger(is, os, "Grid Width? ");
    int gmv = getInteger(is, os, "Grid Max Value? ");

    grid.setGridSize(height, width);
    grid.setMaxNumber(gmv);
}

void setGrid(std::istream &is, std::ostream &os, NumberGrid &grid)
{
    int grow = getInteger(is, os, "Grid Row? ");
    int gcol = getInteger(is, os, "Grid Column? ");
    int gvalue = getInteger(is, os, "Grid Value? ");

    grid.setNumber(grow, gcol, gvalue);
}

void applyGrid(std::istream &is, std::ostream &os, NumberGrid &grid, PPM &dst)
{

    (void)is;
    (void)os;

    grid.setPPM(dst);
}


void setFractalPlaneSize( std::istream& is, std::ostream& os, NumberGrid& grid )
{
    double min_x = getDouble(is, os, "Min X? ");
    double max_x = getDouble(is, os, "Max X? ");
    double min_y = getDouble(is, os, "Min Y? ");
    double max_y = getDouble(is, os, "Max Y? ");

    ComplexFractal *jptr = dynamic_cast<ComplexFractal*>(&grid);
    if(jptr !=0 ){
 
        jptr -> setPlaneSize(min_x, max_x, min_y, max_y);
    }
    else{
        os << "Not a ComplexFractal object. Can't set plane size."<< std::endl;
    }

}


void calculateFractal( std::istream& is, std::ostream& os, NumberGrid& grid )
{
    (void)is;
    (void)os;

    grid.calculateAllNumbers();

}

void setJuliaParameters( std::istream& is, std::ostream& os, NumberGrid& grid )
{
    JuliaSet *jptr = dynamic_cast<JuliaSet*>(&grid);
    if(jptr !=0 ){
        double a = getDouble(is, os, "Parameter a? ");
        double b = getDouble(is, os, "Parameter b? ");
        jptr->setParameters(a,b);
    }else{

        os << "Not a JuliaSet object. Can’t set parameters."<< std::endl;
    }

}

void setJuliaFractal( std::istream& is, std::ostream& os, NumberGrid*& grid ){

   (void) is;
   (void) os;

   if(grid != 0){
       delete(grid);
   }

   grid = new JuliaSet;
}


void setMandelbrotFractal( std::istream& is, std::ostream& os, NumberGrid*& grid ){

    (void) is;
    (void) os; 

    if(grid != 0){
       delete(grid);
   }

   grid = new MandelbrotSet;

}

void setBurningshipFractal( std::istream& is, std::ostream& os, NumberGrid*& grid ){
    (void) is;
    (void) os; 

    if(grid != 0){
       delete(grid);
   }

   grid = new Burningship;

}


void applyGridColorTable( std::istream& is, std::ostream& os, NumberGrid& grid, ColorTable& table, PPM& dst ){

    (void)is;
    (void)os;

    grid.setPPM(dst,table);

}

void setcrop( std::istream& is, std::ostream& os,PPM& src, PPM& dst){

    int right = getInteger(is,os,"Right ?");
    int left =  getInteger(is,os,"Left ?");
    int top = getInteger(is,os,"Top ?");
    int bottom = getInteger(is,os,"Bottom ?");

    src.crop(dst,left,right,top,bottom);

}

void setColorTableSize( std::istream& is, std::ostream& os, ColorTable& table ){

    int size = getInteger(is, os, "Size? ");

    table.setNumberOfColors(size);
    
}

void setColor( std::istream& is, std::ostream& os, ColorTable& table ){

    int pos = getInteger(is, os, "Position? ");
    int red = getInteger(is, os, "Red? ");
    int green = getInteger(is, os, "Green? ");
    int blue = getInteger(is, os, "Blue? ");

    Color c (red,green,blue);

    table.operator[](pos) = c;

    
}

void setRandomColor( std::istream& is, std::ostream& os, ColorTable& table ){
    
    int position = getInteger(is, os, "Position? ");
    
    table.setRandomColor(255,position);


}

void setColorGradient( std::istream& is, std::ostream& os, ColorTable& table ){

    int fp1 = getInteger(is, os, "First position? ");
    int fr1 = getInteger(is, os, "First red? ");
    int fg1 = getInteger(is, os, "First green? ");
    int fb1 = getInteger(is, os, "First blue? ");

    int fp2 = getInteger(is, os, "Second position? ");
    int fr2 = getInteger(is, os, "Second red? ");
    int fg2 = getInteger(is, os, "Second green? ");
    int fb2 = getInteger(is, os, "Second blue? ");

    Color c1 (fr1,fg1,fb1);
    Color c2 (fr2,fg2,fb2);


    table.insertGradient(c1,c2,fp1,fp2);
}
void calculateFractalSingleThread( std::istream& is, std::ostream& os, NumberGrid& grid ){


    (void)is;
    (void)os;

    grid.NumberGrid::calculateAllNumbers();


}

void setColorToHSV(std::istream& is, std::ostream& os, ColorTable& table){

    int p = getInteger(is,os, "Position ?");
    float h = getDouble(is,os,"Hue ?");
    float s = getDouble(is,os, "Saturation ?");
    float v = getDouble(is,os, "Value ?");

    table.HSVtoRGB(p,h,s,v);

}





