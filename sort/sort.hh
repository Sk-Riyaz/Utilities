#ifndef _SORT_
#define _SORT_

#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <cstring>
#include <vector>

using namespace std;

template < typename T >
class Sort
{
   private:
      vector < T >vArray;

      int merge( T a[],T l,T r,T n ); 

   public:
      Sort ();
      ~Sort ();
      void copy( T a[],T n );
      void copy( T a[],T temp[],T n );
      bool compareArray( T a[] );
      void swap( T &a,T &b );
      
      void typeName( char *formatSpecifier );
      void printArray( const char *tilte );
      void printArray( T a[],T arraySize );
      void print( T a[],const char *str,T size,bool Print );

      int sort( T a[],T n );
      int quickSort( T a[],T low,T high );
      int mergeSort( T a[],T low,T high );
      int bubbleSort( T a[],T n );
      int selectionSort( T a[],T n );
      int insertionSort( T a[],T n );
};

#include "sort.cc"

#endif
