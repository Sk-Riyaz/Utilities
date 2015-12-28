#include <time.h>
#include <algorithm>
#include "sort.hh"

using namespace std;
int main( )
{
   unsigned long long int n;
   printf("Enter range for array:");
   scanf("%llu",&n);
   printf("%zu",sizeof(n));
   unsigned long long int a[n];
   srand( time(NULL) );
   //printf("Enter numbers into array:");
   //for( unsigned long long int i=0;i<n;i++ )
   {
   //   a[i] = rand()%100000;
      //scanf("%d",&a[i]);
   }

   Sort< unsigned long long int > sort;

   clock_t begin,end;
   //sort.copy(a,n );
   //sort.printArray( "Before Sortint Array" );

   //sort.sort(a,n);
   //std::sort(b,b+n);
   //sort.copy(b,n );
   //sort.printArray( "After Sortint Array" );
   begin = clock();
   sort.quickSort( a,0,n );
   end = clock();
   //sort.printArray( "After sort:");
   printf("\n\nElapsed: %f sec\n", (double)(end - begin) / CLOCKS_PER_SEC);
   #if 0
   sort.bubbleSort( a,n,true );
   sort.mergeSort( c,0,n,true );
   #endif
   return 0;
}
