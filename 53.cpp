#include<iostream>
using namespace std;
long long int fact(int r)
{
if(r<2)
return 1;
return r*fact(r-1);
}
long long int fac(int n,int r)
{
long long int yy=1;
for(int i=n;i>n-r;i--)
yy*=i;
return yy;
}
long long int comb(int n,int r)
{//cout<<"hi";
return fac(n,r)/fact(r);
}
int main()
{int ans=0;
for(int i=23;i<=100;i++)
{

for(int j=2;j<=i/2.0;j++)
{//cout<<i<<"\t"<<j<<endl;
if(comb(i,j)>1000000)
{ans+=((i-j)-j+1);cout<<i<<"\t"<<j<<"\t"<<((i-j)-j+1)<<endl;break;}
}
}

cout<<ans;
    return 0;
}
