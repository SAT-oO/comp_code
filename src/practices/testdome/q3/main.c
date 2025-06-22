#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  
typedef struct Data
{
    int first;
    int second;
    int third;
} Data;

void *sum(void *arg)
{
    Data *arguments = (Data*) arg;
    int *result = (int*)malloc(sizeof(int));
    int i;
    *result = 0;
    for(i = arguments->first; i < arguments->second; i += arguments->third) 
    {
        *result += i;
    }
    return result;
}

int *run_in_parallel(int count, const Data *params, void *(*function)(void*))
{
    int *arr = (int*)malloc(sizeof(int) * count);

    for(int i = 0; i < count; i++){
        pthread_t *sums = (pthread_t*)malloc(sizeof(pthread_t));
        int num = pthread_create(sums, NULL, function, (void *) &params[i]);
        void *exit_status;
        pthread_join(*sums, &exit_status);

        arr[i] = *(int*)exit_status;
        

    }

    return arr;
}

#ifndef RunTests
int main()
{    
    Data params[] = {{0, 1000, 2}, {6, 2000, 3}};
    int *result = run_in_parallel(2, params, sum);
    printf("%d, %d", result[0], result[1]);
}
#endif