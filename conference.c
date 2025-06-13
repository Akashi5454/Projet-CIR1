int genererFichiersHTML_Simple(int numFiles, const char *directory, const char *filePrefix) {
    char filename[256]; // Buffer pour stocker le chemin complet du fichier
    FILE *fp;           // Pointeur de fichier

    printf("Démarrage de la génération de %d fichiers HTML dans '%s'...\n", numFiles, directory);

    for (int i = 1; i <= numFiles; i++) {
        // Construit le nom complet du fichier.
        // Exemple: "./export/page_001.html"
        sprintf(filename, "%s%s%03d.html", directory, filePrefix, i);

        // Ouvre le fichier en mode écriture ("w")
        fp = fopen("../02fotw.data", "w");

        // Vérifie si l'ouverture du fichier a réussi
        if (fp == NULL) {
            perror("Erreur lors de l'ouverture du fichier"); // Affiche l'erreur système
            return -1; // Retourne une erreur et arrête la génération
        }

        // Écrit le contenu HTML de base
        fprintf(fp, "<!DOCTYPE html>\n");
        fprintf(fp, "<html lang=\"fr\">\n");
        fprintf(fp, "<head>\n");
        fprintf(fp, "    <meta charset=\"UTF-8\">\n");
        fprintf(fp, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
        fprintf(fp, "    <title>Page %d</title>\n", i);
        fprintf(fp, "</head>\n");
        fprintf(fp, "<body>\n");
        fprintf(fp, "    <h1>Ceci est la page numéro %d</h1>\n", i);
        fprintf(fp, "    <p>Ce fichier a été généré simplement par un programme C.</p>\n");
        fprintf(fp, "    <p>Son nom est : <strong>%s</strong></p>\n", filename);
        fprintf(fp, "</body>\n");
        fprintf(fp, "</html>\n");

        // Ferme le fichier
        fclose(fp);
        printf("  - Fichier créé : %s\n", filename);
    }

    printf("Génération terminée. %d fichiers HTML créés.\n", numFiles);
    return 0; // Succès
}
