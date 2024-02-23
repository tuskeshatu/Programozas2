CXXFLAGS = -Wall

elso.exe: main.o module.o
	g++ -o &(CXXFLAGS) elso.exe main.o module.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

module.o: module.cpp
	g++ -c -o module.o module.cpp