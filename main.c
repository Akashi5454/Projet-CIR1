#include "lecture.h"

int main(void) {

    FILE *file = fopen("../02fotw.data", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
    }
    else {
        printf("All good !");
    }

    int a = 1 ;
    char* section = &"sect"[a++] ;
    for (int i = 0 ; i < 350 ; i++) {
        startSect(section);
    }

    FILE *file2 = fopen("../coucou.html", "w");
    fclose(file);
    return 0;
}