#include<iostream>
#include<fstream>
using namespace std;
int size;
int* b=new int[size];
int k=1;
int* ans=new int[9001];
 ofstream myfile;
  void assign()
{
for(int i=0;i<size;i++)
b[i]=-1;
}
void push(int a)
{
//cout<<a<<endl;
int i=1;
for(;i<size&&b[i]!=-1;i++);
b[i]=a;
}
void remove()
{int i=1;
for(;i<size&&b[i]!=-1;i++);
b[i-1]=-1;
}

int has(int a)
{//cout<<a<<endl;
int i=1;
for(;i<size&&b[i]!=-1;i++)
if(b[i]==a)
return 1;
return 0;

}

void out()
{int i=1;
int d1=1,d2=1,d3=1,d4=1,d5=1,d6=1,d7=1;
//myfile<<k<<"\t";
//for(;i<size&&b[i]!=-1;i++)
d1=b[1];
d2=b[2]*1000+b[3]*100+b[4]*10+b[5];
d3=b[1]*10+b[2];
d4=b[3]*100+b[4]*10+b[5];
d5=b[1]*100+b[2]*10+b[3];
d6=+b[4]*10+b[5];
d7=b[6]*1000+b[7]*100+b[8]*10+b[9];
if((d1*d2==d7)||(d3*d4==d7)||(d5*d6==d7))
{ans[d7-1000]=1;
//cout<<d7<<endl;
}
//myfile<<b[i];
//myfile<<"\r\n";
//k++;
}

void permute(int length)
{
if(length==1)
{
int i=1;
for(;i<size;i++)
{
if(!has(i))
{
push(i);
out();
remove();

}
}
}
else
{int i=1;
/* if(length==size)
i=2;
 */for(;i<size;i++)
{//cout<<i<<"\t"<<length<<endl;

if(!has(i))
{
push(i);
permute(length-1);
remove();

}
}

}
}
int main()
{myfile.open ("24.txt");
size=10;
assign();
permute(size-1);
myfile.close();
int anss=0;
for(int i=0;i<9001;i++)
if(ans[i]>0)
{anss+=(i+1000);cout<<i+1000<<endl;}
cout<<anss;
    return 0;
}
