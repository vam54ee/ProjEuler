#include<iostream>
using namespace std;
int main()
{
int a[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int b[10]={0,0,6,6,5,5,5,7,6,6};
long long int c=106;
for(int i=20;i<1000;i++)
{int f=c;
if(i>100&&i%100!=0)
{
c=c+a[i/100]+10;
}
else if(i>=100)
{

c=c+a[i/100]+7;
}
if((i%100)>19)
{
c=c+b[(i%100)/10]+a[i%10];
}
else
{
c=c+a[i%100];
}
cout<<c-f<<"\t"<<i<<endl;
}
cout<<c+11;
 

 return 0;
}
