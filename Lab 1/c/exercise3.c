#include <stdio.h>
#include <stdlib.h> // for atoi()

int main(int argc, char *argv[]) {
    int product = 1;
    if (argc == 1) {
        printf("\nNo arguments passed!\n");
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        product *= atoi(argv[i]); // Convert string to integer
    }
    printf("Product: %d\n", product); // Correct printf usage
    return 0;
}
