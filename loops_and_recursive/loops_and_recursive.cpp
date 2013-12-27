#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<pthread.h>

using namespace std;
int calculate( int m )
{
	int result = 0;
	for( int step=0; step<m+1; step++ )
	{
		result+=step;
	}
	return result;
}

int calculate_recursive( int m )
{
	if( 0>m ) {
		return -1;
	}
	if( 0==m ) {
		return 0;
	}
	return calculate_recursive(m-1)+m;
}

int calculate_recursive_thread()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	for( int i=10000; i<=100000; i++ )
	{
		int result = calculate_recursive( i );
		//cout<<result<<endl;
	}

	gettimeofday(&end, NULL);
	int interval = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	
	pthread_t tid;
	tid = pthread_self();
	cout<<"thread "<<(unsigned int)tid<<" recursive process time is:"<<(double)interval/1000.0<<endl;
}

int calculate_thread()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	for( int i=10000; i<=100000; i++ )
	{
		int result = calculate( i );
		//cout<<result<<endl;
	}

	gettimeofday(&end, NULL);
	int interval = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	
	pthread_t tid;
	tid = pthread_self();
	cout<<"thread "<<(unsigned int)tid<<" process time is:"<<(double)interval/1000.0<<endl;
}

void* calculate_create_thread(void *)
{
	calculate_thread();
}

void* calculate_recursive_create_thread(void *)
{
	calculate_recursive_thread();
}

int main()
{
	pthread_t calculate_thread;
	pthread_t calculate_recursive_thread;
	pthread_create(&calculate_thread, NULL, calculate_create_thread, NULL);
	pthread_create(&calculate_recursive_thread, NULL, calculate_recursive_create_thread, NULL);
	pthread_join(calculate_thread,NULL);
	pthread_join(calculate_recursive_thread,NULL);
}
