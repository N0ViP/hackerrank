#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int i;
    for (i = 0; a[i] && b[i] == a[i]; i++) ;

    return ((a[i] - b[i] > 0) ? 1 : 0);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i;
    for (i = 0; a[i] && b[i] == a[i]; i++) ;

    return ((b[i] - a[i] > 0) ? 1 : 0);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int a_map[26] = {0};
    int b_map[26] = {0};
    int i = 0, ad = 0, bd = 0;
    
    while (a[i] && b[i])
    {
        a_map[a[i] - 'a'] = 1;
        b_map[b[i] - 'a'] = 1;
        i++;
    }
    while (a[i])
        a_map[a[i++] - 'a'] = 1;
    while (b[i])
        b_map[b[i++] - 'a'] = 1;
        
    i = 0;
    while (i < 26)
    {
        ad += a_map[i];
        bd += b_map[i];
        i++;
    }
    
    if (ad != bd)
    {
        return ((ad > bd) ? 1 : 0);
    }
    
    return (lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
    int a_len = strlen(a), b_len = strlen(b);
    if (a_len != b_len)
        return ((a_len > b_len) ? 1 : 0);
    else
        return (lexicographic_sort(a, b));
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (cmp_func(arr[i], arr[j]))
            {
                char* swp = arr[i];
                arr[i] = arr[j];
                arr[j] = swp;
            }
        }
    }
    
    
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
