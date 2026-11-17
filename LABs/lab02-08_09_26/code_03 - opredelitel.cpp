#include <stdio.h>

void main(){
float a11,a12,a21,a22,x1,x2,b1,b2,d,d1,d2;
scanf_s("%f", &a11);
scanf_s("%f", &a12);
scanf_s("%f", &a21);
scanf_s("%f", &a22);
scanf_s("%f", &b1);
scanf_s("%f", &b2);
d=a11*a22-a12*a21;
d1 = b1*a22-a12*a21;
d2 = b2*a22-a12*a21;
x1 = d1/d;
x2 = d2/d;
printf("%f %f = %f\n%f %f = %f\n",a11,a12,b1,a21,a22,b2);
printf("%f",x1);
scanf_s("%f",&d);
}
