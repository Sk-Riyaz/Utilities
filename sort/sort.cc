//#include "quickSort.hh"

template < typename T >
Sort< T >::Sort()
{
   vArray.clear();
}

template < typename T >
Sort< T >::~Sort()
{
   vArray.clear();
}

template < typename T >
void
Sort< T >::copy( T a[],T n )
{
   vArray.clear();
   for( T i=0;i<n;i++ )
      vArray.push_back(a[i]);
}

template < typename T >
void
Sort< T >::copy( T a[],T b[],T n )
{
   for( T i=0;i<n;i++ )
      a[i] = b[i];
}

template < typename T >
bool
Sort< T >::compareArray( T a[] )
{
   size_t size = vArray.size();
   bool retVal = true;
   for( T i=0;i<size;i++ )
   {
      typename vector< T >::const_iterator it = find( vArray.begin(),
                                                      vArray.end(),
                                                      a[i] );
      if ( it == vArray.end() )
      {
         retVal = false;
         break;
      }
   }
   return retVal;
}

template < typename T >
void
Sort< T >::swap( T &a,T &b )
{
   T temp = a;
   a = b;
   b = temp;
}

template < typename T >
int
Sort< T >::sort( T a[],T n )
{
   T temp[n];
   copy( temp,a,n );
   printf("(1)BubbleSort "
          "(2)SelectionSort "
          "(3)InsertionSort "
          "(4)MergeSort "
          "(5)QuickSort\n");
   printf("Enter choice:");
   int ch,count=0;
   bool loop = true;
   do
   {
      count++;
      scanf("%d",&ch);
      bool Print = true;
      if( ch >=1 && ch <=5 )
      {
         char print[10];
         printf("Do you want to print the array(yes/no/y/n):");
         scanf("%s",print);
         if ( !strcmp("no",print) || !strcmp("n",print) )
         {
            Print = false;
         }
      }
      switch( ch )
      {
        case 1:
            {
               bubbleSort( a,n );
               print( temp,"BubbleSort",n,Print );
               loop = false;
            }
            break;
         case 2:
            {
               selectionSort( a,n );
               print( temp,"SelectionSort",n,Print );
               loop = false;
            }
            break;
         case 3:
            {
               insertionSort( a,n );
               print( temp,"InsertionSort",n,Print );
               loop = false;
            }
            break;
         case 4:
            {
               mergeSort( a,0,n );
               print( temp,"MergeSort",n,Print );
               loop = false;
            }
            break;
         case 5:
            {
               quickSort( a,0,n );
               print( temp,"QuickSort",n,Print );
               loop = false;
            }
            break;
         default:
            {
               if( count < 3 )
                  printf("I'm sorry please enter your choice:");
               else
               {
                  loop = false;
                  printf("I'm sorry wrong choice please try again later\n");
               }
            }
            break;
      }
   }while( loop );

   return 0;
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
   else if( typeid(T) == typeid(char) )
      strcpy( formatSpecifier,"%c" );
   else
      printf("Unknown format\n");
}

template < typename T >
void
Sort< T >::printArray( const char *str )
{
   char buff[10] = {'\0'};
   typeName( buff );

   printf("%s:",str);
   char formatSpecifier[30];
   size_t arraySize = vArray.size();
   for ( T i=0; i < arraySize; i++ )
   {
      memset( formatSpecifier, 0, 30 );
      sprintf( formatSpecifier, buff, vArray[i] );
      if( i == arraySize-1 )
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
void
Sort< T >::printArray( T a[],T arraySize )
{
   char buff[10] = {'\0'};
   typeName( buff );

   char formatSpecifier[30];
   for ( T i=0; i < arraySize ; i++ )
   {
      memset( formatSpecifier, 0, 30 );
      sprintf( formatSpecifier, buff, a[i] );
      if( i == arraySize-1 )
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
void
Sort< T >::print( T a[], const char *str,T size,bool Print )
{
   if ( !compareArray( a ) || vArray.size( ) != size )
   {
      printf("Something wrong with your %s\n",str);
      printf("Your array is:");
      printArray( a,size );
      printf("Your array size is:%u\n",size);
   }
   else
   {
      if( Print )
      {
         printArray( str );
      }
   }
}

template < typename T >
int 
Sort< T >::bubbleSort( T a[],T n )
{
   for( T i=0;i<n;i++ )
   {
      for( T j=i+1;j<n;j++ )
      {
         if( a[i] >= a[j] )
         {
            swap( a[i], a[j] );
         }
      }
   }
   copy( a,n );

   return 0;
}

template < typename T >
int 
Sort< T >::selectionSort( T a[],T n )
{
   T i=0,j=0;
   for( i=0; i<n; i++ )
   {
      T tempPos = 0;
      for( j=1; j<n-i ;j++ )
      {
         if( a[tempPos] <= a[j] )
         {
            tempPos = j;
         }
      }
      swap( a[tempPos], a[j-1] );
   }
   copy( a,n );

   return 0;
}

template < typename T >
int 
Sort< T >::insertionSort( T a[],T n )
{
   for( T i=0;i<n;i++ )
   {
      T j=i;
      while( j-1>=0 )
      {
         if( a[j] <= a[j-1] )
         {
            swap( a[j], a[j-1] );
         }
         j--;
      }
   }
   copy( a,n );

   return 0;
}

template < typename T >
int 
Sort< T >::quickSort( T a[],T low,T high )
{
   static unsigned long long int toPrint = 0;
   T pivot = low;
   T i=pivot+1,j=high-1;
   bool toSwap = false;
   toPrint++;
   while( i<=j )
   {
      while( a[pivot] >= a[i] && i<high )
         i++;
      while( a[pivot] < a[j] && j>=0 )
         j--;
      if( i < j )
      {
         swap( a[i], a[j] );
      }
      toSwap = true;
   }
   if( toSwap )
   {
      swap( a[pivot], a[j] );
   }
   if ( low < high-1 )
   {
      quickSort( a, low, j );
      quickSort( a, j+1, high );
   }

   toPrint--;
   if ( !toPrint )
   {
      copy( a,high );
   }

   return 0;
}

template < typename T >
int 
Sort< T >::mergeSort ( T a[],T low,T high )
{
   static unsigned long long int toPrint = 0;
   toPrint++;
   if( low < high-1 )
   {
      T j=low+(high-1-low)/2;
      mergeSort( a,low,j+1 );
      mergeSort( a,j+1,high );
      merge( a,low,j,high );
   }

   toPrint--;
   if ( !toPrint )
   {
      copy( a,high );
   }
   
   return 0;
}

template < typename T >
int 
Sort< T >::merge ( T a[],T l,T r,T n )
{
   T n1 = r-l+1;
   T n2 = n-1-r;

   T low[n1], high[n2];
   for( T i=0;i<n1;i++ )
   {
      low[i] = a[l+i];
   }
   for( T i=0;i<n2;i++ )
   {
      high[i] = a[r+i+1];
   }
   T i=0,j=0,k=l;
   while( i<n1 && j<n2 )
   {
      if( low[i] < high[j] )
      {
         a[k] = low[i];
         i++;
      }
      else if ( high[j] <= low[i] )
      {
         a[k] = high[j];
         j++;
      }
      k++;
   }
   while( i < n1 )
   {
      a[k]=low[i];
      i++;k++;
   }
   while( j < n2 )
   {
      a[k] = high[j];
      j++;k++;
   }

   return 0;
}

#if 0
int main( )
{
   int n;
   printf("Enter range for array:");
   scanf("%d",&n);
   long long int a[n];
   printf("Enter numbers into array:");
   for( int i=0;i<n;i++ )
      scanf("%llu",&a[i]);
   
   Sort< long long int,100 > sort;
   sort.quickSort( a,0,n-1 );
   sort.printArray( "Sorted Array",a,n-1 );

   return 0;
}
#endif
