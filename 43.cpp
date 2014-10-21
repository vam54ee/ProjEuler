#include<iostream>
using namespace std;
int d[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
long long int ans=0;

long long int convert()
{
long long int yy=0;
for(int i=0;i<10;i++)
{yy=yy*10+d[i];}
cout<<yy<<endl;
return yy;
}

int has(int ss)
{
for(int i=0;i<10;i++)
if(d[i]==ss)
return 1;
return 0;
}
int main()
{
for(int i=0;i<10;i+=5)
{
d[5]=i;
for(int j=0;j<10;j+=2)
{
if(has(j))
continue;
d[3]=j;
for(int  k=0;k<10;k++)
{
if(has(k))
continue;
d[2]=k;
for(int l=0;l<10;l++)
{
if((d[3]+d[2]+l)%3!=0)
continue;
if(has(l))
continue;
d[4]=l;
for(int m=0;m<10;m++)
{
if((d[4]*10+d[5]-2*m)%7!=0)
continue;
if(has(m))
continue;
d[6]=m;
for(int n=0;n<10;n++)
{
if((d[5]*10+d[6]-n)%11!=0)
continue;
if(has(n))
continue;
d[7]=n;
for(int q =0;q<10;q++)
{
if((d[6]*10+d[7]+4*q)%13!=0)
continue;
if(has(q))
continue;
d[8]=q;
for(int r =0;r<10;r++)
{
if((d[7]*10+d[8]-5*r)%17!=0)
continue;
if(has(r))
continue;
d[9]=r;
int tt[]={0,0},tt1=0;
int e[]={0,0,0,0,0,0,0,0,0,0};
for(int z=0;z<10;z++)
if(d[z]>=0)
e[d[z]]=1;
for(int z=0;z<10;z++)
{//cout<<e[z]<<"\t"<<d[z]<<endl;
if(e[z]==0&&tt1==0)
{tt[0]=z;tt1=1;}
if(e[z]==0&&tt1!=0)
{tt[1]=z;}
}
//cout<<tt[0]<<"\t"<<tt[1]<<endl;
d[0]=tt[0];d[1]=tt[1];
ans+=convert();
d[0]=tt[1];d[1]=tt[0];
ans+=convert();
d[0]=-1;d[1]=-1;


d[9]=-1;
}

d[8]=-1;
}

d[7]=-1;
}

d[6]=-1;
}

d[4]=-1;
}
d[2]=-1;
}
d[3]=-1;
}
d[5]=-1;
}
cout<<ans;
return 0;
}
