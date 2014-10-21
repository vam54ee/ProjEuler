#include<iostream>
using namespace std;
int main()
{int j=3,k=1;
int b[10003],*c=new int[10003];
b[0]=1;
b[1]=2;b[2]=3;
 //ofstream myfile;
 // myfile.open ("7.txt");
 for(int i=5;j<=10003;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }
 c[6]=0;
int x=1;
long long int n=12000;
long long int y=n*(n+1)/2;
for(int z=n;z<n+1000;z++)
{c=new int[10003];k=1;c[6]=0;
long long int y=z*(z+1)/2;
x=1;
for(long long int i=1;i<j&&y>0;i++)
{int tt=0;
while(y%b[i]==0)
{
tt=1;
//cout<<b[i]<<"\t"<<y<<endl;
c[k]++;
y=y/b[i];
}
if(tt)
k++;
}

for(long long int i=1;i<=k;i++)
{
//cout<<c[i]<<"\t"<<i<<endl;
x=x*(c[i]+1);
}

if(x>300)
cout<<x<<"\t"<<z<<endl;
}
    return 0;
}
