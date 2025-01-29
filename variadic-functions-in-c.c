#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
int  sum (int count,...) {
    va_list args;
    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    
    return (sum);
}

int min(int count,...) {
    va_list args;
    va_start(args, count);
    int mi = va_arg(args, int);
    for (int i = 1; i < count; i++)
    {
        int tmp = va_arg(args, int);
        if (tmp < mi)
            mi = tmp;
    }
    
    return (mi);
}

int max(int count,...) {
    va_list args;
    va_start(args, count);
    int ma = va_arg(args, int);
    for (int i = 1; i < count; i++)
    {
        int tmp = va_arg(args, int);
        if (tmp > ma)
            ma = tmp;
    }
    
    return (ma);
}
