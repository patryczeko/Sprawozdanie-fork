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
    int powtorzen;
    int status = 0;
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
    if(pid_potomka > 0) while(wait_pid == 0)
    {
        printf("Czekam na zakonczneie potomka\n");
        wait_pid = waitpid(pid_potomka, &status, WNOHANG);
        sleep(1);
    }
    if(wait_pid > 0) printf("Pid potomka: %i\n", wait_pid);
    for(; powtorzen > 0; powtorzen--)
    {
        puts(komunikat);
        sleep(5);
    }
}


