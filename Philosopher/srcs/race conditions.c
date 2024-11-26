#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int mails = 0;
pthread_mutex_t mutex;
void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char **argv)
{
    pthread_t t1,t2,t3;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
    if (pthread_create(&t3, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return 4;
    }
    if (pthread_join(t3, NULL) != 0)
    {
        return 4;
    }

    pthread_mutex_destroy(&mutex);
    printf("Number of Mails: %d\n", mails);
    return 0;
}