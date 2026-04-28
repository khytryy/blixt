CC      := g++
CFLAGS  := -Wall -Wextra -g -O2 -I include -I external/ftxui/include -MMD -MP

SRC_DIR := src
OBJ_DIR := obj
TARGET  := blixt

SRCS    := $(shell find $(SRC_DIR) -name "*.cpp")
INC     := $(shell find include -name "*.h") $(shell find external/ftxui/include -name "*.h")
OBJS    := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "     LD $@"
	@$(CC) $(OBJS) -o $@ -L external/ftxui/build -lftxui-component -lftxui-dom -lftxui-screen -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "     CC $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET) build

install:
	@echo "Installing..."
	@cp blixt /usr/local/bin/blixt

format:
	@echo "Formatting code..."
	@clang-format -i $(SRCS) $(INC)

deps:
	cd external/ftxui && mkdir -p build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j$(nproc)

.PHONY: all clean install format deps

-include $(DEPS)