//===========================================================================
// Să se scrie programul care memorează într-un fişier text date despre 
// studenţii unei facultăţi. Pe fiecare linie se memorează: numărul matricol, 
// numele, prenumele, anul, grupa, cele 10 node obţinute la examene. Datele 
// sunt separate prin câte un spaţiu.
//===========================================================================

#include <stdio.h>

#define NR_NOTE 5

int main() {

	FILE *fp;
	char filename[20], stNume[30];
	int stNrMatricol, stAn, stGrupa, stNode[10], i;

	printf("Input filename: ");
	scanf("%s", filename);

	if (fp = fopen(filename, "w")) {

		printf("Numar matricol: ");
		scanf("%d", &stNrMatricol);
		while (!feof(stdin)) {

			getchar();
			printf("Nume student: ");
			gets(stNume);
			printf("Anul: ");
			scanf("%d", &stAn);
			printf("Grupa: ");
			scanf("%d", &stGrupa);
			for (i = 0; i < NR_NOTE; i++) {

				printf("Nota %d = ", i + 1);
				scanf("%d", &stNode[i]);
			}
			fprintf(fp, "%4d %-30s %d %4d ", stNrMatricol, stNume, stAn, stGrupa);
			for (i = 0; i < NR_NOTE; i++) 
			
				fprintf(fp, "%2d ", stNode[i]);
			fprintf(fp, "\n");
			printf("Numar matricol: ");
			scanf("%d", &stNrMatricol);
		}
		printf("\n");
		fclose(fp);
	} else {

		printf("Eroare");
	}
}
