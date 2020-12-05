#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
//Importamos las librerias necesarias para el correcto funcionamiento del programa
int main(int argc, char *argv[]){
    pid_t pid1;//Creamos los dos procesos hijos
    int status1=0,status2=0;
    int my_pipe[2];//Creamos las pipes que usaremos para comunicar el proceso hijo con su padre


    if (pipe(my_pipe)==-1){ 
        fprintf(stderr, "Pipe Failed" ); 
        return 1; 
    } 
    //En caso de que no se creen las pipes lanzamos el mensaje de erro

    if((pid1=fork())==0){
        //Empezamos con el proceso del hijo 1
        close(my_pipe[0]);//El indice 0 de la tuberia indica que es de tipo lectura
        printf("Child %d\n", getpid());//Imprimimos el PID del hijo

        char buffer[240];
        strcpy(buffer,"Envio este mensaje a mi padre usando las pipes aprendidas en la practica 3\n");
        write(my_pipe[1],&buffer,sizeof(buffer));//Escribimos en el canal 1 del pipe el array con los resultados
        exit(EXIT_SUCCESS);//Terminamos el proceso hijo 1
        
    }else{//Proceso padre
        
            printf("Father%d\n", getpid());//Imprimimos el PID del proceso padre

            waitpid(pid1,&status1,2);//Esperamos a que el proceso del hijo 1 termine
            close(my_pipe[1]);//Cuando haya termiando el proceso del hijo 1 cerramos el canal de escritura del pipe

            char buffer[240];
            //Creamos los arrays que usaremos para leer los datos
            
            read(my_pipe[0],buffer,sizeof(buffer));//Leemos del canal 0 del pipe, los datos enviados desde el hijo 1
            printf(buffer);
    }
    return 0;//Terminamos el programa
}