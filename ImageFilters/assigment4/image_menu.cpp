#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "image_menu.h"
#include "PPM.h"

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
    os << "write) Write output image to file.\n";
    os << "copy) Copy input image 1 to output image.\n";
    os << "red-gray) Set output image from input image 1's grayscale from red.\n";
    os << "green-gray) Set output image from input image 1's grayscale from green.\n";
    os << "blue-gray) Set output image from input image 1's grayscale from blue.\n";
    os << "linear-gray) Set output image from input image 1's grayscale from linear colorimetric.\n";
    os << "# Comment to end of line\n";
    os << "size) Set the size of input image 1\n";
    os << "max) Set the max color value of input image 1\n";
    os << "channel) Set a channel value in input image 1\n";
    os << "pixel) Set a pixel's 3 values in input image 1\n";
    os << "clear) Set all pixels to 0,0,0 in input image 1\n";
    os << "diamond) Draw a diamond shape in input image 1\n";
    os << "circle) Draw a circle shape in input image 1\n";
    os << "box) Draw a box shape in input image 1\n";
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

void takeAction(std::istream &is, std::ostream &os, const std::string &choice, PPM &input_image1, PPM &input_image2, PPM &output_image)
{

    (void)input_image2;

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
    else if (choice == "quit")
    {
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

    else
    {
        os << "Unknown Action " << choice << std::endl;
    }
}

int imageMenu(std::istream &is, std::ostream &os)
{
    PPM input_image1;
    PPM input_image2;
    PPM output_image;

    showMenu(os);
    std::string choice = getChoice(is, os);

    while (choice != "quit")
    {

        takeAction(is, os, choice, input_image1, input_image2, output_image);
        showMenu(os);
        choice = getChoice(is, os);
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
