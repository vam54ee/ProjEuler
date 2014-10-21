#include<iostream>
#include<fstream>
using namespace std;
int j=3;
int b[10003];
int ans=0,pr=0;

int isprime(int x)
{
if(x<=1)
return 0;
for(int i=0;i<10003;i++)
if(b[i]==x)
return 1;
return 0;
}
void check(int p,int k)
{int i=0;
for(i=0;isprime(i*(i+p)+k);i++);
if(ans<i)
{ans=i;pr=p*k;
cout<<p<<"\t"<<k<<endl;}

for(i=0;isprime(i*(i-p)+k);i++);
if(ans<i)
{ans=i;pr=-1*p*k;
cout<<p<<"\t"<<k<<endl;}

for(i=0;isprime(i*(i+p)-k);i++);
if(ans<i)
{ans=i;pr=-1*p*k;
cout<<p<<"\t"<<k<<endl;}

for(i=0;isprime(i*(i-p)-k);i++);
if(ans<i)
{ans=i;pr=p*k;
cout<<p<<"\t"<<k<<endl;}

//cout<<ans<<"\t"<<pr<<endl;

}

int main()
{int count;

b[0]=1;
b[1]=2;b[2]=3;
for(int i=5;j<=10003;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
 
 ans=0;
 for(int i=1;i<1000;i+=2)
 {
 for(int j=1;j<1000;j+=2)
 {

 check(i,j);

 }
 
 }
 cout<<endl<<ans<<"\t"<<pr<<endl;
 
 //check(1,41);
    return 0;
}
