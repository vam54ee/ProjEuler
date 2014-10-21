#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
int maxi=0;
int **a=new int*[15];

void grid(int x,int y,int sum)
{
if(x==14)
{
sum=sum+a[x][y];
if(maxi<sum)
maxi=sum;
}
else
{
grid(x+1,y,sum+a[x][y]);
grid(x+1,y+1,sum+a[x][y]);
}
}

int main()
{
int b[]={75};
a[0]=b;
  int bb[]={95,64};
a[1]=bb;
 int bbb[]={17,47,82};
a[2]=bbb;
int bbbb[]={18,35,87,10};
a[3]=bbbb;
 int c[]={20,4,82,47,65};
a[4]=c;
 int cc[]={19,1,23,75,3,34};
a[5]=cc;
 int ccc[]={88,2,77,73,7,63,67};
a[6]=ccc;
 int cccc[]={99,65,4,28,6,16,70,92};
a[7]=cccc;
 int d[]={41,41,26,56,83,40,80,70,33};
a[8]=d;
 int dd[]={41,48,72,33,47,32,37,16,94,29};
a[9]=dd;
 int ddd[]={53,71,44,65,25,43,91,52,97,51,14};
a[10]=ddd;
 int dddd[]={70,11,33,28,77,73,17,78,39,68,17,57};
a[11]=dddd;
 int e[]={91,71,52,38,17,14,91,43,58,50,27,29,48};
a[12]=e;
 int ee[]={63,66,4,68,89,53,67,30,73,16,69,87,40,31};
a[13]=ee;
 int eee[]={4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};
a[14]=eee;
 
 grid(0,0,0);
cout<<maxi;
	return 0;
}
