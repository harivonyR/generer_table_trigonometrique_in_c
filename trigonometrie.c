#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trigonometrie.h"

#define PI 3.14159265358979323846

void generer_table_trigo_csv(char *file_name){
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Erreur ouverture fichier");
        exit(EXIT_FAILURE);
    }

    // Header CSV (propre)
    fprintf(file, "Angle(deg),Sinus,Cosinus,Tangente\n");

    // Header console aligné
    printf("%-10s %-12s %-12s %-12s\n", "Angle", "Sinus", "Cosinus", "Tangente");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i <= 360; i++) {
        double x = i * PI / 180.0;

        double s = sin(x);
        double c = cos(x);

        double t;
        if (fabs(c) < 1e-10) {
            t = NAN;  
        } else {
            t = tan(x);
        }

        // données séparées par des virgules pour le CSV
        fprintf(file, "%d,%.5f,%.5f,%.5f\n", i, s, c, t);

        // alignement des données pour la console
        printf("%-10d %-12.5f %-12.5f %-12.5f\n", i, s, c, t);
    }

    fclose(file);
}