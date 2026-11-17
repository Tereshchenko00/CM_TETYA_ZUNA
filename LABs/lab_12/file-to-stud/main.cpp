

#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct stud{
    int ns;
    int m;
    float *ocen;
    float *bal;
    int f2,f5;
};

stud *readstud(char *, int *);


int main(void){
    stud *z; int i,j,k,n,m;
    ifstream f;
    f = ifstream("data.txt");
    z= readstud("data.txt", &n);
    for (i = 0; i < n; i++){
        cout<<z[i].ns<<" ";
        cout<<z[i].m<<" ";
        for(j=0;j<z[i].m;j++)
            cout<<z[i].ocen[j]<<" ";
        cout<<"\n";
    }
    
    /*f >> n;
    z = new pointf[n];
    for (i = 0; i < n; i++)
        f >> z[i].x >> z[i].y;
    f.close();
    */

}

stud *readstud(char *name, int *n1){
    stud *z;
    int i, j, n;
    ifstream f;
    f = ifstream(name);
    f >> n;
    z = new stud[n];
    for (i = 0; i < n; i++){
        f>>z[i].ns;
        f>>z[i].m;
        z[i].ocen=new float[z[i].m];
        for(j=0;j<z[i].m;j++)
            f>>z[i].ocen[j];
    }
    *n1=n;
    f.close();
    return z;
}
