#include "lecture.h"

int main(void) {

    FILE *file = fopen("../02fotw.data", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
    }
    else {
        printf("All good !");
    }


    fclose(file);
    return 0;
}