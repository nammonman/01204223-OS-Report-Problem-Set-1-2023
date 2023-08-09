#include <stdio.h>
#include <stdlib.h>

int glob_var1 = 0;
int glob_var2 = 0;
int glob_var3 = 0;

int some_function(int input) {
    int some_function_var = input + 1;
    int output = input;
    return output;
}

int main() {
    int a = 55;
    int*b = (int*)malloc(a*sizeof(int));
    
}