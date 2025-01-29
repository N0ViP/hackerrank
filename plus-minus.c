void plusMinus(int arr_count, int* arr) {
    int positive_nums = 0, nigative_nums = 0, zero = 0;
    
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > 0)
            positive_nums++;
        else if (arr[i] < 0)
            nigative_nums++;
        else
            zero++;
    }
    
    printf("%f\n", (float) positive_nums / arr_count);
    printf("%f\n", (float) nigative_nums / arr_count);
    printf("%f\n", (float) zero / arr_count);
}
