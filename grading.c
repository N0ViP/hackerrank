 int ft_modify(int n)
 {
    int tmp = n;
    while (tmp % 5)
        tmp++;
    return ((tmp - n < 3) ? tmp : n);
 }
 
int* gradingStudents(int grades_count, int* grades, int* result_count) {
    for(int i = 0; i < grades_count; i++)
    {
        if (grades[i] < 38)
            continue;
        if (grades[i] % 5)
            grades[i] = ft_modify(grades[i]);
    }
    
    *result_count = grades_count;
    
    return (grades);
}
