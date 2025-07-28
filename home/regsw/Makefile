# Compiler
export RISCV_CC = /opt/dev/riscv_linux_rv64g_regsw/bin/riscv64-unknown-linux-gnu-gcc
# Compiler flags
export RISCV_CFLAGS = --sysroot=/home/heshds/working_dir/cva6-sdk/buildroot/output/host/riscv64-buildroot-linux-gnu/sysroot

REGSW_COMPILER = ../../scripts/compile_linux.sh


# All .c source files
SRCS = $(wildcard *.c)

# Executable names (removing .c)
BINS = $(SRCS:.c=)

# Default target: build all executables
all: increment $(BINS)

# Rule to build each executable from its .c file
%: %.c
	$(REGSW_COMPILER) $< $@ 

# this updates a build counter that we can use to see whether the linux image has the latest changes
increment:
	@num=$$(cat build_number 2>/dev/null || echo 0); \
	new_num=$$((num + 1)); \
	echo $$new_num > build_number; \
	echo "Updated counter: $$new_num"

# Clean rule
clean:
	rm -f $(BINS)

clean-all:
	rm -r asm asm_injected regsw_obj LLVM
	rm -f $(BINS)

