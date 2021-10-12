# initialize variables
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# Targets all files ending with ".c"
C_SRCS := \
$(wildcard *.c)

# Targets all files ending with ".h"
HDRS := \
$(wildcard *.h)

# swaps ".c" endings with ".o" and stores resulting list of strings in OBJS
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
# filters out items ending in .o, so that they don't get re-processed
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# default target
all: build
	@echo "All Done!"
# Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# special build rule, % represents a wildcard that gets replaced for each matching filename
# Catch root directory src files 
bin/%.o: %.c $(HDRS) 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Catch all nested directory files
bin/%.o: src/%.c$(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# removes targeted files
clean: 
	rm -f $(TARGET)
	rm -rf bin

# target which runs build when we type make run
run: build
	@./$(TARGET) doggoP6WComment.ppm out.txt EncodedImage.ppm

# Debugging tool which tells us which sources/headers are found
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"