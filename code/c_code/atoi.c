#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
    uint8_t string[] = "874365";
    int value =  atoi((char*) string);

    printf("\nSome value: ");
    printf("%d", value);

    return 0;
}
