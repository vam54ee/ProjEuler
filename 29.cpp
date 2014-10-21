#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
int *x;
int ans=99*99;
prime(arr,100,j);
int jj[]={2,3,5,6,7,10};
for(int i=0;i<6;i++)
{

x=new int[600];
for(int f=2;f<=100;f++)
x[f]=1;
for(int f=2;pow(jj[i],f)<=100;f++)
{cout<<jj[i]<<"\t"<<f;
for(int z=2;z<101;z++)
{
if(x[f*z]==1)
{ans--;cout<<pow(jj[i],f)<<"\t"<<z<<endl;}
else
x[f*z]=1;

}
}

}
cout<<ans;
	return 0;
}
