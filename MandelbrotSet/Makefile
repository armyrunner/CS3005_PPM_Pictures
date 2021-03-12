all: ppm_menu

ppm_menu: ppm_menu.o image_menu.o PPM.o NumberGrid.o JuliaSet.o MandelbrotSet.o ComplexFractal.o
	g++ -std=c++11 -o ppm_menu  ppm_menu.o image_menu.o PPM.o NumberGrid.o JuliaSet.o MandelbrotSet.o ComplexFractal.o

PPM.o: PPM.cpp PPM.h
	g++ -std=c++11 -c PPM.cpp

ppm_menu.o: ppm_menu.cpp image_menu.h 
	g++ -std=c++11 -c ppm_menu.cpp

image_menu.o: image_menu.cpp image_menu.h PPM.h
	g++ -std=c++11 -c image_menu.cpp 

NumberGrid.o: NumberGrid.cpp NumberGrid.h PPM.h
	g++ -std=c++11 -c NumberGrid.cpp

JuliaSet.o: JuliaSet.cpp JuliaSet.h NumberGrid.h PPM.h ComplexFractal.h
	g++ -std=c++11 -c JuliaSet.cpp

MandelbrotSet.o: MandelbrotSet.cpp MandelbrotSet.h NumberGrid.h PPM.h ComplexFractal.h
	g++ -std=c++11 -c MandelbrotSet.cpp

ComplexFractal.o: ComplexFractal.cpp ComplexFractal.h NumberGrid.h PPM.h NumberGrid.h 
	g++ -std=c++11 -c ComplexFractal.cpp

clean:
	-rm -f *.o
