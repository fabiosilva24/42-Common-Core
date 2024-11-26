#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *routine()
{
    printf("testing threads\n");
    sleep(3);
    printf("done testing\n");
}

int main(int argc, char **argv)
{
    pthread_t t1,t2,t3,t4,t5;

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, &routine, NULL);
    pthread_join(t3, NULL);
    pthread_create(&t4, NULL, &routine, NULL);
    pthread_join(t4, NULL);
}