CC=g++
CFLAGS=-Wall -Werror -pedantic
CPPFLAGS=-DMAP=1
LDFLAGS=

VoyageVoyage : TCatalog.o Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o
	g++ -g -o .Build/VoyageVoyage .Build/TCatalog.o .Build/Catalog.o .Build/ComposedPath.o .Build/SimplePath.o .Build/PathArray.o .Build/Path.o -lm

TCatalog.o : Catalog/TCatalog.cpp
	g++ -g -o .Build/TCatalog.o -c Catalog/TCatalog.cpp

Catalog.o : Catalog/Catalog.h Catalog/Catalog.cpp
	g++ -g -o .Build/Catalog.o -c Catalog/Catalog.cpp

ComposedPath.o : ComposedPath/ComposedPath.h ComposedPath/ComposedPath.cpp
	g++ -g -o .Build/ComposedPath.o -c ComposedPath/ComposedPath.cpp

TSimplePath : SimplePath.o Path.o TSimplePath.o
	g++ -g -o .Build/TSimplePath .Build/SimplePath.o .Build/Path.o .Build/TSimplePath.o -lm

TSimplePath.o : SimplePath/TSimplePath.cpp
	g++ -g -o .Build/TSimplePath.o -c SimplePath/TSimplePath.cpp

SimplePath.o : SimplePath/SimplePath.h SimplePath/SimplePath.cpp
	g++ -g -o .Build/SimplePath.o -c SimplePath/SimplePath.cpp

PathArray.o : PathArray/PathArray.h PathArray/PathArray.cpp
	g++ -g -o .Build/PathArray.o -c PathArray/PathArray.cpp

Path.o : Path/Path.h Path/Path.cpp
	g++ -g -o .Build/Path.o -c Path/Path.cpp

clean :
	rm .Build/*.o

init :
	mkdir .Build/
