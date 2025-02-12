#include <stdio.h>
#define MAX_SQUADRE 20
#define MAX_COGNOME 20
#define MAX_NOME 30
#define MAX_CALCIATORI 23

typedef struct{
    char cognome[MAX_COGNOME];
    int eta;
    int maglia;
    int presenze;
    int gol;
}Calciatore;

typedef struct{
    char squadra[MAX_SQUADRE];
    int punti;
    Calciatore calciatore[MAX_CALCIATORI];
}Squadra;

typedef Squadra Campionato[MAX_SQUADRE];


int main(){
    Campionato serie_a;
    Calciatore capocannoniere;
    Squadra squadra_capocannoniere;

    capocannoniere = serie_a[0].calciatore[0];
    squadra_capocannoniere = serie_a[0];

    for(int i = 0;i < MAX_SQUADRE;i++){
        for(int j = 0; j < MAX_CALCIATORI;j++){
            if(serie_a[i].calciatore[j].gol > capocannoniere.gol){
                capocannoniere = serie_a[i].calciatore[j];
                squadra_capocannoniere = serie_a[i];
            }
        }
    }
    printf("%s", capocannoniere.cognome);
    printf("%s", squadra_capocannoniere.squadra);
}