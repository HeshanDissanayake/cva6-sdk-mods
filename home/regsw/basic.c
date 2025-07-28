#include <stdint.h>
#include <stdio.h>
#include <unistd.h>


int main() {
      asm volatile ("add n20, n3, n4" ::);
      asm volatile ("li n6, 3" ::);
      asm volatile ("li n7, 6" ::);
    
      int result;
      asm volatile ("add %0, n6, n7" :"=r"(result):);
      printf("result %d\n", result);


    return 0;

}