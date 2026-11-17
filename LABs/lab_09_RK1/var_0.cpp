#include <stdio.h>

void main (){
	int **a,*b;
	int i,j,k,n,m,t,imax,buf;
	n=7; m=3;
	int ac[]={7,4,9,12,7,6,8,
		5,2,19,5,15,22,100,
		99,88,3,0,-3,4,5};
	a=new int*[n];

	for(i=0;i<n;i++)
		a[i]=new int[m];

	for (i=0,k=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=ac[k++];

	printf("\nmatr\n");

	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	for (i=0,k=0;i<n;i++)
		for (j=0;j<m;j++)
			if (a[i][j]%2==0)
				k++;
	if (k>0)
		b=new int[k];

	for (i=0,k=0;i<n;i++)
		for (j=0;j<m;j++)
			if (a[i][j]%2==0)
				b[k++]=a[i][j];

	printf("\nmass b \n");

	for (i=0;i<k;i++)
		printf("%d ",b[i]);

	for(t=0;t<k-1;t++){
		for (i=t, imax=t; i<k; i++)
			if(b[i]>b[imax])
				imax=i;
		buf=b[imax];
		b[imax]=b[t];
		b[t]=buf;		
	}

	printf("\n\nsorted b \n");

	for (i=0;i<k;i++)
		printf("%d ",b[i]);

	for (i=0,k=0;i<n;i++)
		for (j=0;j<m;j++)
			if (a[i][j]%2==0)
				a[i][j]=b[k++];

	printf("\n\nmatr\n");

	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	scanf_s("%d ", &j);
}


