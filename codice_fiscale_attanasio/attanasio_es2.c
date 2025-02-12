#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codice[10];
    char data[11]; 
    char segni[14];
} Giocata;

int filtraGiocate(const Giocata* giocate, int numGiocate, Giocata* giocateFiltrate, int anno, int mese) {
    int count = 0;
    char annoMese[8];
    sprintf(annoMese, "%04d-%02d", anno, mese);

    for (int i = 0; i < numGiocate; ++i) {
        if (strncmp(giocate[i].data, annoMese, 7) == 0) {
            giocateFiltrate[count++] = giocate[i];
        }
    }
    return count;
}

int main() {
    int numGiocate = 5;
    Giocata giocate[5] = {
        {"G001", "2024-05-01", "1X21X21X21X21X"},
        {"G002", "2023-04-12", "121X121X121X12"},
        {"G003", "2024-05-15", "X21X21X21X21X2"},
        {"G004", "2022-03-22", "12X12X12X12X12"},
        {"G005", "2024-05-30", "1X21X21X21X21X"}
    };

    int anno, mese;
    printf("Inserisci l'anno (YYYY): ");
    scanf("%d", &anno);
    printf("Inserisci il mese (MM): ");
    scanf("%d", &mese);

    Giocata giocateFiltrate[5];
    int numGiocateFiltrate = filtraGiocate(giocate, numGiocate, giocateFiltrate, anno, mese);

    printf("Giocate filtrate per %04d-%02d:\n", anno, mese);
    for (int i = 0; i < numGiocateFiltrate; ++i) {
        printf("Codice: %s, Data: %s, Segni: %s\n", giocateFiltrate[i].codice, giocateFiltrate[i].data, giocateFiltrate[i].segni);
    }

    return 0;
}
