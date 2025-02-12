#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HITLER 200
#define filest "studenti.txt"

int main(){
    fp = fopen(filest, "r");
    char riga[200];

    if(fp == NULL){
        printf("\n Nada");
        return 0;
    }else{
        printf("\n JE STA");
    }

    while (fgets(riga, HITLER, fp))
    {
        printf("\n%s", riga)
        token = strtok(riga, ",");
        for(i = 0; i < strlen(token); i++){
            
        }
        i++;
    }
    printf("%s", riga);
    fclose(fp);
}
