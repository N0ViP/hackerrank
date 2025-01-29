void staircase(int n) {
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (j > i)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
