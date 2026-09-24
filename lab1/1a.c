#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int N[20];
//out-of-bound write in dynamically allocated memory on the heap

int cwe_malloc(){
    char* p;
    p = malloc(sizeof(char));
    p[400000] = 'b';
    printf("%c",p[400000]);
    return 0;
}

//statically allocated memory
int cwe_static(){
    N[50000000] = 30;
    printf("%d",N[50000000]);
    return 0;
}

//out-of-bound write in automatic memory
int cwe_automatic(){
    int values[20];       // automatic storage
    values[50000000] = 30; // Out-of-bounds write
    return values[50000000];
}

int main(int argc, char** argv){
    //cwe_malloc();
    //cwe_static();
    cwe_automatic();
    return 0;
}