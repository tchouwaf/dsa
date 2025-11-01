CC = gcc
CCFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
INCLUDES = -Ialgorithm/include -Idata_structure/include

SRC_ALGO = $(wildcard algorithm/src/*.c)
SRC_DATA = $(wildcard data_structure/src/*.c)
SRC_MAIN = $(wildcard main/*.c)
SRC      = $(SRC_ALGO) $(SRC_DATA) $(SRC_MAIN)

BIN_ALGO = algorithm/bin
BIN_DATA = data_structure/bin

OBJ_ALGO = $(SRC_ALGO:algorithm/src/%.c=$(BIN_ALGO)/%.o)
OBJ_DATA = $(SRC_DATA:data_structure/src/%.c=$(BIN_DATA)/%.o)
OBJ_MAIN = $(SRC_MAIN:main/%.c=main/%.o)
OBJ      = $(OBJ_ALGO) $(OBJ_DATA) $(OBJ_MAIN)

TARGET = bin/genspace_exec

$(TARGET): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $@

$(BIN_ALGO)/%.o: algorithm/src/%.c
	@mkdir -p $(BIN_ALGO)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BIN_DATA)/%.o: data_structure/src/%.c
	@mkdir -p $(BIN_DATA)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

main/%.o: main/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)
