#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int size=100000;
int* bb;
int kk=1;
 ofstream myfile;
int j=3,k=1;
int *b=new int[size];
int *c=new int[size];
int *d=new int[size];
int *e=new int[size];


void prime(){

b[0]=1;
b[1]=2;b[2]=3;
 for(int i=5;j<=size;i+=2)
 {int x=1;
 for(int c=1;c<j;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[j]=i;j++;}
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
e[k]++;

y=y/b[i];
}
if(tt)
{d[k]=b[i];k++;}
}
}


 
int main()
{
prime();
 c[1]=1;
for(int i=1;b[i]<size;i++)
{
c[b[i]]=1+b[i];
for(int p=b[i]*b[i],q=b[i];p<size&&p!=1;q=p,p=p*b[i])
c[p]=p+c[q];
}
for(int i=2;i<size;i++)
{if(c[i]==0)
{c[i]=1;
e=new int[size];
d=new int[size];
k=1;
 primefact(i);
for(int s=1;s<k;s++)
{//cout<<d[s+1]<<"\t"<<e[s+1]<<"\t"<<(int)pow(d[s+1],e[s+1])<<"\t"<<c[i]<<"\t"<<i<<endl;
int g=(int)pow(d[s],e[s]);
if(g>0&&g<size)
c[i]*=c[g];
else
cout<<i<<endl;
}
//cout<<b[l]<<"\t"<<i/b[l]<<"\t"<<c[b[l]]*c[i/b[l]]<<endl;

}

}

int ss[4]={1713,4064,6392,8695};
for(int i,m=0;m<4;m++)
{i=ss[m];
c[i]=1;
e=new int[size];
d=new int[size];
k=1;
 primefact(i);
/*  for(int s=1;s<k;s++)
{cout<<d[s]<<"\t"<<e[s]<<endl;
}
cout<<endl;
 */  
for(int s=1;s<k;s++)
{//cout<<d[s+1]<<"\t"<<e[s+1]<<"\t"<<(int)pow(d[s+1],e[s+1])<<"\t"<<c[i]<<"\t"<<i<<endl;
int g=(int)pow(d[s],e[s]);
if(g>0&&g<size)
c[i]*=c[g];
else
cout<<i<<endl;
}
 
}




int ans=0;
for(int i=2;i<size;i++)
{//cout<<c[i]-i<<"\t"<<i<<endl;
if(i!=c[i]-i)
if(c[c[i]-i]-(c[i]-i)==i)
{cout<<c[i]-i<<"\t"<<i<<endl;
ans=ans+c[i];c[c[i]-i]=0;}
} 
cout<<ans<<endl<<endl;
//cout<<c[575]-575<<endl;  
//cout<<c[3937]-3937<<endl;
//cout<<c[5593]-5593<<endl;  
  
 	return 0;
}
