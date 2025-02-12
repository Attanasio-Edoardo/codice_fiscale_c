#include <stdio.h>

struct data{//creo struttura
int giorno;
int mese;
int anno;
};

void stampa(struct data d); //prototipo della funzione

int main(void)
{
    struct data d;//dichiarazione var di tipo struct
    printf("Inserisci una data (giorno, mese ed anno in cifre)\n");
    scanf("%d%d%d", &d.giorno, &d.mese, &d.anno);
    while (d.giorno < 1 || d.giorno > 31){
        printf("error: non possono esserci più di 31 giorni reinserisci:");
        scanf("%d",&d.giorno);
    }
    while (d.mese < 1 || d.mese > 12){
        printf("error: non possono esserci più di 12 mesi reinserisci:");
        scanf("%d",&d.mese);   
    }
    printf("La data inserita e':\n");
    stampa(d);
}

void stampa(struct data d)
{
    printf("%d ", d.giorno);
    char *mesi[12]={"gennaio","febbraio","marzo","aprile","maggio","giugno","luglio","agosto","settembre","ottobre","novembre","dicembre"};
    printf(" / %s / ", mesi[d.mese-1]);
    int anno=d.anno;
   
    if(d.anno < 1000)
    {
        if(d.anno<=24)
            anno=2000+anno;
        else
            anno=1900+anno;
    }
    printf("%d ", anno);
}