#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    printf("Wykonuje polecenie za pomoca funkcji system()\n");
    system("echo Pospie sobie chwileczke");
    system("sleep 10");
    printf("Polecenie wywolane za pomoca system() zakonczylo sie\n");
    printf("Wykonuje polecenie za pomoca funkcji execlp()\n");
    execlp("sh", "sh", "-c", "echo Pospie sobie chwileczke && sleep 10 && echo 'Polecenie wywolane za pomoca execlp() zakonczylo sie'", NULL);
    return 0;
}



