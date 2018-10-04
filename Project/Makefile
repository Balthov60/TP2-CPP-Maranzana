CC=g++
CFLAGS=-Wall -Werror -pedantic -std=c++11
CPPFLAGS=-DMAP=1
DEBUG=-g
#-g
LDFLAGS=

VoyageVoyage : TCatalog.o Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o SearchEngine.o
	g++ $(DEBUG) $(CFLAGS) -o .Build/VoyageVoyage .Build/TCatalog.o .Build/Catalog.o .Build/ComposedPath.o .Build/SimplePath.o .Build/PathArray.o .Build/Path.o .Build/SearchEngine.o -lm

TCatalog.o : Catalog/TCatalog.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/TCatalog.o -c Catalog/TCatalog.cpp

Catalog.o : Catalog/Catalog.h Catalog/Catalog.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/Catalog.o -c Catalog/Catalog.cpp

TComposedPath : PathArray.o Path.o ComposedPath.o SimplePath.o TComposedPath.o 
	g++ $(DEBUG) $(CFLAGS) -o .Build/TComposedPath .Build/PathArray.o .Build/ComposedPath.o .Build/Path.o .Build/SimplePath.o .Build/TComposedPath.o  -lm

TComposedPath.o : ComposedPath/TComposedPath.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/TComposedPath.o -c ComposedPath/TComposedPath.cpp

ComposedPath.o : PathArray/PathArray.h ComposedPath/ComposedPath.h ComposedPath/ComposedPath.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/ComposedPath.o -c ComposedPath/ComposedPath.cpp

TSimplePath : SimplePath.o Path.o TSimplePath.o
	g++ $(DEBUG) $(CFLAGS) -o .Build/TSimplePath .Build/SimplePath.o .Build/Path.o .Build/TSimplePath.o -lm

TSimplePath.o : SimplePath/TSimplePath.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/TSimplePath.o -c SimplePath/TSimplePath.cpp

SimplePath.o : SimplePath/SimplePath.h SimplePath/SimplePath.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/SimplePath.o -c SimplePath/SimplePath.cpp

TPathArray : PathArray.o Path.o TPathArray.o SimplePath.o
	g++ $(DEBUG) $(CFLAGS) -o .Build/TPathArray .Build/PathArray.o .Build/Path.o .Build/SimplePath.o .Build/TPathArray.o  -lm

TPathArray.o : PathArray/TPathArray.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/TPathArray.o -c PathArray/TPathArray.cpp

PathArray.o : PathArray/PathArray.h PathArray/PathArray.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/PathArray.o -c PathArray/PathArray.cpp

Path.o : Path/Path.h Path/Path.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/Path.o -c Path/Path.cpp

TSearchEngine : TSearchEngine.o SearchEngine.o Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o
	g++ $(DEBUG) $(CFLAGS) -o .Build/TSearchEngine .Build/SearchEngine.o .Build/TSearchEngine.o .Build/Catalog.o .Build/ComposedPath.o .Build/SimplePath.o .Build/PathArray.o .Build/Path.o  -lm

TSearchEngine.o : SearchEngine/TSearchEngine.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/TSearchEngine.o -c SearchEngine/TSearchEngine.cpp

SearchEngine.o : SearchEngine/SearchEngine.h SearchEngine/SearchEngine.cpp
	g++ $(DEBUG) $(CFLAGS) -o .Build/SearchEngine.o -c SearchEngine/SearchEngine.cpp

clean :
	rm .Build/*.o

init :
	mkdir .Build/
