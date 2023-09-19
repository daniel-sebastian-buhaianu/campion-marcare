#include <stdio.h>
#include <stdlib.h>

#define NMIN 1
#define NMAX 255
#define SMIN 1
#define SMAX 255
#define KMIN 1
#define KMAX 255

int main()
{
	unsigned short N, S, K, nr, i, j;
	char *f, ok;

	FILE *fin = fopen("marcare.in", "r");

	if (!fin) { printf("Eroare marcare.in\n"); return 1; }

	fscanf(fin, "%hu %hu %hu", &N, &S, &K);

	if (N < NMIN || N > NMAX) { printf("Eroare valoare N\n"); return 2; }

	if (S < SMIN || S > SMAX) { printf("Eroare valoare S\n"); return 3; }

	if (K < KMIN || K > KMAX) { printf("Eroare valoare K\n"); return 4; }

	fclose(fin);

	f = (char*)calloc(N+1, sizeof(char));

	FILE *fout = fopen("marcare.out", "w");

	for (nr = 0, i = S, ok = 1; ok; i += K) {
		j = i%N == 0 ? N : i%N;

		if (f[j]) ok = 0;
		else {
			nr++, f[j] = 1;

			fprintf(fout, "%u ", j);
		}
	}

	fprintf(fout, "\n%u", N-nr);

	fclose(fout);

	free(f);

	return 0;
}
// scor 100
