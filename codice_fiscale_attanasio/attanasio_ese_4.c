#include <stdio.h>

struct fig_geom{
    float area;
    float perimetro;
};

typedef struct fig_geom FIG;

FIG formule;

int triangolo(){
    float b, h;
    float lato3;
    printf("inserisci la base triangolo: ");
    scanf("%f", &b);
    printf("inserisci l' altezza del triangolo: ");
    scanf("%f", &h);

    printf("inserisci il terzo lato del tringolo: ");
    scanf("%f", &lato3);

    formule.area =  (b * h) /2;
    formule.perimetro = b + h + lato3;

    printf(" area: %f\n perimetro: %f\n", formule.area, formule.perimetro);
}

int rettangolo(){
    float ll, lc;
    printf("inserisci valore lato lungo del rettangolo: ");
    scanf("%f", &ll);
    printf("inserisci valore lato corto del rettangolo: ");
    scanf("%f", &lc);

    formule.area = ll * lc;
    formule.perimetro = ll * 2 + lc * 2;

    printf(" area: %f\n perimetro: %f\n", formule.area, formule.perimetro);
}

int quadrato(){
    float lato;
    printf("inserisci valore lato: ");
    scanf("%f", &lato);

    formule.area = lato * lato;
    formule.perimetro = lato * 4; 

    printf(" area: %f\n perimetro: %f\n", formule.area, formule.perimetro);
}
int cerchio(){
    float raggio;
    printf("inserisci valore raggio: ");
    scanf("%f", &raggio);

    formule.area = 3.14 * (raggio*raggio);
    formule.perimetro = 2 * raggio * 3.14;

    printf(" area: %f\n perimetro: %f\n", formule.area, formule.perimetro);
}
int main(void) {
    int scelta;

    printf("scegli la figura di cui vuoi conoscere area e perimetro: ");
    scanf("%d", &scelta);

    switch (scelta)
    {
        case 1:
        triangolo();
        break;

        case 2:
        rettangolo();
        break;

        case 3:
        quadrato();
        break;

        case 4:
        cerchio();
        break;

    default:
        break;
    }


    return 0;
}