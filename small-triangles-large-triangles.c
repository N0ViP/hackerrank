#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(triangle tr)
{
    double P = (tr.a + tr.b + tr.c) / 2.0;
    double S = sqrt(P * (P - tr.a) * (P - tr.b) * (P - tr.c));

    return (S);
}

void sort_by_area(triangle* tr, int n) {
	for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (area(tr[i]) > area(tr[j]))
            {
                triangle swp = tr[i];
                tr[i] = tr[j];
                tr[j] = swp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
