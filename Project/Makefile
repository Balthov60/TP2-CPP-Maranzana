CC=g++
CFLAGS=-Wall -Werror -pedantic
CPPFLAGS=-DMAP=1
LDFLAGS=

VoyageVoyage : Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o
	g++ -o VoyageVoyageCatalog.o ComposedPath.o SimplePath.o PathArray.o Path.o -lm

Catalog.o : Catalog/Catalog.h Catalog/Catalog.cpp
	g++ -c Catalog/Catalog.cpp

ComposedPath.o : ComposedPath/ComposedPath.h ComposedPath/ComposedPath.cpp
	g++ -c ComposedPath/ComposedPath.cpp

SimplePath.o : SimplePath/SimplePath.h SimplePath/SimplePath.cpp
	g++ -c SimplePath/SimplePath.cpp

PathArray.o : PathArray/PathArray.h PathArray/PathArray.cpp
	g++ -c PathArray/PathArray.cpp

Path.o : Path/Path.h Path/Path.cpp
	g++ -c Path/Path.cpp

clean :
	rm *.o
