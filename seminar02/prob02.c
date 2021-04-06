//===========================================================================
// Să se scrie un subprogram pentru preluarea vectorului în memorie. 
// Se va scrie și programul apelator.
//===========================================================================

#include <stdio.h>


void rFileToArray(char *filename, float v[], int *n)
{
	FILE* fp;
	float number;

	if (fp = fopen(filename, "r")) {
		
		*n = 0;
		fscanf(fp, "%f", &number);
		while (!feof(fp)) {

			v[(*n)] = number;
			(*n)++;
			fscanf(fp, "%f", &number);
		}
		fclose(fp);
	} else {

		printf("File Open Error!\n");
	}
}

int main() {

    char filename[20];
	float a[20];
	int length, i;
	
	printf("Introduceti numele fisierului: ");
	scanf("%s", filename);
	rFileToArray(filename, a, &length);
	for (i = 0; i < length; i++)

		printf("%4.1f\n", a[i]);
	
	return 0;
}