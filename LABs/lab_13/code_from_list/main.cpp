#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

void sort(char** slow1, int n) {
    int i, j = 1; char* buf;
    while (j) {
        j = 0;
        for (i = 0; i < n - 1; i++) {
            if (strcmp(slow1[i], slow1[i + 1]) > 0) {
                buf = slow1[i];
                slow1[i] = slow1[i + 1];
                slow1[i + 1] = buf; j = 1;
            }
        }
    }
}

int main(void) {
    int i, j, n=2;
    const int len = 10;
    const int len_strok = 3;
    char* buf; char mas_str[len_strok][len];
    buf = new char[30];
    ifstream f; f = ifstream("data.txt");    // выделяем память
    f >> n;
    char** slow1; slow1 = new char* [n];
    //for (i = 0; i < n; i++)        slow1[i] = new char[10];
    for (i = 0; i < n; i++) {
        f >> buf;
        slow1[i] = new char[strlen(buf) + 1];
        for (j = 0; j < strlen(buf); j++)
            slow1[i][j] = buf[j];
        slow1[i][j] = '\0';
    }
    f.close();

    for (i = 0; i < n; i++)
        std::cout << slow1[i] << endl;;
    buf = slow1[1]; //"ccc";
    for (i = 0; i < n; i++)
        if (strcmp(buf, slow1[i]) == 0)
            cout << i << " ";
/*
    j = 1;
    while (j) {
        j = 0;
        for (i = 0; i < n - 1; i++)
            if (strcmp(slow1[i], slow1[i + 1]) > 0) {
                buf = slow1[i];
                slow1[i] = slow1[i + 1];
                slow1[i + 1] = buf; j = 1;
            }
    }       */
    sort(slow1, n);
    std::cout << endl;
    for (i = 0; i < n; i++)
        std::cout << slow1[i] << endl;
//  char* names[] = {"aaa", "ddd"};       char* namesc[2] = {"aaa", "ddd"};
    cin >> j;
}
