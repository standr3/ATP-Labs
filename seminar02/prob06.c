#include <stdio.h>

int main() {

    FILE *fp;
    char filename[20];
    float input;

    printf("Introdu numele fisierului: ");
    scanf("%s", filename);

    if (!(fp = fopen(filename, "rb"))) {

    printf("eroare");
    } else {

        fread(&input, sizeof(float), 1, fp);
        while(!feof(fp)) {

            printf("%f \n", input);
            fread(&input, sizeof(float), 1, fp);
        }
        fclose(fp);
    }
    return 0;
}
