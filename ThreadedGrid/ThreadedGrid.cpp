#include "ThreadedGrid.h"


ThreadedGrid::ThreadedGrid(){

}

ThreadedGrid::ThreadedGrid(const int& height, const int& width):NumberGrid(height,width){

}

ThreadedGrid::~ThreadedGrid(){

}

void ThreadedGrid::calculateAllNumbers(){
	std::vector<std::thread> threads;
	unsigned int max_threads = std::thread::hardware_concurrency();
	unsigned int i;
    int columns;
	for(columns = 0; columns < mHeight; columns++){
		mThreadedVector.push_back(columns);
	}

	for(i = 0; i < max_threads; i++){

		threads.push_back( std::thread(&ThreadedGrid::worker,this));
	}

	for( i = 0; i < max_threads; i++ ) {
    	threads[ i ].join( );
  }

}

void ThreadedGrid::worker(){
	std::vector<int> my_vector_rows;
	int i;


	while(!mThreadedVector.empty()){
		
		my_vector_rows.clear();
		mThreadedVector.pop_back(my_vector_rows,1);

		if(my_vector_rows.size() > 0){

			int pixel_rows = my_vector_rows[0];

			for( i = 0; i < mWidth; i++){
				int value = calculateNumber(pixel_rows,i);
				setNumber(pixel_rows,i,value);

			}
		}
	}
}

