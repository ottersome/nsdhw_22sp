TARGETNAME = _vector
TARGET = $(addprefix $(TARGETNAME),$(shell python3-config --extension-suffix))
OUTPUT_REDIRECTION ?=  result.txt
#Comment
BUILD_DIR ?= ./
SRC_DIR ?= ./
#INC_DIRS := $(shell python3 -m pybind11 --includes) $(shell python3-config --extension-suffix)
INC_DIRS := -I./ $(shell python3-config --includes)
OBJ_DIR ?= ./
#Comment to force change in git

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
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean, run, check, default
default: $(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*.so $(BUILD_DIR)/$(TARGET) result.txt || true

#Pytest
test: 
	python3 -m pytest

# This phony should redirect output to result.txt
check:
	chmod +x $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET) > $(OUTPUT_REDIRECTION)
