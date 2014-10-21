void prime(int *b,int upplimit,int& size_of_array=0){
b=new int[upplimit];
b[0]=1;
b[1]=2;b[2]=3;
size_of_array=3;
 for(int i=5;size_of_array<=upplimit;i+=2)
 {int x=1;
 for(int c=1;c<size_of_array;c++)
 if(i%b[c]==0)
 x=0;
 if(x)
 {b[size_of_array]=i;size_of_array++;}
 }
}