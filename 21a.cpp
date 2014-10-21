#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int size;
int* bb;
int kk=1;
 ofstream myfile;
int j=3,k=1;
int b[10003],*c,*d;



void prime(){

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
}



 void assign()
{
for(int i=0;i<size;i++)
bb[i]=-1;
}



void push(int aa)
{
//cout<<a<<endl;
int i=0;
for(;i<size&&bb[i]!=-1;i++);
bb[i]=aa;
}


void remove()
{int i=0;
for(;i<size&&bb[i]!=-1;i++);
bb[i-1]=-1;
}

int has(int a)
{//cout<<a<<endl;
int i=0;
for(;i<size&&bb[i]!=-1;i++)
if(bb[i]==a)
return 1;
return 0;

}

void out()
{int ak=1;
for(int i=1;i<k&&bb[i-1]!=-1;i++)
{
//cout<<kk<<"\t"<<d[i]<<"\t"<<bb[i-1]<<"\t"<<pow(d[i],bb[i-1])<<endl;
ak=ak*(int)pow(d[i],bb[i-1]);
//cout<<ak<<endl;
}
kk+=ak;
myfile<<kk<<"\r\n";

}

void permute(int length)
{
if(length==1)
{
int i=0;
for(;i<=c[size-length];i++)
{
push(i);
out();
remove();
}
}
else
{int i=0;
for(;i<=c[size-length];i++)
{//cout<<i<<"\t"<<length<<endl;
push(i);
permute(length-1);
remove();
}
}
}

void primefact(int z)
{
long long int y=z;
for(long long int i=1;i<j&&y>0;i++)
{int tt=0;
while(y%b[i]==0)
{
tt=1;
c[k]++;

y=y/b[i];
}
if(tt)
{d[k]=b[i];k++;}
}
}

int main()
{
prime();
myfile.open ("24.txt");

long long int n=0;
long long int y=n*(n+1)/2;
/* for(int z=n;z<10000;z++)
{ */
kk=0;c=new int[10003];d=new int[10003];k=1;c[6]=0;
int ff=280;
primefact(ff);
//cout<<k<<endl;
for(int i=0;i<k;i++)
//cout<<c[i]<<"\t"<<d[i]<<endl;
size=k;
bb=new int[size];

assign();
permute(size-1);
//}
cout<<kk-ff;
myfile.close();
    return 0;
}
