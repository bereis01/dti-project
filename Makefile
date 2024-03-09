C = gcc # C Compiler
CXX = g++ # C++ Compiler
CXXFLAGS = -Wall # Flags

# Directories
DATA_DIR = ./data
INCLUDE_DIR = ./include
OBJ_DIR = ./obj
SRC_DIR = ./src
##

SRCS = $(wildcard $(SRC_DIR)/*.cpp) # Searches for all the .cpp files in (SRC_DIR) and lists them.
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS)) # Takes the text from (SRCS) and substitues the .cpp pattern with the .o pattern.
INCLUDES = $(wildcard $(INCLUDE_DIR)/*.hpp) # Searches for all the .hpp files in (INCLUDE_DIR) and lists them.

TARGET = dti # Executable name.

# Rules
all : main

main : $(TARGET)

$(TARGET) : $(OBJS) $(OBJ_DIR)/sqlite3.o
	$(CXX) $(FLAGS) $(OBJS) $(OBJ_DIR)/sqlite3.o -o $(TARGET)

$(OBJ_DIR)/sqlite3.o : $(SRC_DIR)/sqlite3.c $(INCLUDE_DIR)/sqlite3.h
	$(C) $(FLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(INCLUDES)
	$(CXX) $(FLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm $(OBJS) $(OBJ_DIR)/sqlite3.o $(TARGET)
##