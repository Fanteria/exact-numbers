CXX = g++
CXXFLAGS = -g -Wall -Werror -pedantic --std=c++2a 
#CXXLINKFLAGS =

SRC = src
BIN = bin
TEST = test
TARGET = exact-numbers
 
.PHONY: build
build: $(BIN)/$(TARGET)

.PHONY: run
run: $(BIN)/$(TARGET)
	$(BIN)/$(TARGET) convert -s $(TEST) -t 4

.PHONY: debug
debug: $(BIN)/$(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BIN)/$(TARGET) -s $(TEST)

.PHONY: clean
clean:
	rm -rf $(BIN)

# $^ all rules for dependency (after :)
# $< first parametr of dependency (before :)
# $@ target of rule (before :)
$(BIN)/$(TARGET): $(BIN)/main.o
	@mkdir -p $(BIN)
	$(CXX) $(CXXLINKFLAGS) $^ -o $@

$(BIN)/%.o: $(SRC)/%.cpp
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN)/main.o: $(SRC)/main.cpp
