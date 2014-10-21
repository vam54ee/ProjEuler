#include<iostream>
using namespace std;
int size=8;
int a[]={200,100,50,20,10,5,2,1};
int b[]={1,2,4,10,20,40,100,200};
int ans=0;
int max1=a[0];
int perm(int length,int sum)
{if(sum>=max1)
return 0;
if(length==1)
{
if(sum<max1)
ans++;
//cout<<sum<<"\t"<<ans<<endl;
}
else
{
for(int i=0;i<=b[size-length];i++)
{
if(sum+i*a[size-length]==max1)
{
ans++;
//cout<<sum+i<<"\t"<<ans<<endl;
break;
}
else if(sum>max1)
break;
perm(length-1,sum+(i*a[size-length]));
}

}
}

int main()
{

perm(size,0);
cout<<ans;
return 0;
}
