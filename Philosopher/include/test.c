#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *routine()
{
    printf("Test from threads\n");

}
int main(int argc, char **argv)
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &routine, NULL);      //create a thread
    pthread_join(thread1, NULL); // wait for threads   wait they dont love me like i love you
    return 0;
}
