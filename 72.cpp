#include"bigint.h"
#include<cmath>
using namespace std;
int size=1000000,size1=1000001;
BigInt ans;
 int size2=1;
int *b=new int[size];
int* a=new int[size1];
int gcd(int a,int b)
{
if(a%b==0)
return b;
return gcd(b,a%b);
}
void prime()
{
int* tmp=new int[size1];
for(int i=0;i<size1;i++)
tmp[i]=1;

for(int i=2;i<size1;i++)
for(int j=2;i*j<size1;j++)
tmp[i*j]=0;

for(int i=2;i<size1;i++)
{
if(tmp[i]==1)
{
//cout<<i<<endl;
b[size2]=i;
 if(b[size2]<size1)
 a[b[size2]]=b[size2]-1;size2++;
}
}
a[1]=1;a[2]=1;a[3]=2;

}
bool isperm(int a,int b)
{
BigInt d(a),e(b);
int *p=new int[10],*q=new int[10];
for(int i=0;i<10;i++)
{p[i]=0;q[i]=0;}
for(int i=0;i<d.noOfDigits();i++)
p[d[i]-'0']++;
for(int i=0;i<e.noOfDigits();i++)
q[e[i]-'0']++;
for(int i=0;i<10;i++)
{
if(p[i]!=q[i])
return false;
}return true;
}
 int main()
{int max1=2;
 for(int i=1;i<size1;i++)
 { a[i]=0;}
 prime();
 
  for(int i=1;i<size2;i++)
 {//cout<<i<<endl;
 for(int j=2;pow(b[i],j)<size;j++)
 {a[(int)pow(b[i],j)]=pow(b[i],j-1)*(b[i]-1);
 //cout<<i<<"\t"<<b[i]<<"\t"<<a[(int)pow(b[i],j)]<<endl;
 //cout<<i<<"\t"<<j<<endl;
 }
 }
 int maxi=1;
  for(int i=2;i<46341;i++)
 {//cout<<i<<"\t"<<(i*(i+1)<size)<<endl;
 for(int j=i+1;i*j<size1;j++)
 {//cout<<i<<"\t"<<j<<endl;
 if(i*j>maxi)
 maxi=i*j;
 if(gcd(j,i)==1)
 a[i*j]=a[i]*a[j];
 //cout<<i*j<<endl;
 }
 } 
 
  for(int i=2;i<size1;i++)
{//cout<<i<<"\t"<<a[i]<<endl;
  cout<<i<<"\t"<<a[i]<<endl;
  ans+=a[i];}
cout<<ans;
return 0;
}
  