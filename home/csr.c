#include <stdint.h>
#include <stdio.h>

static inline uint32_t read_csr(void) {
    uint32_t value;
    asm volatile ("csrr %0, 0x800" : "=r"(value));
    return value;
}

static inline void write_csr(uint32_t value) {
    asm volatile ("csrw 0x800, %0" :: "r"(value));
}

int main() {
    
    uint32_t val = read_csr();
    printf("csr --> 0x%08x\n", val);
    write_csr(0x1234);

    val = read_csr();
    printf("csr --> 0x%08x\n", val);
    return 0;
}