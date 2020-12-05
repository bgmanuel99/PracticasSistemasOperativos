#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *file=NULL;
    file=fopen("ejemplo","r");
    char buffer[20]="";
    int i;

    if(file == NULL ) {
     printf("No fue posible abrir el archivo\n");
     return -1;
   }

  fgets(buffer,20,file);
  
  //cerramos el archivo
  fclose(file);
  
  printf(buffer,"\n");
  
  return(0);

}