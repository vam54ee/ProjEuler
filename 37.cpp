#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int j=3;
int b[10003];
int num[]={1,3,7,9};
int numsz=4;
int* store;
int ans=23+53;
void assign(int size)
{store=new int[size];
for(int i=0;i<size;i++)
store[i]=-1;
}

int isprime(long long int f)
{
if(f<10000)
{for(int i=1;i<j;i++)
if(b[i]==f)
return 1;
return 0;
}

for(long long int i=3;i<sqrt(f);i++)
if(f%i==0)
return 0;
return 1;

}

void check(int z)
{long long int p=0;
for(int i=0;i<z;i++)
{
p=(p*10+store[i]);
//cout<<store[i];
}
//cout<<p<<endl;
long long int q=p,u=p,y=0,l=0;
while(q>0)
{//if(p==7993)
//cout<<q<<"\t"<<isprime(q)<<endl;
if(!isprime(q))
l=1;
q/=10;
y++;
}
while(y>0)
{//if(p==7993)
//cout<<u<<"\t"<<isprime(u)<<endl;

if(!isprime(u))
l=1;
u%=(long long int)pow(10,--y);
}
if(l==0)
{ans+=p;cout<<p<<endl;}

//cout<<endl<<endl;
}


int permute(int len,int size)
{if(len==size)
assign(size);
if(len==1)
{
for(int i=0;i<numsz;i++)
{
store[size-len]=num[i];
check(size);
store[size-len]=-1;
}
}
else
{
for(int i=0;i<numsz;i++)
{
//cout<<len<<"\t"<<size<<endl;
store[size-len]=num[i];
permute(len-1,size);
store[size-len]=-1;
}
}
}

int main()
{
b[0]=1;
b[1]=2;b[2]=3;
 //ofstream myfile;
  //myfile.open ("7.txt");
 for(int i=5;i<=10003;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
permute(2,2);
permute(3,3);
permute(4,4);
permute(5,5); 
permute(6,6); 
//permute(7,7); 
//permute(8,8); 
//permute(9,9); 
cout<<ans;
    return 0;
}
