#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    char s1[16];
    char s2[16];

    printf("s1: ");
    for (size_t i = 0; i < sizeof s1; i++)
        printf("%02x ", (unsigned char)s1[i]);

    printf("\ns2: ");
    for (size_t i = 0; i < sizeof s2; i++)
        printf("%02x ", (unsigned char)s2[i]);
    printf("\n");

    char string[32];
    for (int i = 0; i<32; i++){string[i] = 'a';}

    memcpy(s1, string, sizeof( char ) * 32);

    printf("s1: ");
    for (size_t i = 0; i < sizeof s1; i++)
        printf("%02x ", (unsigned char)s1[i]);

    printf("\ns2: ");
    for (size_t i = 0; i < sizeof s2; i++)
        printf("%02x ", (unsigned char)s2[i]);
    printf("\n");

    return 0;
}