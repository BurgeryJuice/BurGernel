#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *mythread(void *arg) {
    printf("%s\n", (char *) arg);
    printf("%d\n", (int) pthread_self());
    return NULL;
}

int main(int argc, char *argv[]) {                    
    if (argc != 1) {
	fprintf(stderr, "usage: main\n");
	exit(1);
    }
    pid_t pidl;
    pidl = fork();
    if (pidl < 0) {
        perror("fork");
        exit(1);
    } else if (pidl == 0) {
        printf("child: begin\n");
        pthread_t p1, p2;
        pthread_create(&p1, NULL, mythread, "A"); 
        pthread_create(&p2, NULL, mythread, "B");
        pthread_join(p1, NULL); 
        pthread_join(p2, NULL); 
        printf("child: end\n");
        exit(0);
    }
    wait(NULL);
    pthread_t p1, p2;
    printf("main: begin\n");
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    printf("main: end\n");
    return 0;
}
