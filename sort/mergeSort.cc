#include<stdio.h>

int merge ( int a[],int l,int r,int n )
{
   int n1 = r-l+1;
   int n2 = n-r;

   //printf("In Merge call:left=%d,  right=%d,a[right]=%d, high=%d \n",l,r,a[r],n );
   int left[n1], right[n2];
   for( int i=0;i<n1;i++ )
   {
      left[i] = a[l+i];
   }
   for( int j=0;j<n2;j++ )
   {
      right[j] = a[r+1+j];
   }

   #if 0 //for debugging
   printf("left:"); 
   for(int i=0;i<n1;i++)
      printf("%d ",left[i]);

   printf("\nhigh:"); 
   for(int i=0;i<n2;i++)
      printf("%d ",right[i]);
   printf("\n"); 
   #endif

   int i=0,j=0,k=l;
   while( i<n1 && j<n2 )
   {
      if( left[i] <= right[j] )
      {
         a[k] = left[i];
         i++;
      }
      else
      {
         a[k] = right[j];
         j++;
      }
      k++;
   }
   
   while( i < n1 )
   {
      a[k]=left[i];
      i++;
      k++;
   }

   while( j < n2 )
   {
      a[k] = right[j];
      j++;
      k++;
   }
   #if 0
   printf("ARRAY:"); 
   for(int i=l;i<n+1;i++)
      printf("%d ",a[i]);
   printf("\n\n"); 
   #endif

   return 0;
}

int mergeSort ( int a[],int low,int high )
{
   static int rl=0;
   //printf("low=%d  high=%d,l=%d \n",
     //       low,high,rl++);

   if( low < high )
   {
      int j=low+(high-low)/2;
      //printf("Before MergeSort left  call:low=%d,  j=%d \n",low,j );
      mergeSort( a,low,j );
      //printf("Before MergeSort right call:low=%d,  j=%d \n",j+1,high );
      mergeSort( a,j+1,high );
      //printf("Before Merge call:low=%d,  j=%d,high=%d \n",low,j,high );
      merge( a,low,j,high );
   }
   return 0;
}

void printArray( int a[], int n)
{
   for( int i=0;i<n;i++ )
      printf("%d ",a[i]);
   printf("\n");
}

int main()
{
   int arr[100];
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);

   mergeSort(arr, 0, n-1);

   printf("Sorted array is \n");
   printArray(arr, n);
   return 0;
}
