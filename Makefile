CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iinclude -IC:/msys64/ucrt64/include
LDFLAGS = -LC:/msys64/ucrt64/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = CzzRenderer
BUILD_DIR = build

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	-del $(TARGET).exe 2>nul
	-if exist $(subst /,\,$(BUILD_DIR)) rmdir /s /q $(subst /,\,$(BUILD_DIR))

run: all
	.\$(TARGET).exe

.PHONY: all clean run
