#include"bigint.h"
#include<fstream>
#include<cmath>
using namespace std;
long double area(long double a,long double b,long double c)
{
	long double d=a+b+c;
	d/=2;
	cout<<d<<"\t"<<a<<"\t"<<b<<"\t"<<c<<"\t"<<sqrt(d*(d-a)*(d-b)*(d-c))<<endl;
	return sqrt(d*(d-a)*(d-b)*(d-c));
}

bool isin(int* a)
{//cout<<"l";
	long double x1,x2,x3,o1,o2,o3;
	x1=sqrt(pow(long double(a[0]-a[2]),2)+pow(long double(a[1]-a[3]),2));
	x2=sqrt(pow(long double(a[4]-a[2]),2)+pow(long double(a[5]-a[3]),2));
	x3=sqrt(pow(long double(a[0]-a[4]),2)+pow(long double(a[1]-a[5]),2));
	o1=sqrt(pow(long double(a[0]),2)+pow(long double(a[1]),2));
	o2=sqrt(pow(long double(a[2]),2)+pow(long double(a[3]),2));
	o3=sqrt(pow(long double(a[4]),2)+pow(long double(a[5]),2));
	long double a1=area(x1,x2,x3),a2=area(x1,o2,o3),a3=area(o1,x2,o3),a4=area(o1,o2,x3);
	cout<<a1<<"\t"<<a2<<"\t"<<x3<<"\t"<<o1<<"\t"<<o2<<"\t"<<o3<<endl;
return a1==a2+a3+a4;
	}

int main()
{
	ifstream fin("102.txt");
	string s;
	int ans=0;
	while(getline(fin,s)&&!(ans++))
	{int x[6];
	for(int i=0,k=0,j=0;i<=s.length();i++)
	{
		if(s[i]==','||i==s.length()-1)
		{
			if(s[k]=='-')
			{
				if(i!=s.length()-1)
				 {x[j++]=-1*(int)BigInt(s.substr(k+1,i-k-1));
				k=i+1;}
				else
					{x[j++]=-1*(int)BigInt(s.substr(k+1,i-k));
				k=i+1;}
				
			}
			else
			{
				if(i!=s.length()-1)
				 {x[j++]=(int)BigInt(s.substr(k,i-k));
				k=i+1;}
				else
					{x[j++]=(int)BigInt(s.substr(k,i-k+1));
				k=i+1;}
			}
			//cout<<x[j-1]<<endl;
		}

	}
	if(isin(x))
	{
		ans++;
		cout<<ans<<endl;
	}
	}
	fin.close();
	return 0;
}
