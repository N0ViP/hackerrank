int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int bob_score = 0, alice_score = 0;
    
    for (int i = 0; i < a_count; i++)
    {
        if (a[i] > b[i])
            alice_score++;
        else if (a[i] < b[i])
            bob_score++;
    }
    
    int *res = (int *) malloc(sizeof(int) * 2);
    if (!res)
        return (NULL);
    *result_count = 2;
    res[0] = alice_score;
    res[1] = bob_score;
    
    return (res);
}

