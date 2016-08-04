#include<stdio.h>
#include<ulimit.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    printf("%d\n",setrlimit(12));
    printf("%d\n",getrlimit());
    printf("%ld\n",sysconf(_SC_OPEN_MAX));
    return EXIT_SUCCESS;
}

