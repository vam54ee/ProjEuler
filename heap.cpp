#include<iostream>
using namespace std;
#define max(a,b) (a>b)?a:b
void swap(int& a,int& b)
{
     int temp=b;
     b=a;
     a=temp;
 }


void heapify(int* array,int length=10,int index=1)
{
int left=2*index;
int right=left+1;
int max=index;
//cout<<array[left]<<endl;
     if(right<length)
  { if(array[left]>array[index]||array[right]>array[index])
   {max=(array[index]>array[left])?(array[index]>array[right]?index:right):(array[left]>array[right]?left:right);
   if(max!=index)
   {swap(array[max],array[index]);
   heapify(array,length,max);
   }//cout<<((array[2*index]==array[index])?2*index:2*index+1)<<endl;
   }  }
   else if(left<length)
   if(array[left]>array[index])
   {//cout<<array[left]<<endl;
   swap(array[left],array[index]);
   //heapify(array,length,2*index);
   }
 }
 void buildheap(int* array,int length)
 {for(int i=length-1;i>0;i--)
{heapify(array,length,i);}

  } 
  void heapsort(int* array,int length)
  {
       buildheap(array,length);
       for(int i=length-1;i>1;i--)
       {swap(array[i],array[1]);
       heapify(array,i,1);
   }}
int main()
{
//int* arr=new int[10];
int arr[11]={0,4,1,3,2,16,9,10,14,8,7};
//for(int i=0;i<10;i++)
//{arr[i]=i;cout<<arr[i]<<"\t";}
//cout<<endl;
heapsort(arr,11);
for(int i=1;i<11;i++)
{cout<<arr[i]<<"\t";}
cout<<endl;
    system("pause");
    return 0;
}
