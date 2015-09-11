#include"bigint.h"
#include<fstream>
#include<cmath>
using namespace std;
int a[53],b[53];
int c[26];


int isHigh()
{
int m=0,n=0,x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}
for(int j=0;j<4;j++)
for(int i=0;i<14;i++)
{
if(a[i+13*j])
x1[i]=1;
}
for(int j=0;j<4;j++)
for(int i=0;i<14;i++)
{
if(b[i+13*j])
x2[i]=1;
}
//cout<<m<<"\t"<<n;
for(int i=13;i>0;i--)
{
if(x1[i]==1&&x2[i]!=1)
return -1;
if(x2[i]==1&&x1[i]!=1)
return 1;
}
return 0;
}


int isRoyal()
{int m=0,n=0;
for(int i=0;i<4;i++)
{
if(a[13*i+9]&&a[13*i+10]&&a[13*i+11]&&a[13*i+12]&&a[13*i+13])
m=1;
if(b[13*i+9]&&b[13*i+10]&&b[13*i+11]&&b[13*i+12]&&b[13*i+13])
n=1;

}
if(m==n)
return 0;
if(m>n)
return -1;
return 1;
}

int isStraightf()
{int m=0,n=0;
for(int i=0;i<4;i++)
{
for(int j=1;j<14;j++)
{
if(a[13*i+j]&&a[13*i+j+1]&&a[13*i+j+2]&&a[13*i+j+3]&&a[13*i+j+4])
m=1;
if(b[13*i+j]&&b[13*i+j+1]&&b[13*i+j+2]&&b[13*i+j+3]&&b[13*i+j+4])
n=1;
}
}
//cout<<m<<n<<endl;
if(m==n&&m==0)
return 0;
if(m>n)
return -1;
if(m<n)
return 1;
return isHigh();
}




int isStraight()
{int m=0,n=0,x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}

for(int i=0;i<4;i++)
{
for(int j=0;j<14;j++)
{
if(a[13*i+j])
x1[j]=1;
if(b[13*i+j])
x2[j]=1;
}
}
for(int i=1;i<10;i++)
{//cout<<x1[i]<<"\t"<<x2[i]<<endl;
if(x1[i]&&x1[i+1]&&x1[i+2]&&x1[i+3]&&x1[i+4])
m=i;
if(x2[i]&&x2[i+1]&&x2[i+2]&&x2[i+3]&&x2[i+4])
n=i;
}
//cout<<m<<n<<endl;
if(m==n&&m==0)
return 0;
if(m>n)
return -1;
if(m<n)
return 1;
return isHigh();
}



int isfof()
{int m=0,n=0,k1=0,k2=0;

for(int j=1;j<14;j++)
{
if(a[13*0+j]&&a[13*1+j]&&a[13*2+j]&&a[13*3+j])
{m=1;k1=j;}
if(b[13*0+j]&&b[13*1+j]&&b[13*2+j]&&b[13*3+j])
{n=1;k2=j;}
}

if(m>n)
return -1;
if(m<n)
return 1;
if(m==n&&m==0)
return 0;
if(k1>k2)
return -1;
if(k1<k2)
return 1;

a[13*0+k1]=a[13*1+k1]=a[13*2+k1]=a[13*3+k1]=0;
b[13*0+k2]=b[13*1+k2]=b[13*2+k2]=b[13*3+k2]=0;
return isHigh();
}


int istof()
{int m=0,n=0,k1=0,k2=0;
int x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}
for(int j=0;j<14;j++)
{
if(a[13*0+j])
x1[j]++;
if(a[13*1+j])
x1[j]++;
if(a[13*2+j])
x1[j]++;
if(a[13*3+j])
x1[j]++;
if(b[13*0+j])
x2[j]++;
if(b[13*1+j])
x2[j]++;
if(b[13*2+j])
x2[j]++;
if(b[13*3+j])
x2[j]++;
}
for(int j=0;j<14;j++)
{if(x1[j]==3)
{m=1;k1=j;}
if(x2[j]==3)
{n=1;k2=j;}
}//cout<<m<<"\t"<<n<<endl;
if(m>n)
return -1;
if(m<n)
return 1;
if(m==n&&m==0)
return 0;
if(k1>k2)
return -1;
if(k1<k2)
return 1;

if(a[k1]==1)
a[k1]=0;
if(a[13+k1]==1)
a[13+k1]=0;
if(a[26+k1]==1)
a[26+k1]=0;
if(a[39+k1]==1)
a[39+k1]=0;

if(b[k2]==1)
b[k2]=0;
if(b[13+k2]==1)
b[13+k2]=0;
if(b[26+k2]==1)
b[26+k2]=0;
if(b[39+k2]==1)
b[39+k2]=0;



return isHigh();}



int istpair()
{int m=0,n=0;
int x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}
for(int j=1;j<14;j++)
{
if(a[13*0+j])
x1[j]++;
if(a[13*1+j])
x1[j]++;
if(a[13*2+j])
x1[j]++;
if(a[13*3+j])
x1[j]++;
if(b[13*0+j])
x2[j]++;
if(b[13*1+j])
x2[j]++;
if(b[13*2+j])
x2[j]++;
if(b[13*3+j])
x2[j]++;}
int t1=0,t2=0,k1=-1,k2=0,k3=-1,k4=0;
for(int j=0;j<14;j++)
{//cout<<x1[j]<<"\t"<<x2[j]<<endl;
if(x1[j]==2)
{t1++;
if(k1==-1)
k1=j;
else
k2=j;
}
if(x2[j]==2)
{t2++;
if(k3==-1)
k3=j;
else
k4=j;}
}
if(t1==2)
m=1;
if(t2==2)
n=1;


if(m>n)
return -1;
if(m<n)
return 1;
if(m==n&&m==0)
return 0;
if((k1>k2&&k1>k4)||(k3>k2&&k3>k4))
return -1;
if((k2>k1&&k2>k3)||(k4>k1&&k4>k3))
return 1;

if(k1)
if(a[k1]==1)
a[k1]=0;
if(a[13+k1]==1)
a[13+k1]=0;
if(a[26+k1]==1)
a[26+k1]=0;
if(a[39+k1]==1)
a[39+k1]=0;

if(b[k2]==1)
b[k2]=0;
if(b[13+k2]==1)
b[13+k2]=0;
if(b[26+k2]==1)
b[26+k2]=0;
if(b[39+k2]==1)
b[39+k2]=0;

if(a[k3]==1)
a[k3]=0;
if(a[13+k3]==1)
a[13+k3]=0;
if(a[26+k3]==1)
a[26+k3]=0;
if(a[39+k3]==1)
a[39+k3]=0;

if(b[k4]==1)
b[k4]=0;
if(b[13+k4]==1)
b[13+k4]=0;
if(b[26+k4]==1)
b[26+k4]=0;
if(b[39+k4]==1)
b[39+k4]=0;

return isHigh();
}




int ispair()
{int m=0,n=0;
int x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}
for(int j=0;j<14;j++)
{
if(a[13*0+j])
x1[j]++;
if(a[13*1+j])
x1[j]++;
if(a[13*2+j])
x1[j]++;
if(a[13*3+j])
x1[j]++;
if(b[13*0+j])
x2[j]++;
if(b[13*1+j])
x2[j]++;
if(b[13*2+j])
x2[j]++;
if(b[13*3+j])
x2[j]++;}
int t1=0,t2=0,k1,k2;
for(int j=1;j<14;j++)
{

if(x1[j]==2)
{t1++;k1=j;}
if(x2[j]==2)
{t2++;k2=j;}
}
if(t1==1)
m=1;
if(t2==1)
n=1;
if(m>n)
return -1;
if(m<n)
return 1;
if(m==n&&m==0)
return 0;
if(k1>k2)
return -1;
if(k2>k1)
return 1;
if(a[k1]==1)
a[k1]=0;
if(a[13+k1]==1)
a[13+k1]=0;
if(a[26+k1]==1)
a[26+k1]=0;
if(a[39+k1]==1)
a[39+k1]=0;

if(b[k2]==1)
b[k2]=0;
if(b[13+k2]==1)
b[13+k2]=0;
if(b[26+k2]==1)
b[26+k2]=0;
if(b[39+k2]==1)
b[39+k2]=0;

return isHigh();
}




int isFH()
{



int m=0,n=0,k1=0,k2=0;
int x1[14],x2[14];
for(int i=0;i<14;i++)
{x1[i]=0;x2[i]=0;}
for(int j=0;j<14;j++)
{
if(a[13*0+j])
x1[j]++;
if(a[13*1+j])
x1[j]++;
if(a[13*2+j])
x1[j]++;
if(a[13*3+j])
x1[j]++;
if(b[13*0+j])
x2[j]++;
if(b[13*1+j])
x2[j]++;
if(b[13*2+j])
x2[j]++;
if(b[13*3+j])
x2[j]++;}
for(int j=1;j<14;j++)
{//cout<<x1[j]<<"\t"<<x2[j]<<endl;
if(x1[j]==3)
{m=1;k1=j;}
if(x2[j]==3)
{n=1;k2=j;}
}
//cout<<m<<n<<endl;

int m1=0,n1=0;
//int x1[14],x2[14];

int t1=0,t2=0,k3,k4;
for(int j=1;j<14;j++)
{if(x1[j]==2)
{t1++;k3=j;}
if(x2[j]==2)
{t2++;k4=j;}
}
if(t1==1)
m1=1;
if(t2==1)
n1=1;
m=m&&m1;
n=n&&n1;

if(m>n)
return -1;
if(m<n)
return 1;
if(m==n&&m==0)
return 0;
if(k1>k2)
return -1;
if(k2>k1)
return 1;
if(k3>k4)
return -1;
if(k4>k3)
return 1;
return 0;

}




int isFlush()
{int m=0,n=0;
for(int i=0;i<4;i++)
{int c1=0,c2=0;
for(int j=1;j<14;j++)
{
if(a[13*i+j])
c1++;
if(b[13*i+j])
c2++;
}
//cout<<c1<<"\t"<<c2<<endl;
if(c1==5)
m=1;
if(c2==5)
n=1;
}
if(m==n&&m==0)
return 0;
if(m>n)
return -1;
if(m<n)
return 1;
return isHigh();
}



void init(string s)
{
for(int i=0;i<53;i++)
{a[i]=0;b[i]=0;}

for(int i=0;i<14;i+=3)
{
int p=13*c[s[i+1]-'A'];
if(s[i]>='A'&&s[i]<='Z')
{a[p+(c[s[i]-'A'])-1]=1;}
else
{a[p+(s[i]-'0')-1]=1;}
}

for(int i=15;i<s.length();i+=3)
{
int p=13*c[s[i+1]-'A'];
if(s[i]>='A'&&s[i]<='Z')
b[p+(c[s[i]-'A'])-1]=1;
else
b[p+(s[i]-'0')-1]=1;
}

 for(int i=0;i<53;i++)
{cout<<a[i];}
cout<<endl;
for(int i=0;i<53;i++)
{cout<<b[i];}
cout<<endl;
 }

int main()
{for(int i=0;i<26;i++)
{c[i]=0;}
c['C'-'A']=0;
c['D'-'A']=1;
c['H'-'A']=2;
c['S'-'A']=3;
c['J'-'A']=11;
c['Q'-'A']=12;
c['K'-'A']=13;
c['A'-'A']=14;
c['T'-'A']=10;


ifstream fin("54.txt");
	string s;//="QC KC 3S JC KD 2C 8D AH QS TS\n";
	//init(s);
	cout<<isStraight();
	//for(int i=0;i<size;i++)
	//arr[i]=new BigInt[size];
	int ans=0;
 	   for(int i=0;i<1000&&getline(fin,s);i++)
	{
		init(s);
		cout<<s<<endl;
		int ck=isRoyal();
		if(ck!=0)
		{cout<<"royal\n";
		if(ck==-1)
		ans++;
		continue;}
		ck=isStraightf();
		if(ck!=0)
		{cout<<"strf\n";
		if(ck==-1)ans++;
		continue;}
		ck=isfof();
		if(ck!=0)
		{cout<<"fof\n";
		if(ck==-1)ans++;
		continue;}
		ck=isFH();
		if(ck!=0)
		{cout<<"fh\n";
		if(ck==-1)ans++;
		continue;}
		ck=isFlush();
		if(ck!=0)
		{cout<<"f\n";
		if(ck==-1)ans++;
		continue;}
		ck=isStraight();
		if(ck!=0)
		{cout<<"str\n";
		if(ck==-1)ans++;
		continue;}
		ck=istof();
		if(ck!=0)
		{cout<<"tof\n";
		if(ck==-1)ans++;
		continue;}
		ck=istpair();
		if(ck!=0)
		{cout<<"tpair\n";
		if(ck==-1)ans++;
		continue;}
		ck=ispair();
		if(ck!=0)
		{cout<<"pair\n";if(ck==-1)ans++;
		continue;}
		ck=isHigh();
		if(ck!=0)
		{cout<<"high\n";if(ck==-1)ans++;
		continue;}
		
	}    
	cout<<ans;
	fin.close();
	return 0;
	}