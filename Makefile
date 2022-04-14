CC = gcc

CFLAGS = -c -g

INCLUDE	= ./header
SOURCE 	= ./src
OUT 	= ./out
BUILD	= ./build
BUILD_DIR= $(BUILD)/debug

defaults: debug

debug: out build_debug Dll comparar main linkar

out:
	@rm -rf $(OUT)
	mkdir -p $(OUT)

build_debug:
	@rm -rf $(BUILD)
	@mkdir -p $(BUILD_DIR)

Dll: $(SOURCE)/dll.c $(INCLUDE)/dll.h
	$(CC) -o $(OUT)/dll.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/dll.c

comparar: $(SOURCE)/comparar.c $(INCLUDE)/comparar.h
	$(CC) -o $(OUT)/comparar.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/comparar.c

main: $(SOURCE)/main.c
	$(CC) -o $(OUT)/main.o -I $(INCLUDE) $(CFLAGS) $(SOURCE)/main.c

linkar: $(OUT)
	$(CC) -o $(BUILD_DIR)/main $(OUT)/*

