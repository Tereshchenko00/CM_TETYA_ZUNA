#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct pointf
{
    float x, y;
};

pointf *readfile(char *, int &); // Прототип функции чтения

int main(void){
    pointf *z; // Указатель на массив точек
    int n, i;  // n - количество точек, i - счетчик
    ifstream f;
    f = ifstream("data.txt"); // Открытие файла (дублируется в функции)
    z = readfile("data.txt", n); // Чтение: z получает массив, n - количество
    for (i = 0; i < n; i++) // Вывод всех точек на экран
        cout<<z[i].x<<" "<<z[i].y<<"\n";

    /*f >> n;
    z = new pointf[n];
    for (i = 0; i < n; i++)
        f >> z[i].x >> z[i].y;
    f.close();
    */
}

pointf *readfile(char *name, int &n){
    pointf *z;
    int i, j;
    ifstream f;
    f = ifstream(name); // Открытие файла по имени
    f >> n;             // Считываем количество точек (меняет n в main)
    z = new pointf[n];  // Выделяем память под массив
    for (i = 0; i < n; i++) // Чтение координат из файла
        f>>z[i].x>>z[i].y;
    f.close();          // Закрытие файла
    return z;           // Возврат указателя на массив
}
