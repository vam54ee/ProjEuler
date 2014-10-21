#include<iostream>
using namespace std;
int size;
char b=new int[size];
int k=725760;
void assign()
{
for(int i=0;i<size;i++)
b[i]=-1;
}
void push(int a)
{int i=0
for(;i<size&&b[i]!=-1;i++);
b[i]=a;
}
void remove()
{int i=0
for(;i<size&&b[i]!=-1;i++);
b[i-1]=-1;
}

int has(int a)
{int i=0
for(;i<size&&b[i]!=-1;i++)
if(b[i]==a)
return 1;
return 0;

}

void out()
{int i=0
for(;i<size&&b[i]!=-1;i++)
cout<<b[i];
cout<<endl;

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
{
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
{
size=3;
permute(size);
    return 0;
}
