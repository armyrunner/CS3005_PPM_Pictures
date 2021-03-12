#ifndef _THREADEDGRID_H_
#define _THREADEDGRID_H_

#include "NumberGrid.h"
#include "PPM.h"
#include "ThreadedVector.h"
#include <cstdlib> // for std::rand()
#include <ctime> // for std::time()
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

class ThreadedGrid :public NumberGrid{
    public:

        ThreadedGrid();
        ThreadedGrid(const int& height, const int& width);
        virtual ~ThreadedGrid();
        virtual void calculateAllNumbers();
        virtual void worker();
        
    private:

        ThreadedVector<int> mThreadedVector;
        
};

#endif /*_THREADEDGRID_H_*/