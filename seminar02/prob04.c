//===========================================================================
// Să se scrie programul care calculează media studenţilor integralişti şi 
// cea mai mare dintre mediile studenţilor integralişti din fişierul creat 
// anterior.
//===========================================================================

#include<stdio.h>

int main() {

	FILE* fp;
	char filename[30], stNume[30];
	int stNrMatricol, stAn, stGrupa, stNote[10], i, numar_intg, ok;
	float medie, meds, medmax;

	printf("Input filename:");
	scanf("%s", filename);

	if (!(fp = fopen(filename, "r"))) {

        printf("File Open Error!\n");
    } else {

		numar_intg = 0;
		medie = 0;
		medmax = 0;
		fscanf(fp, "%d", &stNrMatricol);
		while (!feof(fp)) {

			fscanf(fp, "%s %d %d ", stNume, &stAn, &stGrupa);
			meds = 0;
			ok = 0;
			for (i = 0; i < 10; i++) {

				fscanf(fp, "%d", &stNote[i]);
				if (stNote[i] < 5) 

                    ok = 1;
				meds = meds + stNote[i];
		    }

			if (!ok) {

				numar_intg++;
				meds = meds / 10;
				medie = medie + meds;
				if (meds > medmax) 
                    
                    medmax = meds;
            }
			fscanf(fp, "%d", &stNrMatricol);
		}
		fclose(fp);
    }
	if (numar_intg == 0) {

        printf("Nu exista studenti integralisti");
    } else {

		printf("Media maxima este %f si media studentilor integralisti este %f", 
                medmax, medie / numar_intg);
	}

    return 0;
}