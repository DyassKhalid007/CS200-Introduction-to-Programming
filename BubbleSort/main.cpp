#include <iostream>

using namespace std;

int main()
{
   int swap=-2;
   int arr[]={99,2,1,6,4,100};
   while(swap!=0)
   {
       swap=0;

       for(int i=0;i<7-1;i++)
       {
           if(arr[i]<arr[i+1])
           {
               int temp=arr[i+1];
               arr[i+1]=arr[i];
               arr[i]=temp;
               swap++;
           }
       }
   }
   for(int i=0;i<6;i++)
   {
       cout<<arr[i]<<endl;
   }

}
