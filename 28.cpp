#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
long long int sum=1;
for(int i=1;i<=500;i++)
{//cout<<sum<<endl;
int x,y,z,w,j;
j=2*i+1;
x=(int)pow(j,2);
y=x-j+1;
z=y-j+1;
w=z-j+1;
//cout<<x<<"\t"<<y<<"\t"<<z<<"\t"<<w<<endl;
sum+=(x+y+z+w);
}
cout<<sum;
	return 0;
}
