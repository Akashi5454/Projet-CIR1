#include "creFichierBase.h"


int genererFichiersHTML_Simple(int nombre) {
    char nomFichier[256];
    FILE *f;

    for (int i = 1; i <= nombre; i++) {
        sprintf(nomFichier, "../export/page_%03d.html", i);

        f = fopen(nomFichier, "w");


        fprintf(f, "<!DOCTYPE html>\n");
        fprintf(f, "<html lang=\"fr\">\n");
        fprintf(f, "<head><meta charset=\"UTF-8\"><title>Page %d</title></head>\n", i);
        fprintf(f, "<body>\n");
        fprintf(f, "<h1>Page numéro %d</h1>\n", i);
        fprintf(f, "<p>Nom du fichier : %s</p>\n", nomFichier);
        fprintf(f, "</body></html>\n");

        fclose(f);
        printf("✅ Fichier créé : %s\n", nomFichier);
    }

    printf("✅ Tous les fichiers HTML ont été générés.\n");
    return 0;
}