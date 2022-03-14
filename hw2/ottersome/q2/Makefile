TARGETNAME = _vector
TARGET = $(addprefix $(TARGETNAME),$(shell python3-config --extension-suffix))
OUTPUT_REDIRECTION ?=  result.txt
#Comment
BUILD_DIR ?= ./
SRC_DIR ?= ./
INC_DIRS := $(shell python3 -m pybind11 --includes)
OBJ_DIR ?= ./

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS?=

# Comenting this one out because they python command above provide the -I prefix
#INC_FLAGS = $(addprefix -I,$(INC_DIRS))
#CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++11 -DDEBUG -g #-O0 -v -da -Q
#CPPFLAGS ?= $(INC_DIRS) -std=c++11 -Werror -Wpedantic -Wall -fPIC 
CPPFLAGS ?= -O3 -Wall -shared -std=c++11 -fPIC $(INC_DIRS)

#Objects to executable
#$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	#$(CXX) $(OBJ_FILES) -o $@ $(LDFLAGS)

# Source files
#$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	#echo "For $@ This is the obj file ${SRC_FILES}" 
	#echo "WOrking with includes : ${INC_DIRS}"
	#$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
		
$(BUILD_DIR)/$(TARGET): $(SRC_DIR)/main.cpp
	echo "There are the inc dirs : ${INC_DIRS}"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean, run, check, default
default: $(BUILD_DIR)/$(TARGET)

clean:
	rm -r $(OBJ_DIR)/*.so $(BUILD_DIR)/$(TARGET) result.txt

#Im guessig this bad boid runs our already compiled executable
test: 
	pytest

# This phony should redirect output to result.txt
check:
	chmod +x $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET) > $(OUTPUT_REDIRECTION)
