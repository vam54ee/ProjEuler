#include<iostream>
#include<fstream>
using namespace std;
int size;
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
int i=0;
for(;i<size&&b[i]!=-1;i++);
b[i]=a;
}
void remove()
{int i=0;
for(;i<size&&b[i]!=-1;i++);
b[i-1]=-1;
}

int has(int a)
{//cout<<a<<endl;
int i=0;
for(;i<size&&b[i]!=-1;i++)
if(b[i]==a)
return 1;
return 0;

}

void out()
{int i=0;
myfile<<k<<"\t";
for(;i<size&&b[i]!=-1;i++)
myfile<<b[i];
myfile<<"\r\n";
k++;
}

void permute(int length)
{
if(length==1)
{
int i=0;
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
{int i=0;
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
permute(size);
myfile.close();
    return 0;
}
