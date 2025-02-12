#include <stdio.h>
#include <math.h>

struct s_punto{
    float punto_x;
    float punto_y;
};

typedef struct s_punto punti_xy; 
int main(){
    float distanza;
    punti_xy p;
    printf("Inserisci l'ascissa  X:");
    scanf("%f", &p.punto_x);
    printf("Inserisci l'ordinata  Y:");
    scanf("%f", &p.punto_y);

    distanza = sqrt(pow(p.punto_x,2)+pow(p.punto_y,2));

    printf("DISTANZA: %f\n",distanza);
    return 0;
}