#include <stdio.h>

int main() {

    FILE *fp;
    float input;
    char nume[20];

    scanf("%s", nume);
    
    if (!(fp = fopen(nume, "wb"))) {

        printf("File Open Error!");
    } else {

        printf("Input number: ");
        scanf("%f", &input);
        while(!(feof(stdin))) {

            fwrite(&input, sizeof(float), 1, fp);
            printf("Input number: ");
            scanf("%f", &input);
        }
        fclose(fp);
    }

    return 0;
}