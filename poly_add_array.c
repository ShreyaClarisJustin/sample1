#include<stdio.h>
struct Poly
{
float coeff;
int exp;
} x[10], y[10], z[10];
void readPoly(struct Poly a[], int terms)
{
for (int i = 0; i < terms; i++)
{
printf("Enter the coefficient and exponent for the term %d: ", i + 1);
scanf("%f %d", &a[i].coeff, &a[i].exp);
}
}
int addPoly(int n, int m)
{
int i = 0, j = 0, k = 0;
while (i < n && j < m)
{
if (x[i].exp == y[j].exp)
{
z[k].coeff = x[i].coeff + y[j].coeff;
z[k].exp = x[i].exp;
i++, j++, k++;
}
else if (x[i].exp > y[j].exp)
{
z[k].coeff = x[i].coeff;
z[k].exp = x[i].exp;
i++, k++;
}
else
{
z[k].coeff = y[j].coeff;
z[k].exp = y[j].exp;
j++, k++;
}
}
while (i < n)
{
z[k].coeff = x[i].coeff;
z[k].exp = x[i].exp;
i++, k++;
}
while (j < m)
{
z[k].coeff = y[j].coeff;
z[k].exp = y[j].exp;
j++, k++;
}
return k;
}

void displayPoly(struct Poly b[], int terms)
{
for (int i = 0; i < terms; i++)
{
printf("%.2fx^%d", b[i].coeff, b[i].exp);
if(i != terms - 1)
{
printf("+");
}
}
printf("\n");
}
int main()
{
int n, m, k;
printf("Enter the number of terms of first expression: ");
scanf("%d", &n);
readPoly(x, n);
printf("Expression 1: ");
displayPoly(x, n);
printf("Enter the number of terms of second expression: ");
scanf("%d", &m);
readPoly(y, m);
printf("Expression 2: ");
displayPoly(y, m);
k = addPoly(n, m);
printf("Resultant expression: ");
displayPoly(z, k);
return 0;
}