# VARIABLES
CC=g++
CC_FLAGS=-Wall -Werror -pedantic -std=c++11

CPPFLAGS=-DMAP=1
DEBUG=-g
#-g

# FILES NAMES
EXEC = VoyageVoyage
BUILD_FOLDER = .Build/
FILES_NAMES = Catalog ComposedPath
OBJECTS = TCatalog.o Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o

# RULES

$(EXEC) : TCatalog.o Catalog.o ComposedPath.o SimplePath.o PathArray.o Path.o
	$(CC) $(DEBUG) $(CC_FLAGS) -o $(BUILD_FOLDER)$(EXEC) .Build/TCatalog.o .Build/Catalog.o .Build/ComposedPath.o .Build/SimplePath.o .Build/PathArray.o .Build/Path.o -lm

TCatalog.o : Catalog/TCatalog.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TCatalog.o -c Catalog/TCatalog.cpp

Catalog.o : Catalog/Catalog.h Catalog/Catalog.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/Catalog.o -c Catalog/Catalog.cpp

TComposedPath : PathArray.o Path.o ComposedPath.o SimplePath.o TComposedPath.o 
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TComposedPath .Build/PathArray.o .Build/ComposedPath.o .Build/Path.o .Build/SimplePath.o .Build/TComposedPath.o  -lm

TComposedPath.o : ComposedPath/TComposedPath.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TComposedPath.o -c ComposedPath/TComposedPath.cpp

ComposedPath.o : PathArray/PathArray.h ComposedPath/ComposedPath.h ComposedPath/ComposedPath.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/ComposedPath.o -c ComposedPath/ComposedPath.cpp

TSimplePath : SimplePath.o Path.o TSimplePath.o
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TSimplePath .Build/SimplePath.o .Build/Path.o .Build/TSimplePath.o -lm

TSimplePath.o : SimplePath/TSimplePath.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TSimplePath.o -c SimplePath/TSimplePath.cpp

SimplePath.o : SimplePath/SimplePath.h SimplePath/SimplePath.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/SimplePath.o -c SimplePath/SimplePath.cpp

TPathArray : PathArray.o Path.o TPathArray.o SimplePath.o
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TPathArray .Build/PathArray.o .Build/Path.o .Build/SimplePath.o .Build/TPathArray.o  -lm

TPathArray.o : PathArray/TPathArray.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/TPathArray.o -c PathArray/TPathArray.cpp

PathArray.o : PathArray/PathArray.h PathArray/PathArray.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/PathArray.o -c PathArray/PathArray.cpp

Path.o : Path/Path.h Path/Path.cpp
	$(CC) $(DEBUG) $(CC_FLAGS) -o .Build/Path.o -c Path/Path.cpp


# COMMANDS

clean:
	rm -f *(BUILD_FOLDER)*.o

init :
	mkdir $(BUILD_FOLDER)
