#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 30
#define G 2
/*Realizzare in C un elenco che contiene per ciascuno studente:
il nome, il cognome, l’età, e la media che ha conseguito a fine anno. 

L’utente, inizialmente deve inserire i dati e poi attraverso un menù deve consentire le seguenti operazioni:
1- Stampa media dei voti con nome e cognome degli alunni;

2- Visualizzazione della media di un alunno specifico
3- Visualizzazione della media di tutti gli alunni
4- Visualizzazione dei dati degli alunni con voto>=6
5- Visualizzazione dei dati degli alunni con voto<6
6- Uscita dal programma

Numero degli studenti da considerare 5
Materie: Italiano, Matematica, Informatica, Storia, Inglese.
Ricorda: utilizzo delle funzioni.*/

struct studenti{
    char nome[L];
    char cognome[L];
    float media;
    float ita;
    float mate;
    float info;
    float sto;
    float ing;
};

typedef struct studenti STU;
typedef struct medie MED;

STU arr[G]; 

int inserimento_studenti(){
    for(int i = 0; i < G ; i++){
        printf("Inserisci il nome dello studente %d :", i);
        scanf("%s", arr[i].nome);
        printf("Inserisci il cognome dello studente %d", i);
        scanf("%s", arr[i].cognome);
        printf("Inserisci la media in matemagica dello studente");
        scanf("%f", &arr[i].mate);
        printf("Inserisci la media in infoplay dello studente");
        scanf("%f", &arr[i].info);
        printf("Inserisci la media in stocapipapara dello studente");
        scanf("%f", &arr[i].sto);
        printf("Inserisci la media in inglish dello studente");
        scanf("%f", &arr[i].ing);
        printf("Inserisci la media in itaxdante dello studente");
        scanf("%f", &arr[i].ita);
    }

    return 0;
}
float media(){
    for(int i = 0;i < G;i++){
    arr[i].media = (arr[i].mate + arr[i].ita + arr[i].sto + arr[i].ing + arr[i].info) / 5;
    }
}
int stampa_mnc(){
    for(int i = 0;i < G; i++){
        printf("ALLUNO %d: %s %s %f \n",i, arr[i].nome,arr[i].cognome, arr[i].media);
    }
    return 0;
}
int media_alunni(){
    for(int i = 0;i < G; i++){
        printf("ALLUNO %d: %f \n",i,arr[i].media);
    }
    return 0;
}

int stampa_alu_specifico(){
    char name[20];
    char surname[20];

    printf("Inserisci nome dell'alunno di cui vuoi vedere la media: ");
    scanf("%s",name);
    printf("\ncognome:");
    scanf("%s",surname);
    for(int i = 0; i < G; i++){
        printf("\narr[i] = %s %s", arr[i].nome, arr[i].cognome);
        printf(" %s ",name);
        if(arr[i].nome == name && arr[i].cognome == surname ){
            printf("\nciao");
            printf("MEDIA: %f",arr[i].media);
            break;
        }
    }
}

int main(){
    int scelta;

    inserimento_studenti();
    printf("Inserisci cosa vuoi fare: \n");
    scanf("%d", &scelta);
    media();
    switch (scelta){
        case 1:
        stampa_mnc();
        break;

        case 2:
        stampa_alu_specifico();
        break;

        // case 3:
        // media_alunni();
        // break;

        // case 4:
        // voto_mag_6();
        // break;

        // case 5:
        // voto_min_6();
        // break;

        // case 6:
        // return 0;
        // break;
    }
}