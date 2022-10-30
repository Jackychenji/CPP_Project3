#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "Matrix.h"



void createMatrix(Matrix *m, int row, int column, char name)
{
    if (row <= 0 || column <= 0)
    {
        printf("Invalid input in row or column");
        exit(0);
    }

    m->row = row;
    m->column = column;
    m->name = name;
    m->data = (double **)malloc(sizeof(double *) * m->row);
    for (int i = 0; i < m->row; i++)
    {
        m->data[i] = (double *)malloc(sizeof(double) * m->column);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            m->data[i][j] = 0;
        }
    }
}

void InitialMatrix(Matrix *m)
{
    printf("Please initialize the Matrix %c\n", m->name);
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            scanf("%lf", &m->data[i][j]);
        }
    }
}

void ShowMatrix(Matrix *m)
{
    printf("Matrix %c is:\n", m->name);
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            printf("%lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

void CopyMatrix(Matrix *m, Matrix *n)
{
    if (m->data == NULL)
    {
        printf("Invalid source matrix.");
        exit(0);
    }

    n->row = m->row;
    n->column = m->column;
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->column; j++)
        {
            n->data[i][j] = m->data[i][j];
        }
    }
    printf("You have copied Matrix %c to Matrix %c\n", m->name, n->name);
}

void DeleteMatrix(Matrix *m)
{
    printf("You have deleted Matrix %c\n", m->name);
    for (int i = 0; i < m->row; i++)
    {
        free(m->data[i]);
        m->data[i] = NULL;
    }
    free(m->data);
    m->data = NULL;
}




int main()
{
    Matrix m, n;
    createMatrix(&m, 2, 2, 'm');
    InitialMatrix(&m);
    createMatrix(&n, 2, 4, 'n');
    InitialMatrix(&n);
    ShowMatrix(&n);
    CopyMatrix(&m, &n);
    Matrix total;
    total = addMatrix(m, n);
    ShowMatrix(&total);
    Matrix Subtraction;
    Subtraction = MinusMatrix(m, n);
    Matrix Multiply;
    Multiply = MultiplyMatrix(m, n);
    ShowMatrix(&Subtraction);
    ShowMatrix(&Multiply);
    DeleteMatrix(&m);
    addScalar(&n, 4);
    ShowMatrix(&n);
    MinusScalar(&n, 3);
    ShowMatrix(&n);
    printf("%d\n",MinimalValue(n));
    printf("%d\n",rank(n));
    ShowMatrix(&n);
    int deter;
    deter = det(n);
    printf("%d\n",deter);
    Matrix ni;
    ni = qiuni(n);
    ShowMatrix(&ni);
}