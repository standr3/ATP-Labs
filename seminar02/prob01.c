//===========================================================================
// Să se scrie un subprogram pentru crearea unui fișier text care să conțină 
// elemente reale (în fișier sunt memorate elementele unui vector – un 
// element pe fiecare linie). Se va oferi și un exemplu de utilizare.
//===========================================================================

#include <stdio.h>

void wArrayToFile(char *filename) {
    FILE *fp;
    float number;
    
    if (!(fp = fopen(filename, "w")))

        printf("File Open Error!");
    else {
        
        printf("Input number: ");
        scanf("%f", &number);
        while(!feof(stdin)) {

            fprintf(fp, "%.2f\n", number);
            printf("Input number: ");
            scanf("%f", &number);
        }
        printf("\n");
        fclose(fp);
    }
}

int main() {

    char filename[20];

    printf("Input filename: ");
    scanf("%s", filename);
    wArrayToFile(filename);

    return 0;
}