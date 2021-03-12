

#ifndef _NumberGrid_H_
#define _NumberGrid_H_
// starte h file on 10/09/19 to increase functionality to ppm program

#include <vector>
#include "PPM.h"
#include "ColorTable.h"

class NumberGrid
{
	public:
		NumberGrid( );
		NumberGrid( const int& height, const int& width );
		
		int getHeight( ) const;
		int getWidth( ) const;
		int getMaxNumber( ) const;
		void setMaxNumber( const int& number );
		const std::vector< int >& getNumbers( ) const;
		int index( const int& row, const int& column ) const;
		bool indexValid( const int& row, const int& column ) const;
		bool numberValid( const int& number ) const;
		int getNumber( const int& row, const int& column ) const;
		void setNumber( const int& row, const int& column, const int& number );
		void setPPM( PPM& ppm ) const;
		
		virtual ~NumberGrid();
		virtual int calculateNumber( const int& height, const int& width) const = 0;
		virtual void calculateAllNumbers();
		virtual void setGridSize( const int& height, const int& width );
		void setPPM ( PPM& ppm, const ColorTable& colors) const;


	private:

		int mWidth;
		int mHeight;
		int mMaxNumber;

		std::vector<int> mData;
};


#endif /* _NumberGrid_H_ */
