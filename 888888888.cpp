//文件名:   array01.cpp 
#include<iostream> 
using   namespace   std; 
int   main() 
{ 
  int   len; 
  cin>>len; 
  //用指针p指向new动态分配的长度为len*sizeof(int)的内存空间 
  int   *p=new   int[len]; 
int a[len]={1,3,4,5};
  delete[]   p; 
  return   0; 
} 