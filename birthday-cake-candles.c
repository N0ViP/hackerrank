int birthdayCakeCandles(int candles_count, int* candles) {
    int  max = 0, res = 0;

    for (int i = 0; i < candles_count; i++)
    {
        if (candles[i] > max)
            max = candles[i];
    }
    
    for (int i = 0; i < candles_count; i++)
    {
        if (candles[i] == max)
            res++;
    }
    
    return (res);
}
