void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    
    int or = 0, ap = 0;
    for (int i = 0; i < apples_count; i++)
    {
        if (apples[i] + a >= s && apples[i] + a <= t)
            ap++;
    }
    for (int i = 0; i < oranges_count; i++)
    {
        if (oranges[i] + b >= s && oranges[i] + b <= t)
            or++;
    }

    printf("%d\n", ap);
    printf("%d\n", or);
}
