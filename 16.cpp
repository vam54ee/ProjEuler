#include<iostream>
using namespace std;
int main()
{
int n=1000,x=400;
int* arr=new int[401];int carry=0;
arr[400]=1;
for(int j=0;j<n;j++)
{carry=0;int i;
for(i=400;i>=x;i--)
{int a=arr[i]*2+carry;
//cout<<a<<"\t"<<arr[i]<<"\t"<<arr[i-1]<<"\t"<<i<<"\t"<<carry<<endl;
arr[i]=a%10;
carry=a/10;
//cout<<a<<"\t"<<arr[i]<<"\t"<<arr[i-1]<<"\t"<<carry<<"\t"<<(i-1>0&&arr[i-1]>0)<<endl;
}
arr[i]=carry;
if(carry)
x=i;
//cout<<x<<endl;
}
int z=0;
for(int i=x;i<401;i++)
{z+=arr[i];
cout<<arr[i]<<endl;
}

cout<<z;
    return 0;
}
