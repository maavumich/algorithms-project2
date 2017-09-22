all: parta partb

parta: parta.cpp
	g++ parta.cpp -I /usr/include/eigen3/ -lboost_iostreams -lboost_system -lboost_filesystem -o parta

