#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

template<typename T>
int find(T array[], int length, T value)
{
	int index = 0;
	for( ; index<length; index++ )
	{
		if( value == array[index] )
		{
			return index;
		}
	}
	return -1;
}

int find_by_pointer(int array[], int length, int value)
{
	int index = 0;
	int* current_p = array;
	int* end = array + length;
	while( current_p < end )
	{
		if( *current_p == value )
		{
			return current_p - array;
		}
		current_p++;
	}
	return -1;
}

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = array;
	//assert( 5 == find( array, 10, 4 ) );
	cout << find<int>( array, 10, 4 ) << endl;
	cout << find_by_pointer( array, 10, 8 ) << endl;
	printf( "address of array is[%08x]\n", array );
	printf( "address of array is[%08x]\n", &array );
	printf( "address of array_1 is[%08x]\n", array + 1 );
	printf( "address of array_0 is[%08x]\n", &array[0] );
	printf( "p_0 is[%08x]\n", p );
	printf( "address of p_0 is[%08x]\n", &p );
}
