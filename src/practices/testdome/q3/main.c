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
    Data *arguments = (Data *)arg;
    int *result = (int *)malloc(sizeof(int));
    if(!result){
        perror("malloc failed");
        pthread_exit(NULL);
    }
    int i;
    *result = 0;
    for (i = arguments->first; i < arguments->second; i += arguments->third)
    {
        *result += i;
    }
    return result;
}

int *run_in_parallel(int count, const Data *params, void *(*function)(void *))
{
    int *arr = (int *)malloc(sizeof(int) * count );
    pthread_t *sums = (pthread_t *)malloc(sizeof(pthread_t) * count );
    void **res = (void **)malloc(sizeof(void *) * count);

    for (int i = 0; i < count; i++)
    {

        int num = pthread_create(&sums[i], NULL, function, (void *)&params[i]);
    }
    for(int i = 0; i < count; i++){
        pthread_join(sums[i], &res[i]);
        arr[i] = *(int *)res[i];
        free(res[i]);
    }

    free(sums);
    free(res);

    return arr;
}

#ifndef RunTests
int main()
{
    Data params[] = {{0, 1000, 2}, {6, 2000, 3}};
    int *result = run_in_parallel(2, params, sum);
    printf("%d, %d\n", result[0], result[1]);
}
#endif