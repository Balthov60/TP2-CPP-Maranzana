### CONFIGURATION

# PROJECT CONFIGURATION

BUILD_FOLDER        = .Build
SRC_FOLDER          = src
TEST_FOLDER         = test
EXEC                = VoyageVoyage

MAIN_TEST_MODULE    = Main
MODULES_NAME        = Catalog SearchEngine ComposedPath SimplePath PathArray Path
MODULES_NAME_TEST   = SearchEngine ComposedPath SimplePath PathArray Path

# COMPILATION CONFIGURATION

CC                  =g++
CC_FLAGS            =-Wall -Werror -pedantic -std=c++11
CC_DEBUG_FLAGS      =-g -DMAP


### INITIALISATION

# GET FILES

object_files    := $(addprefix $(BUILD_FOLDER)/,$(MODULES_NAME))
test_o_files    := $(addprefix $(BUILD_FOLDER)/,$(MODULES_NAME_TEST))


ifneq (,$(findstring test,$(MAKECMDGOALS)))
	test_file       := $(lastword $(MAKECMDGOALS))
endif

object_files    := $(BUILD_FOLDER)/$(MAIN_TEST_MODULE).o $(foreach object,$(object_files),$(object).o)
test_o_files    := $(BUILD_FOLDER)/$(test_file).o $(foreach object,$(test_o_files),$(object).o)

modules_folders := $(foreach folder,$(MODULES_NAME),$(SRC_FOLDER)/$(folder))
test_folders    := $(foreach folder,$(MODULES_NAME),$(TEST_FOLDER)/$(folder))


### RULES

# MAIN RULES

all: clean
all: $(BUILD_FOLDER)/$(EXEC)

debug: clean
debug: CC_FLAGS += $(CC_DEBUG_FLAGS)
debug: $(BUILD_FOLDER)/$(EXEC)

debug-test: test-debug

test-debug: clean
test-debug: CC_FLAGS += $(CC_DEBUG_FLAGS)
test-debug: $(test_file)

test: clean
test: $(test_file)

.SILENT:

# BUILD MAIN EXEC

vpath %.cpp $(modules_folders) $(test_folders) $(SRC_FOLDER) $(TEST_FOLDER)

$(BUILD_FOLDER)/$(EXEC): $(object_files)
	@echo "building executable : $@ with [$^]\n"
	$(CC) $(CC_FLAGS) -o $@ $^ -lm
	@echo "building done."

# BUILD TESTS   # UNABLE TO BUILD ONLY USEFULL OBJECY FOR TEST

$(test_file) : $(test_o_files)
	@echo "building Test : $@"
	$(CC) $(CC_FLAGS) -o $(BUILD_FOLDER)/$@ $^ -lm
	@echo "building Test : done.\n"

# BUILD OBJECTS

$(BUILD_FOLDER)/%.o: %.cpp
	@echo "building : [$@ $<]"
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo "builded  : [$@ $<]\n"


### OTHER

clear : clean
clean :
	@echo "Clean all objects file"
	rm -f .Build/*.o

clean-all :
	@echo "Clean all"
	rm -f .Build/*

init :
	mkdir .Build/
