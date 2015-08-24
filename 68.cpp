#include"bigint.h"
#include<fstream>
using namespace std;
int size;BigInt ans;
int* b=new int[size];
int k=1;
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
{int i=1,m=0,ck=1;BigInt ack;
myfile<<k<<"\t";
for(;i<size/2+1&&b[i]!=-1;i++)
m+=b[i];
//cout<<m<<endl;
if(m%(size/2)!=0)
return;
for(int f=1;f<size;f++)
{
if(!has(f))
{int x=(size-1)/2;
push(f);
int tot=b[x+1]+b[1]+b[2];
//cout<<tot<<endl;
for(int ff=2;ff<=x;ff++)
{int fff;
if(x+ff!=size-1)
fff=tot-b[ff]-b[ff+1];
else
fff=tot-b[ff]-b[1];
//cout<<tot<<"\t"<<x+ff<<"\t"<<fff<<endl;//<<"\t"<<b[x+1]<<"\t"<<b[1]<<"\t"<<b[2]<<endl;
if(fff<1||fff>=size)
{ck=0;break;}
if(!has(fff))
b[x+ff]=fff;
else
{ck=0;break;}
}
if(ck)
{int cc=(size-1)/2;string s="";
for(int i=1;i<=cc;i++)
{//cout<<"\t"<<b[cc+i]<<b[i]<<b[i+1];
if(b[cc+i]==10)
s+="10";
else
s+=(char)(b[cc+i]+'0');
if(b[i]==10)
s+="10";
else
s+=(char)(b[i]+'0');
if(i!=cc)
{
if(b[i+1]==10)
s+="10";
else
s+=(char)(b[i+1]+'0');
}
else
{
if(b[1]==10)
s+="10";
else
s+=(char)(b[1]+'0');
}
//cout<<b[i];
}

cout<<endl<<s<<endl;
ack=BigInt(s);
if(ans<ack)
{ans=ack;}//cout<<ans<<endl;}
}
/* for(int i=1;i<size;i++)
{cout<<b[i];}
cout<<endl;
 */
for(int ff=2;ff<=x;ff++)
{b[x+ff]=-1;}
remove();

}
}
//myfile<<b[i];
//myfile<<"\r\n";
k++;
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
size=11;
assign();
permute(5);
myfile.close();
    return 0;
}
