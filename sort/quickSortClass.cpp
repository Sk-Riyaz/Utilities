#include "quickSort.hh"


template < typename T >
Sort< T >::Sort()
{

}

template < typename T >
Sort< T >::~Sort()
{

}

template < typename T >
void 
Sort< T >::typeName( char *formatSpecifier )
{
   if( typeid(T) == typeid(int) )
      strcpy( formatSpecifier,"%d" );
   else if( typeid(T) == typeid(long int) )
      strcpy( formatSpecifier,"%ld" );
   else if( typeid(T) == typeid(long long int) )
      strcpy( formatSpecifier,"%lld" );
   else if( typeid(T) == typeid(unsigned int) )
      strcpy( formatSpecifier,"%u" );
   else if( typeid(T) == typeid(unsigned long int) )
      strcpy( formatSpecifier,"%lu" );
   else if( typeid(T) == typeid(unsigned long long int) )
      strcpy( formatSpecifier,"%llu" );
   else if( typeid(T) == typeid(float) )
      strcpy( formatSpecifier,"%f" );
   else if( typeid(T) == typeid(double) )
      strcpy( formatSpecifier,"%f" );
   else
      printf("Unknown format\n");
}

template < typename T >
void
Sort< T >::printArray( const char *str,T a[], int high )
{
   char buff[10] = {'\0'};
   typeName( buff );

   printf("%s:",str);
   char formatSpecifier[30];
   for ( int i=0;i<=high;i++ )
   {
      memset( formatSpecifier, 0, 30 );
      sprintf( formatSpecifier, buff, a[i] );
      if( i == high )
      {
         printf("%s\n",formatSpecifier);
      }
      else 
      {
         printf("%s ",formatSpecifier);
      }
   }
}

template < typename T >
int 
Sort< T >::quickSort( T a[],int low,int high )
{
   int pivot = low;
   int i=pivot+1,j=high;
   bool swap = false;
   while( i<=j )
   {
      while( a[pivot] >= a[i] && i<=high )
         i++;
      while( a[pivot] < a[j] && j>=0 )
         j--;
      if( i < j )
      {
         T temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
      swap = true;
   }
   if( swap )
   {
      T temp = a[pivot];
      a[pivot] = a[j];
      a[j] = temp;
   }
   if ( low < high )
   {
      quickSort( a, low,j-1 );
      quickSort( a, j+1, high );
   }

   return 0;
}

#if 1
int main( )
{
   int n;
   printf("Enter range for array:");
   scanf("%d",&n);
   long long int a[n];
   printf("Enter numbers into array:");
   for( int i=0;i<n;i++ )
      scanf("%llu",&a[i]);

   Sort< long long int > sort;
   sort.quickSort( a,0,n-1 );
   sort.printArray( "Sorted Array",a,n-1 );

   return 0;
}
#endif
