#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    pid_t pid, pid1, pid2, pid3;

    for(int i = 0; i < 4 ; i++){ // Creamos los 4 primeros hijos del nodo raiz
        switch (pid = fork())
        {
        case 0:
            printf("PID hijo: %d, PID padre: %d\n",getpid(),getppid());
            if(i==0||i==1){
                for(int j = 0; j < 2; j++){ // Creamos dos nuevos hijos para los hijos 1 y 2 del nodo raiz
                    switch(pid1 = fork()){
                    case 0:
                        printf("PID hijo: %d, PID padre: %d\n",getpid(),getppid());
                        // Creamos un ultimo hijo para el primer hijo de los hijos 1 y 2 del nodo raiz
                        if(j == 0){
                            switch(pid3 = fork()){
                            case 0:
                                printf("PID hijo: %d, PID padre: %d\n",getpid(),getppid());
                                break;
                            case -1:
                                printf("ERROR");
                                exit(-1);
                            default:
                                break;
                            }
                            if(pid3 == 0) break;
                        }
                        break;
                    case -1:
                        printf("ERROR");
                        exit(-1);
                    default:
                        break;
                    }
                    if(pid1 == 0) break;
                }
            }else if(i==2){
                //Crea el hijo 3
                switch(pid2 = fork())
                {
                case 0:
                    printf("PID hijo: %d, PID padre: %d\n",getpid(),getppid());
                    break;
                case -1:
                    printf("ERROR");
                    exit(-1);
                default:
                    break;
                }
                if(pid2 == 0) break;
            }
            break;
        case -1:
            printf("ERROR");
            exit(-1);
        default:
            break;
        }
        if(pid == 0) break;
    }

    

    return 0;
}