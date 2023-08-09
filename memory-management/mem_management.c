#include <stdio.h>
#include <stdlib.h>

int glob_var1 = 1;
int glob_var2 = 2;
int glob_var3 = 3;

void dangerous_function(int*b) {
    printf("recursive malloc until stack overflow");
    b = (int*)malloc(999*sizeof(int));
    dangerous_function(b);
}

void some_function(int i) {
    printf("stack depth %d\n",i);
    if (i < 5)
    {
        printf("address of i variable in some_function: %p\n",&i);
        some_function(i+1);
    }
}

int main() {
    int*b = (int*)malloc(sizeof(int));
    printf("global var 1 address: %p\n", &glob_var1);
    printf("global var 2 address: %p\n", &glob_var2);
    printf("global var 3 address: %p\n", &glob_var3);
    printf("local var b address: %p\n", b);
    for (int i = 1; i < 5; i++)
    {
        b = (int*)malloc(sizeof(int));
        printf("address b after malloc %d more times: %p\n", i, b);
    }
    
    some_function(1);
    free(b);
    return 0;
}