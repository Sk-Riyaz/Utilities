#include <stdio.h>

int insertionSort( int a[], int n )
{
   for( int i=0;i<n;i++ )
   {
      int j=i;
      while( j-1>=0 )
      {
         if( a[j] <= a[j-1] )
         {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
         }
         j--;
      }
   }
   return 0;
}

int main()
{
   int a[100]={0},n;
   scanf("%d",&n);
   for( int i=0;i<n;i++)
      scanf("%d",&a[i]);
   
   insertionSort( a,n );

   printf("\nMAIN:\n");
   for( int i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
   return 0;
}
