#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define filest "comuni_imp.txt"
#define cgl 3
#define maxlenght 16

FILE *fp;                               //dichiarazione di un puntatore ad un file
char mesi[] = "ABCDEHLMPRST";
char codice_fiscale[maxlenght];
int i = 0;
int c = 0;
int len;
int cons = 0, vocs = 0;
char con[cgl];
char voc[cgl];
char cifre[5];

void controllo(char *parola){            
    len = strlen(parola);
    for(i=0; i<len; i++){
        if(toupper(parola[i]) == 'A' || toupper(parola[i]) == 'E' || toupper(parola[i]) == 'I' || toupper(parola[i]) == 'O' || toupper(parola[i]) == 'U'){
            voc[vocs] = parola[i];
            vocs++;
        } else {
            con[cons] = parola[i];
            cons++;
        }
    }
}

void cognome()                          //funzione che compone il cognome nel codice fiscale
{
    char cognome[len];
    printf("\nInserisci il tuo cognome: ");
    scanf("%s", cognome);

    controllo(cognome);

    if(cons >= 3){
        for(i = 0 ; i < cgl ; i++)
            codice_fiscale[i] = con[i];
    } else if(cons == 2){
        con[2] = voc[0];
        for(i = 0 ; i < cgl ; i++)
            codice_fiscale[i] = con[i];
    }else if(cons == 1 && vocs >= 2){
        con[1] = voc[0];
        con[2] = voc[1];
        for(i = 0 ; i < cgl ; i++)
            codice_fiscale[i] = con[i];
    }else if(cons == 1 && vocs == 1){
        con[1] = voc[0];
        con[2] = 'X';
        for(i = 0 ; i < cgl ; i++)
            codice_fiscale[i] = con[i];
    }else if(cons == 0 && vocs == 2){
        voc[2] = 'X';
        for(i = 0 ; i < cgl ; i++)
            codice_fiscale[i] = voc[i];
    }  
    cons = 0;
    vocs = 0;
    len = 0;
}

void nome(){                            
    char nome[len];
    printf("\nInserisci il tuo nome: ");
    scanf("%s", nome);
   
    controllo(nome);
   
    if(cons >= 4){
        codice_fiscale[3] = con[0];
        for(i = 4; i< cgl * 2; i++)
            codice_fiscale[i] = con[i - 2];
    } else if(cons == 3){
        for(i = 3 ; i < cgl * 2 ; i++)
            codice_fiscale[i] = con[i - 3];
    } else if(cons == 2){
        con[2] = voc[0];
        for(i = 3 ; i < cgl * 2 - 1 ; i++)
            codice_fiscale[i] = con[i - 3];
    }else if(cons == 1 && vocs >= 2){       
        con[1] = voc[0];
        con[2] = voc[1];
        for(i = 3 ; i < cgl * 2 ; i++)
            codice_fiscale[i] = con[i - 3];
    }else if(cons == 1 && vocs == 1){
        con[1] = voc[0];
        con[2] = 'X';
        for(i = 3 ; i < cgl * 2 ; i++)
            codice_fiscale[i] = con[i - 3];
    }else if(cons == 0 && vocs == 2){
        voc[2] = 'X';
        for(i = 3 ; i < cgl * 2 ; i++)
            codice_fiscale[i] = voc[i - 3];
    }
    len = 0;
}

void anno(){                                
    int anno_nascita;
    printf("\nInserisci il tuo anno di nascita: ");
    scanf("%d", &anno_nascita);
   
    sprintf(cifre , "%d" , anno_nascita);
   
    codice_fiscale[6] = cifre[2];
    codice_fiscale[7] = cifre[3];
}

void mese(){                                //funzione che compone la cifra del mese nel codice fiscale 

    int mese_utente;

    printf("\nInserisci il tuo mese di nascita (1-12) : ");
    scanf("%d", &mese_utente);

    while(mese_utente < 1 || mese_utente > 12){
        printf("\nERROR : il mese non esiste");
        printf("\nInserisci di nuovo il tuo mese di nacita: ");
        scanf("%d", &mese_utente);
    }

    codice_fiscale[8] = mesi[mese_utente - 1];
}

char sesso_giorno_nascita(){                //funzione che compone le due cifre relative all'anno di nascita del codice fiscale
   
    char sex[len];
    int giorno_nascita = 0;

    printf("\nInserisci il tuo sesso: ");
    scanf("%s", sex);
    printf("\nInserisci il giorno in cui sei nato: ");
    scanf("%d", &giorno_nascita);

    while(giorno_nascita < 1 || giorno_nascita > 31){
        printf("\nERROR : non puo essere");
        printf("\nInserisci d nuovo il giorno in cui sei nato: ");
        scanf("%d", &giorno_nascita);
    }
   
    sprintf(cifre , "%d" , giorno_nascita);
    if(sex[0] == 'M' || sex[0] == 'm' && giorno_nascita >= 10)
        sprintf(cifre , "%d" , giorno_nascita);
    else if((sex[0] == 'M' || sex[0] == 'm') && (giorno_nascita >= 1 && giorno_nascita < 10)){
            codice_fiscale[9] = '0';
            strncpy(codice_fiscale + 10,cifre,1);
            return 0;
    } else if(sex[0] == 'F' || sex[0] == 'f'){
        giorno_nascita = giorno_nascita + 40;
        sprintf(cifre , "%d" , giorno_nascita);
    }
    codice_fiscale[9] = cifre[0];
    codice_fiscale[10] = cifre[1];
    return 0;
}
char codici_catastali(){
    char comune[34];
    char riga[50];
    char codice_comunale[5],nome_comune[50];

    printf("\nInserisci il comune di dove sei originario: ");
    scanf("%s", comune);
   
    //assegnazione di un file esterno al puntatore dichiarato in precedenza
    fp = fopen(filest , "r");
   
    if(fp == NULL){
        printf("\nIl file potrebbe non esistere");
        return 0;
    }else{
        printf("\nFile letto correttamente");
    }
   
    while(fscanf(fp,"%s %s",codice_comunale,nome_comune) != EOF){
        if(strcmp(comune,nome_comune) == 0)
        break;
    }
    strncpy(codice_fiscale + 11,codice_comunale, 4);
    fclose(fp);
}
void carattere_alfabetico_controllo(){
   
    char numeri_pari[] = "0123456789nnnnnnnnnnnnnnnn";
    char lettere_pari[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numeri_dispari[] = "10nnn2n3n4nnn5n6n7n8n9nnn";
    char lettere_dispari[] = "BAKPLCQDREVOSFTGUHMINJWZYX";
    int somma = 0;

    for(i = 0; i < 16; i++){
        if(i % 2 != 0){
            for(int j = 0; j < strlen(lettere_pari); j++){
                if(toupper(codice_fiscale[i]) == lettere_pari[j] || toupper(codice_fiscale[i]) == numeri_pari[j] ){
                    somma += j;
                    break;
                }
            }
        }else if(i % 2 == 0){
            for(int j = 0; j < strlen(lettere_pari); j++){
                if(toupper(codice_fiscale[i]) == lettere_dispari[j] || toupper(codice_fiscale[i]) == numeri_dispari[j] ){
                    somma += j;
                    break;
                }
            }
        }
    }
    somma = somma % 26;
    codice_fiscale[15] = lettere_pari[somma];
}
void stampa_codice_fiscale(){
    printf("\nCODICE FISCALE: ");
    for(i = 0; i < maxlenght; i++){
        printf("%c", toupper(codice_fiscale[i]));
    }
    printf("\n");
}

void inverso(){
    char anno[3];
    int mese;
    char giorno[3];
   
    printf("Inserisci il tuo codice fiscale: ");
    scanf("%s", codice_fiscale);
   
    //nome e cognome
    printf("\nCOGNOME: %c%c%c",codice_fiscale[0] , codice_fiscale[1] , codice_fiscale[2]);
    printf("\nNOME: %c%c%c",codice_fiscale[3] , codice_fiscale[4] , codice_fiscale[5]);
   
    //anno di nascita
    strncpy(anno,codice_fiscale + 6,2);
    if(atoi(anno) < 25)
        printf("\nANNO: %d", 2000 + atoi(anno));
    else
        printf("\nANNO: %d", 1900 + atoi(anno));
       
    //mese di nascita
    for(i = 0; i <strlen(mesi); i++){
        if(codice_fiscale[8] == mesi[i])
            mese = i + 1;
    }
    printf("\nMESE: %d", mese);
   
    //giorno di nascita
    strncpy(giorno,codice_fiscale + 9,2);
    if(atoi(giorno) - 40 < 0)
        printf("\nGIORNO: %d",atoi(giorno));
    else
        printf("\nGIORNO: %d",atoi(giorno) - 40);
       
    char codice_catastale[] = {codice_fiscale[11],codice_fiscale[12],codice_fiscale[13],codice_fiscale[14],'\0'};
    char riga[30];
    char codice_catastale_file[5];

    //assegnazione di un file esterno al puntatore dichiarato in precedenza
    fp = fopen(filest,"r");
   
    if(fp == NULL)
        printf("\nfile non trovato");
    else
        printf("\nfile torvato");
       
    while(fscanf(fp,"%s %s",codice_catastale_file,riga)){
        if(strncmp(codice_catastale_file,codice_catastale,4) == 0)
            break;
    }
    printf("\nIL COMUNE DI ORIGINE: %s", riga);
    fclose(fp);
}

void main(){
    int scelta;
   
    printf("Inserisci un della seguenti opzioni: \n-calcolo codice fiscale (premi 1) \n-calcolo codice fiscale inverso (premi 2)\nInserisci:");
    scanf("%d", &scelta);
   
    switch(scelta){

        case 1:                             //nel caso in cui l'utente inserisce '1' verranno elaborate le funzioni per il calcolo del codice fiscale
        cognome();
        nome();
        anno();
        mese();
        sesso_giorno_nascita();
        codici_catastali();
        carattere_alfabetico_controllo();
        stampa_codice_fiscale();
        break;
   
        case 2:                             //nel caso in cui l'utente inserisce '2' verra elaborata la funzione per l'estrazione dei dati da un codice fiscale
        inverso();
        break;
    }
}