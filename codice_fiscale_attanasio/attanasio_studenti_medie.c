#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define filest "studenti.txt"
#define MAX_LENGHT_NS 20

struct studenti_sei{
    char nome[MAX_LENGHT_NS];
    char cognome[MAX_LENGHT_NS];
    int media;
};

typedef struct studenti_sei STU;

int main(){
    FILE *fp;
    STU s[5];
    char name[MAX_LENGHT_NS];
    char surname[MAX_LENGHT_NS];
    char medium[5];
    int i = 0;

    fp = fopen(filest, "r");
    if(fp == NULL){
        printf("\nNada");
        return 0;
    }else{
        printf("\n ce sta");
    }
    while(fscanf(fp,"%s %s %s",name,surname,medium)){
        if(atoi(medium) > 6){
            strcpy(s[i].nome, name);
            strcpy(s[i].cognome, surname);
            s[i].media = atoi(medium);
            i++;
            if(i = 5)break;
        }
    }
    fclose(fp);

    for(int j = 0; j < i; j++)
        printf("\n STUDENTE :  %s %s MEDIA: %d",s[j].nome,s[j].cognome,s[j].media);
    
    printf("\n");
}