#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct pointf
{
    float x, y;
};

// Прототип функции чтения матрицы из файла
int **readmatr(char *, int *,int *);


int main(void){
     
    int **b,n,m,i,j; // b - матрица, n - строки, m - столбцы
    ifstream f;
    f = ifstream("data.txt"); // Открытие файла (потом открывается заново в функции)
    
    // Вызов функции. n и m передаются по указателю, чтобы вернуть их значения в main
    b = readmatr("data.txt", &n,&m);
    
    // Вывод матрицы на экран
    for (i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<b[i][j]<<" ";
        cout<<"\n";
    }

    /* Закомментированный старый код
    f >> n;
    z = new pointf[n];
    for (i = 0; i < n; i++)
        f >> z[i].x >> z[i].y;
    f.close();
    */

}

// Функция для чтения матрицы из файла
int **readmatr(char * name, int *n1,int *m1){
    int **a, i, j,n,m;
    ifstream f;
    f = ifstream(name); // Открываем файл
    f >> n >> m;        // Читаем размерность: n (строки) и m (столбцы)
    
    a = new int*[n];    // Выделяем массив указателей (строки)
    for (i = 0; i < n; i++)
        a[i] = new int[m]; // Выделяем память под столбцы в каждой строке

    // Циклы для чтения элементов матрицы
    for (i = 0; i < n; i++)
        for(j=0;j<m;j++){
            f>>a[i][j];     // Читаем элемент
            *m1=m;          // Возвращаем количество столбцов в main (лишний раз в цикле)
            *n1=n;          // Возвращаем количество строк в main (лишний раз в цикле)
        }
    f.close();          // Закрываем файл
    return a;           // Возвращаем указатель на матрицу
}
