long aVeryBigSum(int ar_count, long* ar) {
    long res = 0;
    
    for (int i = 0; i < ar_count; i++)
    {
        res += ar[i];
    }
    
    return (res);
}
