all: ppm_menu

ppm_menu: ppm_menu.o image_menu.o PPM.o NumberGrid.o
	g++ -std=c++11 -o ppm_menu  ppm_menu.o image_menu.o PPM.o NumberGrid.o

PPM.o: PPM.cpp PPM.h
	g++ -std=c++11 -c PPM.cpp

ppm_menu.o: ppm_menu.cpp image_menu.h 
	g++ -std=c++11 -c ppm_menu.cpp

image_menu.o: image_menu.cpp image_menu.h PPM.h
	g++ -std=c++11 -c image_menu.cpp 

NumberGrid.o: NumberGrid.cpp NumberGrid.h PPM.h
	g++ -std=c++11 -c NumberGrid.cpp
clean:
	-rm -f ppm_menu.o image_menu.o PPM.o
