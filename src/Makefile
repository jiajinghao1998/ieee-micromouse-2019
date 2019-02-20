testmain: testmain.o floodfill.o
	g++-8 -std=c++17 -g -o testmain testmain.o floodfill.o

testmain.o: testmain.cpp
	g++-8 -std=c++17 -g -c testmain.cpp

floodfill.o: floodfill.cpp floodfill.hpp
	g++-8 -std=c++17 -g -c floodfill.cpp

clean:
	rm -f *.o testmain
	rm -rf *.dSYM

new:
	make clean
	make
