

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define CSR_REGSW_C 0x800



void regsw_c_loading_test(){
    int value;
    asm volatile ("regsw_c	x1, 0xff(x3)" ::);
    asm volatile ("csrr %0, 0x800" : "=r"(value));

    printf("regsw_c --> 0x%08x\n", value);
    // 11 00001   00 1111 1111
}

void regsw_mask_increment_test(){
    // regsw_c	x13, 0x3ee(x16)		# 100 00.0 110 1.01 111 101 110
                                    # 100 00.0 110 1.01 111 101 110
    uint32_t regsw_c;
    uint32_t rs1_bank;
    uint32_t rs2_bank;
    uint32_t rd_bank;

    asm volatile ("regsw_c	x13, 0x3ee(x16)" ::);
   
    asm volatile ("csrr %0, 0x800" : "=r"(regsw_c));
    printf("loaded regsw_c --> 0x%08x\n", regsw_c);
   
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x803" : "=r"(regsw_c));
    printf("mask - %d -- >", regsw_c);
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x803" : "=r"(regsw_c));  
    printf("mask - %d -- >", regsw_c);  
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x803" : "=r"(regsw_c));
    printf("mask - %d -- >", regsw_c);
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x803" : "=r"(regsw_c));
    printf("mask - %d -- >", regsw_c);
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x803" : "=r"(regsw_c));
    printf("mask - %d -- >", regsw_c);
    asm volatile ("csrr %0, 0x804" : "=r"(rs1_bank));
    printf("rs1 bank - %d", rs1_bank);
    asm volatile ("csrr %0, 0x805" : "=r"(rs2_bank));
    printf("| rs2 bank - %d", rs2_bank);
    asm volatile ("csrr %0, 0x806" : "=r"(rd_bank));
    printf("| rd bank - %d\n", rd_bank);

    asm volatile ("csrr %0, 0x800" : "=r"(regsw_c));
    printf("loaded regsw_c --> 0x%08x\n", regsw_c);
    

	// li	n4, 0
	// addi	t6, a2, 10
	// sub	n1, n1, t4
	// sub	n2, t5, n2
	// addw	n2, n1, n2
	// sgtz	n3, n2
	// negw	n1, n2

}



int main() {
    // regsw_c_loading_test();
    regsw_mask_increment_test();
    return 0;
}