#!/bin/bash

INJECTOR_PATH="/home/heshds/working_dir/regws-instruction-injection"


# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <file_path> <output>"
  exit 1
fi

# Extract the file name without the directory path
filename=$(basename "$1")

# Remove the file extension
basename=$(echo "$filename" | cut -d '.' -f 1)

# List of folders to check/create
FOLDERS=(
  "asm"
  "asm_injected"
  "LLVM"
  "regsw_obj"
)

# Loop through each folder and check if it exists
for FOLDER in "${FOLDERS[@]}"; do
  if [ ! -d "$FOLDER" ]; then
    echo "Folder not found. Creating: $FOLDER"
    mkdir -p "$FOLDER"
  else
    echo "Folder already exists: $FOLDER"
  fi
done


/home/heshds/working_dir/llvm-project/output-regsw/bin/clang --sysroot=/home/heshds/working_dir/cva6-sdk/buildroot/output/host/riscv64-buildroot-linux-gnu/sysroot/usr/ --gcc-toolchain=/home/heshds/working_dir/cva6-sdk/buildroot/output/host/riscv64-buildroot-linux-gnu/ -O3 -S  -emit-llvm --target=riscv64  -march=rv64g  $1 -o LLVM/${basename}_extra.ll

/home/heshds/working_dir/llvm-project/output-regsw/bin/llc -O3  --march=riscv64 -mcpu=generic-rv64 -mattr=+d  LLVM/${basename}_extra.ll -o asm/${basename}_extra.S

python3 "$INJECTOR_PATH/inject.py" asm/${basename}_extra.S "$INJECTOR_PATH/encoding.json" asm_injected/${basename}_exReg_Inj.S

# /opt/dev/riscv_linux_rv64g_regsw/bin/riscv64-unknown-linux-gnu-gcc -static -c -O3  -nostdlib -nostartfiles -march=rv64g_zba_zbb_zbs_zbc -mabi=lp64d asm_injected/${basename}_exReg_Inj.S -o regsw_obj/${basename}_extra.o
$RISCV_CC $RISCV_CFLAGS asm_injected/${basename}_exReg_Inj.S -o $2

