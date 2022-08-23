#include <stdio.h>
#define size 8
int main() {
	int N = 0;
	int M = 0;
	scanf("%d %d", &N, &M);
	char chess[53][53] = { 'a' };
	for (int i = 0; i < N; i++) {
		scanf("%s", chess[i]);
	}

	int a, b, i, j, r;
	int min_r = 1000;
	for (a = 0; a + size <= N; a++) {
		for (b = 0; b + size <= M; b++) {
			char f = chess[a][b];
			char s = (chess[a][b] == 'B') ? 'W' : 'B';
			r = 0;
			for (i = a; i < a + size; i++) {
				for (j = b; j < b + size; j++) {
					int odd = (i + j) % 2; 
					if ((odd == 0 && chess[i][j] != f) || (odd == 1 && chess[i][j] != s))
						r++; 
				}
			}
			r = (size*size - r < r) ? size*size - r : r;
			if (min_r > r) 
				min_r = r;
		}

	}
	printf("%d", min_r);
}
