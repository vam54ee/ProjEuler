#include"bigint.h"
#include<cmath>
#include<fstream>
using namespace std;
bool is(int p,char c)
{char d=p^c;
return (d>31);
//return ((d>='A'&&d<='Z')||(d>='a'&&d<='z')||d==' '||d=='\"'||d=='\''||d=='?'||d==','||d=='!'||d==':'||d=='-'||d=='.');
}
int main()
{ BigInt a[3001], b[1001];
    ifstream fin("59.txt");
	ofstream fout("59o.txt");
	string s;
	getline(fin,s);
	//int k=0;
 	int i=0;
	for(int k=0,j=k+1;j<s.length()&&k<s.length();j++)
	{
	if(s[j]==',')
	{
	a[i++]=BigInt(s.substr(k,j-k));
	k=j+1;
	cout<<i<<"\t"<<j<<endl;
	}
	if(j==s.length()-1)
	{
	a[i++]=BigInt(s.substr(k,j-k+1));
	k=j+1;
	cout<<i<<"\t"<<j<<endl;
	}
	}
	
	int max1=1;
	char x,y,z;
	
for(int j=0;j<26;j++)
{max1=1;
for(int k=0;k<26;k++)
{
for(int l=0;l<26;l++)
{
for(int m=0;m<i;m+=3)
{x=j+'a',y=k+'a',z=l+'a';
//cout<<x<<y<<z<<(!(is(a[m],x)&&is(a[m+1],y)&&is(a[m+2],z)))<<endl;
if(!(is(a[m],x)&&is(a[m+1],y)&&is(a[m+2],z)))
{max1=0;
//cout<<(char)a[m]<<"\t"<<x<<"\t"<<(char)a[m+1]<<"\t"<<y<<"\t"<<(char)a[m+2]<<"\t"<<z<<endl;
break;}

}
/* if(max1)
 {fout<<x<<y<<z<<"\r\n";
 for(int m=0;m<i;m+=3)
{char p=(a[m]^x),q=(a[m+1]^y),r=(a[m+2]^z);
fout<<p<<q<<r;
//cout<<x<<y<<z<<endl;
}
fout<<"\r\n"<<"\r\n"<<"\r\n";
 } */
 }
}
//break;
}
int d=0;
  for(int m=0;m<i;m++) 
 { 
 if(m%3==0)
 d+=(a[m]^'g');
 if(m%3==1)
 d+=(a[m]^'o');
 if(m%3==2)
 d+=(a[m]^'d');
 cout<<d<<endl;
	} 
 	 return 0;
}
