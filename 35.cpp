#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int j=3;
int b[10003];
int num[]={1,3,7,9};
int numsz=4;
int* store;
int ans=4;
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


int iscirc(int x,int d)
{//cout<<"hi";
int t=x,l=x;
for(int i=0;i<d-1;i++)
{if(t%2==0)
return 0;
t=t/10;
}
for(int i=0;i<d;i++)
{
int c=x/(int)pow(10,d-1);
x=(x%(int)pow(10,d-1))*10+c;
if(!isprime(x))
{return 0;
}
//cout<<has(91)<<"\t"<<has(70)<<endl;
}
cout<<l<<"\t"<<x;
cout<<endl;
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
if(iscirc(p,z))
ans++;
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
j=3;
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
 
 // for(int i=1;i<j;i++)
 // myfile<<b[i]<<"\r\n";
   //cout<<"hi";
 // myfile.close();
 // int ans=0;
/* for(int i=0;i<j;i++)
 {int d=0;
 if(0<b[i]&&b[i]<10)
 if(iscirc(b[i],1))
 ans++;
 if(10<b[i]&&b[i]<100)
 if(iscirc(b[i],2))
 ans++;
 } */
  /* for(int i=25;i<j;i++)
 {int d=0;
 if(100<b[i]&&b[i]<1000)
 if(iscirc(b[i],3))
 ans++;
  if(1000<b[i]&&b[i]<10000)
 if(iscirc(b[i],4))
 ans++;
  if(10000<b[i]&&b[i]<100000)
 if(iscirc(b[i],5))
 ans++;
    }
 */
cout<<ans;
    return 0;
}
