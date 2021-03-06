#ifndef _ColorTable_H_
#define _ColorTable_H_

#include <iostream>
#include <vector>


class Color{

    public:

        Color();
        Color(const int& red,const int& green,const int& blue);
        int getRed() const;
        int getGreen() const;
        int getBlue() const;
        int getChannel(const int& channel) const;
        void setRed(const int& value);
        void setGreen(const int& value);
        void setBlue(const int& value);
        void setChannel(const int& channel, const int& value);
        void invert(const int& max_color_value);
        bool operator==(const Color& rhs) const;
        void setFromHSV( const double& hue, const double& saturation, const double& value );
       


    private:

        int mRed;
        int mGreen;
        int mBlue;



}; 

std::ostream& operator<<(std::ostream& os, const Color& color);

class ColorTable{

    public:

        ColorTable(const size_t& num_color);
        size_t getNumberOfColors()const;
        void setNumberOfColors(const size_t& num_color);
        const Color& operator[](const int& i) const;
        Color& operator[](const int& i) ;
        void setRandomColor(const int & max_color_value, const size_t& position);
        void insertGradient(const Color& color1, const Color& color2, const size_t& position1,const size_t& position2);
        int getMaxChannelValue()const;
        void insertHSVGradient( const double& h1, const double& s1, const double& v1, const double& h2, const double& s2, const double& v2, const size_t& position1, const size_t& position2 );

    private:

        std::vector<Color> mColor;

};




#endif /* _ColorTable_H_ */