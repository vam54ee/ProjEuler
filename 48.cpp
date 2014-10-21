#include<iostream>
#include<cmath>
using namespace std;
void power1(int i,long long int&g)
{//long long int x=1;
//cout<<i<<"\t";
long long int carry=0;
int* x=new int [10];
x[9]=1;
int v=9;
for(int j=0;j<i;j++)
{carry=0;
for(int k=9;k>=0;k--)
{
long long int c=x[k]*i+carry;
x[k]=c%10;
carry=c/10;
if(v==k)
{
for(int p=k-1;p>=0&&carry>0;carry/=10,p--,v--)
x[p]=carry%10;

break;
}
}
/* if(i==15)
cout<<x<<endl;
 */
 }
 g=0;
for(int p=0;p<10;p++)
{
g=g*10+x[p];
if(i==988)
cout<<x[p];
}
//if(i==988)
//cout<<"\t"<<pow(12,12)<<endl;
//cout<<i<<"\t"<<g<<endl;
}
int main()
{ int *a=new int[10];long long int g=0;a[6]=0;
/* for(int i=1;i<10;i++)
cout<<(a+=pow(i,i))<<endl;
 */for(int k=1;k<1000;k++)
{
power1(k,g);

long long int carry=g;
for(int l=9;l>=0;l--)
{//cout<<a[l]<<endl;
long long int c=a[l]+carry;
a[l]=c%10;
carry=c/10;
/* if(v==k)
{
for(int p=k-1;p>=0&&carry>0;carry/=10,p--,v--)
x[p]=carry%10;

break;
} */
//cout<<a[l]<<"\t"<<l<<endl;
}
cout<<endl;

//a+=g;
cout<<k<<"\t"<<g<<endl;
//if(a/1000000000>1)
//a%=10000000000;
//cout<<a<<endl;
}

for(int p=0;p<10;p++)
{
g=g*10+a[p];
}
cout<<g;
    return 0;
}
