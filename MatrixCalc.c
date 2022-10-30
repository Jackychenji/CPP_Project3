#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include "Matrix.h"

Matrix addMatrix(Matrix m, Matrix n)
{
    if (m.row != n.row || m.column != n.column)
    {
        printf("Matrix %c and Matrix %c are not the same size.", m.name, n.name);
        exit(0);
    }
    Matrix total;
    createMatrix(&total, m.row, m.column, 'R');
    for (int i = 0; i < total.row; i++)
    {
        for (int j = 0; j < total.column; j++)
        {
            total.data[i][j] += m.data[i][j] + n.data[i][j];
        }
    }
    return total;
}

Matrix MinusMatrix(Matrix m, Matrix n)
{
    if (m.row != n.row || m.column != n.column)
    {
        printf("Matrix %c and Matrix %c are not the same size.", m.name, n.name);
        exit(0);
    }
    Matrix Subtraction;
    createMatrix(&Subtraction, m.row, m.column, 'R');
    for (int i = 0; i < Subtraction.row; i++)
    {
        for (int j = 0; j < Subtraction.column; j++)
        {
            Subtraction.data[i][j] += m.data[i][j] - n.data[i][j];
        }
    }
    return Subtraction;
}

void addScalar(Matrix *A, int a)
{
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->column; j++)
        {
            A->data[i][j] += a;
        }
    }
}

void MinusScalar(Matrix *A, int a)
{
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->column; j++)
        {
            A->data[i][j] -= a;
        }
    }
}

void MultiplyScalar(Matrix *A, int a)
{
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->column; j++)
        {
            A->data[i][j] *= a;
        }
    }
}

void DivideScalar(Matrix *A, int a)
{
    for (int i = 0; i < A->row; i++)
    {
        for (int j = 0; j < A->column; j++)
        {
            A->data[i][j] /= a;
        }
    }
}

Matrix MultiplyMatrix(Matrix m, Matrix n)
{
    if (m.row != n.column)
    {
        printf("Matrix %c and Matrix %c can't multiply.", m.name, n.name);
        exit(0);
    }
    Matrix Multiplication;
    createMatrix(&Multiplication, m.row, n.column, 'R');
    for (int i = 0; i < Multiplication.row; i++)
    {
        for (int j = 0; j < Multiplication.column; j++)
        {
            for (int k = 0; k < m.column; k++)
            {
                Multiplication.data[i][j] += m.data[i][k] * n.data[k][j];
            }
        }
    }
    return Multiplication;
}

int MinimalValue(Matrix m)
{
    if (m.data==NULL)
    {
        printf("Invalid input matrix.");
        exit(0);
    }
    int min = m.data[0][0];
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
        {
            if (min>m.data[i][j])
            {
                min = m.data[i][j];
            }
            
        }
    }
    return min;
}

int MaximalValue(Matrix m)
{
    if (m.data==NULL)
    {
        printf("Invalid input matrix.");
        exit(0);
    }
    
    int max = m.data[0][0];
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.column; j++)
        {
            if (max<m.data[i][j])
            {
                max = m.data[i][j];
            }
            
        }
    }
    return max;
}

Matrix transposeMatrix(Matrix n){
    Matrix m = addMatrix(n,n);
    Matrix temp = m;
    createMatrix(&m, m.column, m.row,'T');
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.column; j++){
            m.data[i][j] = temp.data[j][i];
        }
    }
    return m;
}

void transposeMatrix_change(Matrix *m){
    
    Matrix temp = *m;
    createMatrix(m, m->column, m->row,'T');
    for(int i = 0; i < m->row; i++){
        for(int j = 0; j < m->column; j++){
            m->data[i][j] = temp.data[j][i];
        }
    }
}

Matrix SwapRows(Matrix n, int i, int j){
    Matrix m = addMatrix(n,n);
    if (m.row<j||m.row<i||i<=0||j<=0)
    {
        printf("Invalid swap rows.");
        exit(0);
    }
    
    double temp;
    for(int k = 0; k < m.column; k++){
        temp = m.data[i][k];
        m.data[i][k] = m.data[j][k];
        m.data[j][k] = temp;
    }
    return m;
}

void SwapRows_change(Matrix *m, int i, int j){
    if (m->row<j||m->row<i||i<=0||j<=0)
    {
        printf("Invalid swap rows.");
        exit(0);
    }
    
    double temp;
    for(int k = 0; k < m->column; k++){
        temp = m->data[i][k];
        m->data[i][k] = m->data[j][k];
        m->data[j][k] = temp;
    }
}

Matrix SwapColumn(Matrix n, int i, int j){
    Matrix m = addMatrix(n,n);
    double temp;
    for(int k = 0; k < m.column; k++){
        temp = m.data[k][i];
        m.data[k][i] = m.data[k][j];
        m.data[k][j] = temp;
    }
    return m;
}

void SwapColumn_change(Matrix *m, int i, int j){
    double temp;
    for(int k = 0; k < m->column; k++){
        temp = m->data[k][i];
        m->data[k][i] = m->data[k][j];
        m->data[k][j] = temp;
    }
}

Matrix column_sub(Matrix n, int i, int j, double times){
    Matrix m = addMatrix(n,n);
    for(int k = 0; k < m.column; k++){
        m.data[k][i] -= m.data[k][j] * times;
        if(fabs(m.data[k][i]) < 0.00000001){
            m.data[k][i] = 0;
        }
    }
    return m;
}

void column_sub_change(Matrix *m, int i, int j, double times){
    for(int k = 0; k < m->column; k++){
        m->data[k][i] -= m->data[k][j] * times;
        if(fabs(m->data[k][i]) < 0.00000001){
            m->data[k][i] = 0;
        }
    }
}

Matrix Row_sub(Matrix n, int i, int j, double time){
    Matrix m = addMatrix(n,n);
    for(int k = 0; k < m.column; k++){
        m.data[i][k] -= m.data[j][k] * time;
        if(fabs(m.data[i][k]) < __FLT_EPSILON__){
            m.data[i][k] = 0;
        }
    }
    return m;
}

void Row_sub_change(Matrix *m, int i, int j, double time){
    for(int k = 0; k < m->column; k++){
        m->data[i][k] -= m->data[j][k] * time;
        if(fabs(m->data[i][k]) < 0.00000001){
            m->data[i][k] = 0;
        }
    }
}

Matrix Row_jieti(Matrix n){
    int i = 0;
    int j = 0;
    Matrix m = addMatrix(n,n);

    if(m.row < m.column){
        m = transposeMatrix(m);
    }
    while(i < m.row && j < m.column){
        if(m.data[i][j] != 0){
            double divisor = m.data[i][j];
            for(int k = j; k < m.column; k++){
                m.data[i][k] /= divisor;
                if(fabs(m.data[i][k]) < 0.00000001){
                    m.data[i][k] = 0;
                }
            }
            for(int k = i + 1; k < m.row; k++){
                m = Row_sub(m, k, i, m.data[k][j]);
            }
            i++;
            j++;
        }
        else{
            int k;
            for(k = i + 1; k < m.row; k++){
                if(m.data[k][j] != 0){
                    break;
                }
            }
            if(k >= m.row){
                j++;
                continue;
            }
            m = SwapRows(m, i, k);
            double divisor = m.data[i][j];
            for(int l = j; l < m.column; l++){
                m.data[i][l] /= divisor;
                if(fabs(m.data[i][l]) < 0.00000001){
                    m.data[i][l] = 0;
                }
            }
            for(int l = i + 1; l < m.row; l++){
                m = Row_sub(m, l, i, m.data[l][j]);
            }
            i++;
            j++;
        }
    }
    return m;
}
 
void Row_jieti_change(Matrix *m){
    int i = 0;
    int j = 0;
    
    if(m->row < m->column){
        transposeMatrix_change(m);
    }
    while(i < m->row && j < m->column){
        if(m->data[i][j] != 0){
            double divisor = m->data[i][j];
            for(int k = j; k < m->column; k++){
                m->data[i][k] /= divisor;
                if(fabs(m->data[i][k]) < 0.00000001){
                    m->data[i][k] = 0;
                }
            }
            for(int k = i + 1; k < m->row; k++){
                Row_sub_change(m, k, i, m->data[k][j]);
            }
            i++;
            j++;
        }
        else{
            int k;
            for(k = i + 1; k < m->row; k++){
                if(m->data[k][j] != 0){
                    break;
                }
            }
            if(k >= m->row){
                j++;
                continue;
            }
            SwapRows_change(m, i, k);
            double divisor = m->data[i][j];
            for(int l = j; l < m->column; l++){
                m->data[i][l] /= divisor;
                if(fabs(m->data[i][l]) < 0.00000001){
                    m->data[i][l] = 0;
                }
            }
            for(int l = i + 1; l < m->row; l++){
                Row_sub_change(m, l, i, m->data[l][j]);
            }
            i++;
            j++;
        }
    }
}

int rank(Matrix m){
    m = Row_jieti(m);
    int i = 0; 
    int j = 0; 
    while(i < m.row && j < m.column){
        if(m.data[i][j] == 0){
            break;
        }
        i++;
        j++;
    }
    return i;
}
 
int Nixu_number(int *array, int n){
    int nixu = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(array[i] > array[j]){
                nixu++;
            }
        }
    }
    return nixu;
}
 

int find_if_exist(int *array, int n, int value){
    for(int i = 0; i < n; i++){
        if(value == array[i]){
            return 1;
        }
    }
    return 0;
}
 
void execute(double *value, Matrix m, int i, int j, int *column){
    if(i == m.row){
        double temp = 1;
        for(int k = 0; k < m.row; k++){
            temp = temp * m.data[k][column[k]];
        }
        int Nixu_num = Nixu_number(column, m.row);
        if (Nixu_num%2==0)
        {
            *value = *value + temp;
        }else *value = *value - temp;
        
    }
    for(int p = 0; p < m.column; p++){
        if(!find_if_exist(column, i, p)){
            column[i] = p;
            execute(value, m, i + 1, 0, column);
        }  
    }
}
 
double det(Matrix m){
    if(m.row != m.column){
        printf("The matrix is not a square matrix");
        exit(0);
    }
    double value = 0;
    int *column = (int *)malloc(sizeof(int)*m.row); 
    for(int k = 0; k < m.row; k++){
        column[k] = 0;
    }
    for(int k = 0; k < m.column; k++){
        column[0] = k; 
        execute(&value, m, 1, 0, column);       
    }
    return value;
}
 
double yuzishi(Matrix m, int i, int j){
    if(m.row != m.column){
        printf("The matrix is not a square matrix");
        exit(0);
    }
    Matrix rest;
    createMatrix(&rest, m.row - 1, m.column - 1,'Y');
    for(int a = 0; a < rest.row; a++){
        for(int b = 0; b < rest.column; b++){
            if(a < i && b < j){
                rest.data[a][b] = m.data[a][b];
            }
            else if(a < i && b >= j){
                rest.data[a][b] = m.data[a][b + 1];
            }
            else if(a >= i && b < j){
                rest.data[a][b] = m.data[a + 1][b];
            }
            else if(a >= i && b >= j){
                rest.data[a][b] = m.data[a + 1][b + 1];
            }
        }
    }
    return det(rest);
}
 
double algebraic_yuzishi(Matrix m, int i, int j){ 
    if ((i+j)%2==0)
    {
        return yuzishi(m, i, j);
    }else{
        return yuzishi(m, i, j)*(-1);
    }
     
}
 
Matrix qiuni(Matrix m){
    Matrix Nijuzhen;
    createMatrix(&Nijuzhen, m.row, m.column,'N');
    for(int i = 0; i < Nijuzhen.row; i++){
        for(int j = 0; j < Nijuzhen.column; j++){
            Nijuzhen.data[i][j] = algebraic_yuzishi(m, j, i) / det(m);
        }
    }
    return Nijuzhen;
}
