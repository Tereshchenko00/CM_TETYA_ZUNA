#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct pointf{
	float x,y;
};

struct okr{
	pointf centr;
	float rad;
};

float rast(pointf,pointf);

pointf peres(okr,okr);


int main(void){
	pointf t0;
	okr *z;
	int i,j,k,n,m;

	n=3;
	z = new okr[n];
	
	for(i=0;i<n;i++){
		cin>>z[i].centr.x;
		cin>>z[i].centr.y;
		cin>>z[i].rad;
	}

	for(i=0;i<n;i++){
		cout<<"x="<<z[i].centr.x;
		cout<<" y="<<z[i].centr.y;
		cout<<" z="<<z[i].rad<<"\n";
	}
	t0 = peres(z[0],z[1]);

	cout<<t0.x<<"\n";
	cout<<t0.y<<"\n";

	cin>>i;
}

pointf peres(okr r1, okr r2){
	pointf r;
	float s;
	s=rast(r1.centr,r2.centr);
	if (s<=(r1.rad+r2.rad)){
		r.x=1;
		r.y=1;
	}
	else{
		r.x=0;
		r.y=0;
	}
	return r;
}

float rast(pointf t1,pointf t2){
	float r;
	r=sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
	return r;
}
