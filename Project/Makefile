### CONFIGURATION

# PROJECT CONFIGURATION

BUILD_FOLDER        = .Build
SRC_FOLDER          = src
TEST_FOLDER         = test
EXEC                = VoyageVoyage

MAIN_TEST_MODULE    = Main
MODULES_NAME        = Catalog SearchEngine ComposedPath SimplePath PathArray Path

# COMPILATION CONFIGURATION

CC                  =g++
CC_FLAGS            =-Wall -Werror -pedantic -std=c++11
CC_DEBUG_FLAGS      =-g -DMAP


### INITIALISATION

# GET FILES

object_files    := $(addprefix $(BUILD_FOLDER)/,$(MODULES_NAME))
object_files    := $(BUILD_FOLDER)/$(MAIN_TEST_MODULE).o $(foreach object,$(object_files),$(object).o)

modules_folders := $(foreach folder,$(MODULES_NAME),$(SRC_FOLDER)/$(folder))

### RULES

# MAIN RULES

all: $(BUILD_FOLDER)/$(EXEC)
all: clean

debug: clean
debug: $(BUILD_FOLDER)/$(EXEC)
debug: CC_FLAGS += $(CC_DEBUG_FLAGS)

.SILENT:

# BUILD MAIN EXEC

vpath %.cpp $(modules_folders) $(SRC_FOLDER)

$(BUILD_FOLDER)/$(EXEC): $(object_files)
	@echo "building executable : $@ with [$^]\n"
	$(CC) $(CC_FLAGS) -o $@ $^ -lm

$(BUILD_FOLDER)/%.o: %.cpp
	@echo "building : [$@ $<]"
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "builded  : [$@ $<]\n"

### OTHER

clear : clean
clean :
	@echo "clean all file"
	rm -f .Build/*.o

init :
	mkdir .Build/