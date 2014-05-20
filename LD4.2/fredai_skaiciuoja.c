/* Vardenis Pavardenis KTU varpav */
/* Failas: loginas_pipe02.c */

/*
 * CS170: 
 * print4.c -- forks off THREADS threads that print their ids
 */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#define THREADS 4

int Ego()
{
	int return_val;

	return_val = (int)pthread_self();

	return(return_val);
}

void *printme(void *arg)
{
	printf("Hi.  I'm thread %d\n", Ego());
	return NULL;
}

int factorial(int num)
{
    int sum=1;
    int count;
    
    if(num > 0) {
        for(count=1;count<=num;count++)
        {
            sum = sum*count;
        }
    } else if(num < 0) {
        for(count=num;count<0;count--)
        {
            sum = sum*count;
        }
    } else {
        return 0;
    }
    
    return sum;
}

int main()
{
	int i;
	int *vals;
	pthread_t *tid_array;
	void *retval;
	int err;
	int fk;

	vals = (int *)malloc(THREADS*sizeof(int));
	if(vals == NULL)
	{
		exit(1);
	}

	tid_array = (pthread_t *)malloc(THREADS*sizeof(pthread_t));
	if(tid_array == NULL)
	{
		exit(1);
	}

	for (i = 0; i < THREADS; i++) 
	{
		err = pthread_create(&(tid_array[i]), NULL, printme, NULL);
		if(err != 0)
		{
			fprintf(stderr,"thread %d ",i);
			perror("on create");
			exit(1);
		}
			
    }

    sleep(2);
	for (i = 0; i < THREADS; i++) 
	{

		printf("I'm %d\n", (int)tid_array[i]);
    	fk = factorial((int)tid_array[i]);
    	printf("\tFactorial: %d\n", fk);
  	}

	free(tid_array);

	return(0);
}


