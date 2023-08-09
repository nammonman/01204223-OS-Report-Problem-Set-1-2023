#include <stdio.h>
#include <stdlib.h>

int glob_var1 = 1;
int glob_var2 = 2;
int glob_var3 = 3;

void some_function(int input, int**b) {
    int a = input;
    *b = (int*)malloc(sizeof(int));
    glob_var2 += 2;
    printf("stack address: %p\n", &a);
    printf("heap address: %p\n", b[input-1]);
    printf("global var 2 address: %p\n", &glob_var2);
    if(a < 30)
    some_function(a+1,b);
}

int main() {
    int*b = NULL;
    printf("global var 1 address: %p\n", &glob_var1);
    printf("global var 2 address: %p\n", &glob_var2);
    printf("global var 3 address: %p\n", &glob_var3);
    some_function(glob_var1,&b);
    free(b);
    return 0;
}