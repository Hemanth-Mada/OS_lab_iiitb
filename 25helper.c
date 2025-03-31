/*    Program Number: 25
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: Support program for 25.c
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int dummy = 10; // Unused variable
    if (argc > 1) {
        printf("Helper received: '%s'\n", argv[1]); // Simple output
    } else {
        printf("No input given\n");
    }
    return 0;
}