#include "createFile.h"

void generate_html_sections(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        fprintf(stderr, "Chemin essayé : %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    char line[LINE_SIZE];
    FILE* current_section = NULL;
    int section_count = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  // Supprimer le saut de ligne

        if (strncmp(line, "<section>", 9) == 0) {
            if (current_section != NULL)
                end_section(current_section);

            section_count++;
            if (section_count > 350) {
                fprintf(stderr, "Erreur : plus de 350 sections détectées.\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }

            current_section = start_section(section_count);

        } else if (strncmp(line, "</section>", 10) == 0) {
            end_section(current_section);
            current_section = NULL;

        } else if (current_section != NULL) {
            fprintf(current_section, "<p>%s</p>\n", replace_links_only(line));
        }
    }

    if (current_section != NULL)
        end_section(current_section);

    fclose(file);
}




char* replace_links_only(const char* input) {
    static char output[2048];
    output[0] = '\0';

    const char* p = input;

    while (*p) {
        const char* start = strstr(p, "<a>");
        if (!start) {
            strcat(output, p);
            break;
        }

        // Copier tout ce qu'il y a avant <a>
        strncat(output, p, start - p);

        const char* end = strstr(start, "</a>");
        if (!end) {
            strcat(output, start);
            break;
        }

        // Contenu entre <a> et </a>
        char inner[256];
        int len = end - (start + 3);
        strncpy(inner, start + 3, len);
        inner[len] = '\0';

        // Cherche le premier nombre dans inner
        int number = 0;
        for (int i = 0; inner[i]; i++) {
            if (inner[i] >= '0' && inner[i] <= '9') {
                number = atoi(&inner[i]);
                break;
            }
        }

        char link[512];
        if (number > 0)
            sprintf(link, "<a href=\"sect%d.html\">%s</a>", number, inner);
        else
            sprintf(link, "<a>%s</a>", inner);

        strcat(output, link);
        p = end + 4; // après </a>
    }

    return output;
}

FILE* start_section(int section_number) {
    char filename[256];
    sprintf(filename, "export/sect%d.html", section_number);

    FILE* f = fopen(filename, "w");
    if (!f) {
        fprintf(stderr, "Impossible de créer le fichier <%s>\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(f,
        "<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "  <meta charset=\"UTF-8\">\n"
        "  <title>Section %d</title>\n"
        "  <link href=\"style.css\" rel=\"stylesheet\"/>\n"
        "</head>\n"
        "<body>\n"
        "<h1>Section %d</h1>\n",
        section_number, section_number
    );

    return f;
}

void end_section(FILE* file) {
    if (file) {
        fprintf(file, "</body>\n</html>\n");
        fclose(file);
    }
}












void generer_index() {
    char nomFichier[256];
    FILE *f;
    sprintf(nomFichier, "export/index.html");

        f = fopen(nomFichier, "w");


        fprintf(f, "<!DOCTYPE html>\n");
        fprintf(f, "<html lang=\"fr\">\n");
        fprintf(f, "<head><meta charset=\"UTF-8\"><title>Page 1</title></head>\n");
        fprintf(f, "<body>\n");
        fprintf(f, "<h1>Loup Solitaire</h1>\n" );
       fprintf(f, "<img src=\"https://media.pocketgamer.fr/images/news/2011/08/Lone-Wolf.png\" alt=\"Illustration Loup Solitaire\" />\n");
        fprintf(f, "<a href=\"../export/sect001.html\">commencer L'histoire</a>\n");
        
        fprintf(f, "</body></html>\n");

        fclose(f);
        printf("✅ Fichier créé : %s\n", nomFichier);


}
