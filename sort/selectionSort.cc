#include<stdio.h>

int selectionSort( int a[],int n )
{
   int i=0,j=0;
   for( i=0; i<n; i++ )
   {
      int tempPos = 0;
      for( j=1; j<n-i ;j++ )
      {
         if( a[tempPos] <= a[j] )
         {
            tempPos = j;
         }
      }

      int temp = a[tempPos];
      a[tempPos] = a[j-1];
      a[j-1] = temp;

   }
   //for( int i=0;i<n;i++)
      //printf("%d ",a[i]);
   return 0;
}

int main()
{
   int n,a[100];
   scanf("%d",&n);

   for( int i=0;i<n;i++ )
      scanf("%d",&a[i]);
   selectionSort( a,n );
   for( int i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");

   return 0;
}
