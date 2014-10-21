#include<iostream>
using namespace std;
int max1=0;
int j=3;
int b[10003];
int* a;
void check(int s)
{
a=new int[1000];
int p=10;
for(int i=0;i<1000;i++)
{
a[i]=p/s;
p=p%s;
p*=10;
//cout<<p<<"\t"<<a[i]<<endl;
}
for(int i=0;i<1000;i++)
{
for(int y=i+1;y<1000;y++)
{
if(a[i]==a[y]&&(a[i]!=0))
{int e=0;
for(int q=i+1,w=y+1;q<y&&w<1000;q++,w++)
{
//cout<<q<<"\t"<<w<<"\t"<<a[q]<<"\t"<<a[w]<<"\t"<<s<<endl;
if(a[q]!=a[w])
{e=1;break;}
}
if(e==0&&max1<y-i)
{max1=y-i;cout<<i<<"\t"<<y<<"\t"<<(y-i)<<"\t"<<max1<<"\t"<<s<<endl;
return;}
if(e==0)
return;
}
}
}
}

int main()
{
b[0]=1;b[1]=2;b[2]=3;
for(int i=5;j<10003;i++)
{int l=0;
for(int z=1;z<j;z++)
{
if(i%b[z]==0)
{l=1;break;}
}
if(l==0)
{b[j++]=i;}
}
for(int i=4;i<10000;i++)
check(b[i]);
//check(7);
//check(11);
//check(13);
return 0;
}
  