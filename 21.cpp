#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int size=10000;
int* bb;
int kk=1;
 ofstream myfile;
int j=3,k=1;
int *b=new int[size];
int *c=new int[size];
int *d=new int[size];
int *e=new int[size];


void prime(){

b[0]=1;
b[1]=2;b[2]=3;
 for(int i=5;j<=size;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
}
int primefact(int z)
{int w=1;
long long int y=z;
for(long long int i=1;i<j&&y>0;i++)
{int tt=0,r=0;
while(y%b[i]==0)
{
tt=1;
r++;

y=y/b[i];
}
if(tt)
{
w*=c[(int)pow(b[i],r)];}
}
c[z]=w;

}


 
int main()
{
prime();
 c[1]=1;
for(int i=1;b[i]<size;i++)
{
c[b[i]]=1+b[i];
for(int p=b[i]*b[i],q=b[i];p<size&&p!=1;q=p,p=p*b[i])
c[p]=p+c[q];
}
for(int i=2;i<size;i++)
{if(c[i]==0)
{c[i]=1;
 primefact(i);
}
//cout<<b[l]<<"\t"<<i/b[l]<<"\t"<<c[b[l]]*c[i/b[l]]<<endl;

}


//for(int i=2;i<size;i++)
//cout<<c[i]<<"\t"<<i<<endl;



int ans=0;
for(int i=2;i<size;i++)
{//cout<<c[i]-i<<"\t"<<i<<endl;
if(i<c[i]-i&&c[i]-i!=1)
if(c[c[i]-i]-(c[i]-i)==i)
{cout<<c[i]-i<<"\t"<<i<<endl;
ans=ans+c[i];}
} 
cout<<ans<<endl<<endl;
//cout<<c[575]-575<<endl;  
//cout<<c[3937]-3937<<endl;
//cout<<c[5593]-5593<<endl;  
  
 	return 0;
}
