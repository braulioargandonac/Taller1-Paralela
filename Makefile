CXX = g++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

Estudiante.o: directorios Estudiante.cpp Estudiante.h
	$(CXX) $(CXXFLAGS) -c Estudiante.cpp -o build/Estudiante.o

Funciones.o: directorios Funciones.cpp Funciones.h
	$(CXX) $(CXXFLAGS) -c Funciones.cpp -o build/Funciones.o

all: clean main.o Funciones.o Estudiante.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Funciones.o build/Estudiante.o $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all
