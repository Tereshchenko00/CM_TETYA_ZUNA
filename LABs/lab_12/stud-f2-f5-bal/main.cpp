#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct stud{
    int ns;
    int m;
    float *ocen;
    float bal;
    int f2,f5;
};

stud *readstud(char *, int *);

void form(stud &);

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
    
    /*
    for (i = 0; i < n; i++){
        z[i].bal=0;
        z[i].f2=0;
        z[i].f5=0;
        for(j=0;j<z[i].m;j++){
            if (z[i].ocen[j]==2)
                z[i].f2+=1;
            if (z[i].ocen[j]==5)
                z[i].f5+=1;
            z[i].bal+=z[i].ocen[j];
        }
        z[i].bal/=z[i].m;
    */
    for (i = 0; i < n; i++){
        form(z[i]);

    }
    for (i = 0; i < n; i++){
        cout<<i<<": "<<z[i].f2<<" ";
        cout<<z[i].f5<<" ";
        cout<<z[i].bal<<"\n";
        
    }

}
void form(stud &z){
    int j;
        z.bal=0;
        z.f2=0;
        z.f5=0;
        for(j=0;j<z.m;j++){
            if (z.ocen[j]==2)
                z.f2+=1;
            if (z.ocen[j]==5)
                z.f5+=1;
            z.bal+=z.ocen[j];
        }
        z.bal/=z.m;
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
