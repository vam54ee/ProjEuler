#include<iostream>
using namespace std;
long long int rec(int a,int b)
{
if(a==1)
return b+1;
else if(b==1)
return a+1;
else if(a==b)
return 2*rec(a-1,b);
else if(a!=b)
return rec(a-1,b)+rec(a,b-1);
}
int main()
{int n=20;
cout<<rec(n,n);
    return 0;
}
