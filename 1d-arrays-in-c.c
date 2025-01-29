#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, res = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    if (!arr)
        return (1); 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        res += arr[i];
    }
    
    printf("%d\n", res);
    return 0;
}
