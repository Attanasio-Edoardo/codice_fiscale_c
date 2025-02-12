#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NOME 50
#define MAX_CORSI 10
#define MAX_STUDENTI 100
#define filest "studenti.txt"
#define filest_sec "risultato.txt"

FILE *fp;
int i = 0;

typedef struct corsi{
    char nome_corso;
    int voto;
}Corso;

struct studente{
    char nome[MAX_NOME];
    char cognome[MAX_NOME];
    int id;
    Corso corsi[MAX_CORSI];
    int num_corso;
    float media;
};

typedef struct studente STU;
STU alunni[MAX_STUDENTI];

char leggi_file(){
    fp = fopen(filest, "r");
    char riga[200];

    if(fp == NULL){
        printf("\n Nada");
        return 0;
    }else{
        printf("\n JE STA");
    }

    while (fgets(riga, 200, fp))
    {
        printf("\n%s", riga)
        token = strtok(riga, ",");
        for(i = 0; i < strlen(riga); i++){
            
        }
        i++;
    }
    printf("%s", riga);
    fclose(fp);
}

char media(){

}

char scrivi_file(){
    fp = fopen(filest_sec, "w");

    if(fp == NULL){
        printf("\n Nada");
        return 0;
    }else{
        printf("\n JE STA");
    }


}

int main(){
    leggi_file();
    media();
    scrivi_file();
}