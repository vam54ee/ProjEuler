#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int j=3;
int b[10003];
int isprime(int f)
{
for(int i=0;i<10003;i++)
if(b[i]==f)
return 1;
return 0;
}
int ans=0;
void check(int p)
{
int q=p,u=p,l=0;
while(q>0)
{
if(isprime(q))
ans+=p;
q/=10;
l++;
}
while(u>0)
{
if(isprime(q))
ans+=p;
q%=(int)pow(10,--l);
}
}

int main()
{
b[0]=1;
b[1]=2;b[2]=3;
 ofstream myfile;
  myfile.open ("7.txt");
 for(int i=5;j<=10003;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
 }

// for(int i=1;i<j;i++)
  //myfile<<b[i]<<"\r\n";
 
  //myfile.close();
 check(37);
 check(3373);
 check(3733);
 check(3793);
 check(3797);
 check(7333);
 check(7393);
 check(7793);
 check(7993);
 check(7937);
 check(73);

cout<<ans;
    return 0;
}
