#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int main()
{
string x;
char* y;
int p=1;

for(int j=0;x.length()<=5400000;j++)
{sprintf(y,"%d",j) ;
//itoa (j,y,10);
x+=string(y);

}
int x1,x2,x3,x4,x5,x6,x7;
x1=1;
x2=1;
x3=x[100]-'0';
x4=x[1000]-'0';
x5=x[10000]-'0';
x6=x[100000]-'0';
x7=x[1000000]-'0';

cout<<x3*x4*x5*x6*x7;

//cout<<x[449999];
  return 0;
}
