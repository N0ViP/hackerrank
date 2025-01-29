int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int res, first_diagonal = 0, second_diagonal = 0;
    
    for (int i = 0; i < arr_rows; i++)
    {
        first_diagonal += arr[i][i];
    }
    int j = 0;
    for (int i = arr_rows - 1; i >= 0; i--)
    {
        second_diagonal += arr[j++][i];
    }
    
    return (abs(first_diagonal - second_diagonal));
}

