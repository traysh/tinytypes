TARGET = tinytype

CXX = g++
CXX_FLAGS = -g -O0 -Wall -Werror -Wfatal-errors
CXX_FILES = $(shell find -name '*.cpp')

.PHONY: all clean
all: $(TARGET)

clean:
	@rm $(shell find -name '*.o' $(dir $(TARGET)))
	@rm $(TARGET)

$(TARGET): $(CXX_FILES)
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp -o $(TARGET)
