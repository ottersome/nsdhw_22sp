TARGET ?= main
#Comment
BUILD_DIR ?= ./
SRC_DIR ?= ./
INC_DIRs ?= ./
OBJ_DIR ?= ./

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS=

INC_FLAGS = $(addprefix -I,$(INC_DIRS))
#CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -std=c++11 -DDEBUG -g #-O0 -v -da -Q
CPPFLAGS ?= $(INC_FLAGS) -std=c++11 

#Objects to executable
$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $@ $(LDFLAGS)

# Source files
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	echo "For $@ This is the obj file ${SRC_FILES}" 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
		

.PHONY: clean, run, check, default
default: run

clean:
	rm -r $(OBJ_DIR)/%.cpp

run: $(BUILD_DIR)/$(TARGET)
	echo "Executing the default target"

check:
	echo "I dont know what this should do"
