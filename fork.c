#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    pid_t pid_potomka;
    pid_t wait_pid = 0;
    char *komunikat;
    int powtorzen, status;
    printf("Na razie dziala jeden proces\n");
    pid_potomka = fork();
    switch (pid_potomka) {
        case -1:
            printf("Rozwidlenie procesu nie powiodlo sie.\n");
            exit(1);
        case 0:
            komunikat = "Jestem potomkiem";
            powtorzen = 5;
            break;
        default:
            komunikat = "Jestem rodzicem";
            powtorzen = 5;
            break;
    }
    while((wait_pid = wait(&status)) > 0);
    if(pid_potomka > 0)
        printf("Pid potomka %i\n", pid_potomka);
    for(; powtorzen > 0; powtorzen--)
    {
        puts(komunikat);
        sleep(5);
    }
}


