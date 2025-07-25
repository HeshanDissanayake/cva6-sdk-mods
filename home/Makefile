# Compiler
CC = /home/heshds/working_dir/cva6-sdk/buildroot/output/host/bin/riscv64-buildroot-linux-gnu-gcc

# Compiler flags
CFLAGS = 

# All .c source files
SRCS = $(wildcard *.c)

# Executable names (removing .c)
BINS = $(SRCS:.c=)

# Default target: build all executables
all: $(BINS)

# Rule to build each executable from its .c file
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean rule
clean:
	rm -f $(BINS)
