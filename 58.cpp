#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
using namespace std;
int j=3;
int size=10003;
int *b=new int[size];
int isprime(int h)
{
if(h<100000)
{
for(int i=1;i<size;i++)
if(b[i]==h)
return 1;
return 0;
}
for(int i=2;i<sqrt(h);i++)
if(h%i==0)
return 0;
return 1;
}
int main()
{


b[0]=1;
b[1]=2;b[2]=3;
 //ofstream myfile;
  //myfile.open ("7.txt");
 for(int i=5;j<=size;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }

long long int sum=3;
for(int i=2;i<=15000;i++)
{//cout<<sum<<endl;
int x,y,z,w,j;
j=2*i+1;
x=(int)pow(j,2);
y=x-j+1;
z=y-j+1;
w=z-j+1;
//cout<<x<<"\t"<<y<<"\t"<<z<<"\t"<<w<<endl;
if(isprime(y))
sum++;
if(isprime(z))
sum++;
if(isprime(w))
sum++;
cout<<sum<<"\t"<<(2*j-1)<<"\t"<<sum*100.0/(2*j-1)<<"\t"<<j<<endl;
if(sum*100.0/(2*j-1)<10)
{cout<<sum*100.0/(2*j-1)<<"\t"<<j<<endl;}
}
//cout<<sum;
	return 0;
}
