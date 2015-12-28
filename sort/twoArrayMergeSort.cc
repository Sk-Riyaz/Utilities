#include<stdio.h>

using namespace std;

int mergeSort ( int a[],int b[],int m,int n )
{
   static int c[100];
   int i=0,j=0,k=0;
   while( i<m && j<n )
   {
      if( a[i] <= b[j] )
      {
         c[k] = a[i];
         i++;k++;
      }
      else if ( b[j] <= a[i] )
      {
         c[k] = b[j];
         j++;k++;
      }
   }
   if( i < m )
   {
      while( i < m )
      {
         c[k]=a[i];
         i++;k++;
      }
   }
   if( j < n )
   {
      while( j < n )
      {
         c[k] = b[j];
         j++;k++;
      }
   }
  return 0;
}

int main( )
{
   int m,n;
   printf("Enter range for arrayA,arrayB:");
   scanf("%d%d",&m,&n);
   int a[m],b[n];
   printf("Enter numbers into arrayA:\n");
   for( int i=0;i<m;i++ )
      scanf("%d",&a[i]);

   printf("Enter numbers into arrayB:\n");
   for( int i=0;i<n;i++ )
      scanf("%d",&b[i]);
   
   int *c;
   c = mergeSort(a,b,m,n);
   printf("Sorted and merged array:\n");
   for ( int g=0;g<m+n;g++)
   {
      if( g != m+n-1 )
      {
         printf("%d ",*(c+g));
      }
      else
      {
         printf("%d\n",*(c+g));
      }
   }
  return 0;
}
