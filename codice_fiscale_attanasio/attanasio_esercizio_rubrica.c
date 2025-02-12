#include <stdio.h>
#include <string.h>
#define NC 5
#define CN 30
#define filest "rubrica.txt"

struct contatto{
    char nome[CN];
    char cognome[CN];
    char num_tel[10];
};

typedef struct contatto CON;
CON contatti[NC];

int L = 0;
FILE *fp;

char aggiungiContatto(){
    printf("\nInserisci il nome del contatto:");
    scanf("%s", contatti[L].nome);

    printf("\nInserisci il cognome del contatto:");
    scanf("%s", contatti[L].cognome);

    printf("\nInserisci il numero di telefono del contatto:");
    scanf("%s", contatti[L].num_tel);

    L++;
}

char visualizzaContatto(){
    for(int i = 0;i < NC; i++){
        printf("\nCONTATTO[%d] = %s %s %s",i,contatti[i].nome,contatti[i].cognome,contatti[i].num_tel);
    }
}

char cercaContatto(){
    char name[CN];
    printf("\nInserisci il nome della persona di cui vuoi il contatto");
    scanf("%s", name);
    for(int i = 0; i < NC; i++){
        if(strcmp(contatti[i].nome, name) == 0){
            printf("\nNUMERO DI TELEFONO: %s", contatti[i].num_tel);
        }
    }
}

char aggiungiInFile(){
    fp = fopen(filest, "w");

    if(fp == NULL)
        printf("\nfile non trovato");
    else
        printf("\nfile torvato");
    
    for(int i = 0;i < NC; i++){
        fprintf(fp,"\nCONTATTO[%d] = %s %s %s",i,contatti[i].nome,contatti[i].cognome,contatti[i].num_tel);
    }
    fclose(fp);
}

int main(){
    int scelta;
    
    do{
        printf("\nInserisci cosa vuoi fare: \n");
        scanf("%d", &scelta);
        switch(scelta){

            case 1:
            aggiungiContatto();
            break;
            
            case 2:
            visualizzaContatto();
            break;

            case 3:
            cercaContatto();
            break;

            case 4:
            break;

            default:
            printf("ERROR: non valido");
        }
    }while(scelta != 4);
    aggiungiInFile();
}