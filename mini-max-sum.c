void miniMaxSum(int arr_count, int* arr) {
    long long min = LLONG_MAX;
    long long max = 0;
    long long tmp = 0;

    for (int i = 0; i < arr_count; i++)
    {
        tmp = 0;
        for (int j = 0; j < arr_count; j++)
        {
            if (j != i)
                tmp += arr[j];
        }
        
        if (min > tmp)
            min = tmp;
        if (max < tmp)
            max = tmp;
    }
    
    printf("%lld %lld\n", min, max);
}

