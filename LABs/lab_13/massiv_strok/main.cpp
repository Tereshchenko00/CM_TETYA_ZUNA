#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void){
    char **slova; int i,j,n,m;
    int lens;
    lens=50;
    ifstream f;
    f=ifstream("data.txt");
    f>>n;
    slova=new char *[n];
    for (i=0;i<n;i++)
        slova[i]=new char[lens];
    for (i=0;i<n;i++)
        f>>slova[i];
    f.close();
    for (i=0;i<n;i++)
        cout<<slova[i];
}
