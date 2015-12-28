#include <stdio.h>
#include <stdlib.h>

using namespace std;

template < typename T >
int print( const char *str,T a[], int high )
{
   printf("%s:",str);
   char buff[30] = {'\0'};
   for ( int i=0;i<=high;i++ )
   {
      if( i == high )
      {
         printf("%lld\n",a[i]);
      }
      else 
      {
         printf("%lld ",a[i]);
      }
   }
   return 0;
}

int quickSort( long long int a[],int low,int high )
{
   int pivot = low;
   int i=pivot+1,j=high-1;
   bool swap = false;
   while( i<=j )
   {
      while( a[pivot] >= a[i] && i<high )
         i++;
      while( a[pivot] < a[j] && j>=0 )
         j--;
      if( i < j )
      {
         long long int temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
      swap = true;
   }
   if( swap )
   {
      long long int temp = a[pivot];
      a[pivot] = a[j];
      a[j] = temp;
   }
   if ( low < high-1 )
   {
      quickSort( a, low,j );
      quickSort( a, j+1, high );
   }

   return 0;
}

int main( )
{
   int n;
   printf("Enter range for array:");
   scanf("%d",&n);
   long long int a[n];
   printf("Enter numbers into array:");
   for( int i=0;i<n;i++ )
      scanf("%lld",&a[i]);

   //int *c;
   quickSort( a,0,n );
   print( "Sorted Array",a,n-1 );

   return 0;
}
