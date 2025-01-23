#include <stdio.h>
struct Tuple
{
    int row;
    int col;
    int value;
};
int i, j;
void read_matrix(int rows, int cols, int mat[10][10])
{
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}
void mat_to_tup(struct Tuple tup[10], int mat[10][10], int rows, int cols)
{
    int k = 1;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (mat[i][j] != 0)
            {
                tup[k].row = i;
                tup[k].col = j;
                tup[k].value = mat[i][j];
                k++;
            }
        }
    }
    tup[0].row = rows;
    tup[0].col = cols;
    tup[0].value = k - 1;
}
void display_tup(struct Tuple tup[10])
{
    int rows = tup[0].row;
    int cols = tup[0].col;
    for (i = 0; i <= tup[0].value; i++)
    {
        printf("%d\t%d\t%d\n", tup[i].row, tup[i].col, tup[i].value);
    }
}
void transpose(struct Tuple tup[10], struct Tuple tup2[10])
{
    tup2[0].row = tup[0].col;
    tup2[0].col = tup[0].row;
    tup2[0].value = tup[0].value;
    int mat[10][10], n = tup[0].value;
    int k = 1;
    for (i = 0; i < tup[0].col; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (tup[j].col == i)
            {
                tup2[k].row = tup[j].col;
                tup2[k].col = tup[j].row;
                tup2[k].value = tup[j].value;
                k++;
            }
        }
    }
}
void add(struct Tuple tup1[10], struct Tuple tup2[10], struct Tuple tup3[10])
{
    int r1 = tup1[0].row, r2 = tup2[0].row, c1 = tup1[0].col, c2 = tup2[0].col;
    if ((r1 != r2) || (c1 != c2))
    {
        printf("Addition not possible");
    }
    else
    {
        printf("Sum:\n");
        int n1 = 1, n2 = 1, k = 1;
        tup3[0].row = r1;
        tup3[0].col = c1;
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                if ((tup1[n1].row == i) && (tup1[n1].col == j) && (tup2[n2].row == i) &&
                    (tup2[n2].col == j))
                {
                    tup3[k].row = i;
                    tup3[k].col = j;
                    tup3[k].value = tup1[n1].value + tup2[n2].value;
                    k++;
                    n1++;
                    n2++;
                }
                else if ((tup1[n1].row == i) && (tup1[n1].col == j))
                {
                    tup3[k].row = i;
                    tup3[k].col = j;
                    tup3[k].value = tup1[n1].value;
                    k++;
                    n1++;
                }
                else if ((tup2[n2].row == i) && (tup2[n2].col == j))
                {
                    tup3[k].row = i;
                    tup3[k].col = j;
                    tup3[k].value = tup2[n2].value;
                    k++;
                    n2++;
                }
            }
        }
        tup3[0].value = k - 1;
        display_tup(tup3);
    }
}
int main()
{
    int x, y, p, q;
    int mat1[10][10], mat2[10][10];
    struct Tuple tup1[10], tup2[10], tup3[10], tup_trans1[10], tup_trans2[10];
    printf("Enter the number of rows and columns of matrix1:\n");
    scanf("%d%d", &x, &y);
    printf("Enter the elements of matrix1\n");
    read_matrix(x, y, mat1);
    printf("Enter the number of rows and columns of matrix2:\n");
    scanf("%d%d", &p, &q);
    printf("Enter the elements of matrix2:\n");
    read_matrix(p, q, mat2);
    printf("Matrix1 in tuple form:\n");
    mat_to_tup(tup1, mat1, x, y);
    display_tup(tup1);
    printf("Transpose of matrix1:\n");
    transpose(tup1, tup_trans1);
    display_tup(tup_trans1);
    printf("Matrix2 in tuple form:\n");
    mat_to_tup(tup2, mat2, p, q);
    display_tup(tup2);
    printf("Transpose of matrix2:\n");
    transpose(tup2, tup_trans2);
    display_tup(tup_trans2);
    add(tup1, tup2, tup3);
    return 0;
}