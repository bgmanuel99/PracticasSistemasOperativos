#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void){

    int fd, bytes_escritos;
    char buffer[100];
    mode_t modo=S_IRWXU;
    strcpy(buffer,"Esto es un ejemplo");

    if((fd=open ("ejemplo", O_RDWR | O_CREAT, modo))==-1){
        perror("Error al abrir o crear el fichero");
    }else{
        bytes_escritos=write(fd,buffer,strlen(buffer));
    }
    exit(0);
}