#pragma warning(disable:4996) 
#include <stdio.h> 
#include <conio.h> 
#include <time.h> 
#include <stdlib.h> 

int main()
{
	int i, j, chislo, cnt = 0;
	int cont = 0;
	float A[31][2];
	FILE *fp;
	srand(time(NULL));
	printf("Vvedite chislo: ");
	while (scanf("%d", &chislo) != 1) {
		printf("Again: ");
		flushall();
	}
	fp = fopen("Bagazh.txt", "w");
	for (i = 1; i < 31; i++) {
		for (j = 0; j < 2; j++) {
			if (j == 0) A[i][j] = rand() % 50 + 1;
			else A[i][j] = (float)(rand() % 50 + 1) / (rand() % 10 + 1);
			fscanf(fp, "%f", &A[i][j]);
		}
	}
	fprintf(fp, "\t\t Kol-vo: Ves(kg):\n"); printf("\t Kol-vo: Ves(kg):\n");
	for (i = 1; i < 31; i++) {
		printf("Passenger%d: ", i); fprintf(fp, "Passenger%d: ", i);
		for (j = 0; j < 2; j++) {
			if (j == 0) { printf("%7g", A[i][j]); fprintf(fp, "%7g", A[i][j]); }
			else { printf("%7.3g", A[i][j]); fprintf(fp, "%7.3g", A[i][j]); }
			if (A[i][j] == chislo && (j == 0)) {
				++cnt;
			}
			else if (A[i][j] > chislo && (j == 1)) {
				++cont;
			}
		}
		printf("\n"); fprintf(fp, "\n");
	}
	printf("\nKoli4estvo passajirov imeushee zadannoe kol-vo veshei: %d\n\n", cnt); printf("Koli4estvo passajirov ves bagazha kotorih bolshe zadannogo: %d\n\n\n", cont);
	fprintf(fp, "\nKoli4estvo passajirov imeushee zadannoe kol-vo veshei: %d\n\n", cnt); fprintf(fp, "Koli4estvo passajirov ves bagazha kotorih bolshe zadannogo: %d\n\nVvedennoe chislo - %d", cont, chislo);
	fclose(fp);
	_getch();
}