#include <stdio.h>


struct pointf{
	float x,y;
};

struct stud{
	int NZ;
	float bal;
};

pointf sred_t(pointf*,int);


void main(){
	pointf *z,t0;
	stud *tz;
	int i,j,k,n,m;

	n=3;
	z= new pointf[n];
	tz=new stud[n];
	
	for(i=0;i<n;i++)
		scanf_s("%f %f", &z[i].x, &z[i].y);
		
	for(i=0;i<n;i++)
		printf("%f %f\n", z[i].x, z[i].y);

	t0=sred_t(z,n);
	printf("\n%f %f\n", t0.x, t0.y);
	scanf_s("%f",i);
}

pointf sred_t(pointf *a, int n){
	pointf t;
	int i;
	for(i=0,t.x=0,t.y=0;i<n;i++){
		t.x+=a[i].x;
		t.y+=a[i].y;
	}
	if(n!=0){
		t.x/=n;
		t.y/=n;
	}
	return t;
}