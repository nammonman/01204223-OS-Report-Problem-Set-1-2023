#include <stdio.h>
#include <time.h>
#include <stdarg.h>

double timedPrintf(const char *format, ...) {
    clock_t start = clock();
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    //printf("time taken for printf: %f seconds\n", timeTaken);
    return timeTaken;
}

double timedScanf(const char *format, ...) {
    clock_t start = clock();
    
    va_list args;
    va_start(args, format);
    vscanf(format, args);
    va_end(args);
    
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    //printf("time taken for scanf: %f seconds\n", timeTaken);
    return timeTaken;
}

int main() {
     clock_t start = clock();

    int n;
    printf("enter a number: ");
    double count = 0;

    clock_t end = clock();

    double preCount = (double)(end - start) / CLOCKS_PER_SEC;
    double scanfCount = timedScanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        count += timedPrintf("Ay, ay, ay, I'm your little butterfly Green, black and blue Make the colours in the sky %d \n",i+1);
    }

    printf("total scanf: %f seconds\n",scanfCount-preCount);
    printf("total printf: %f seconds",count);
    
    return 0;
}
