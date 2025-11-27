#include <stdio.h>
#include <stdlib.h>

int clm(int len, int *arr);
int clm(int len, int *arr) {
	int c = 0;
	if (len == 1) { return 1; }
	if (arr[0] >= arr[1]) { c++; }
	if (arr[len - 1] >= arr[len - 2]) { c++; }
	for (int i = 1; i < len - 2; i++) {
		if ((arr[i] >= arr[i - 1]) && (arr[i] >= arr[i + 1])) { c++; }
	}
	return c;
}

int main(int argc, char **argv) {
	int N, ans;
	int *a;
	N = strtol(argv[1], NULL, 10);
	a = malloc(N * sizeof(int));
	if(a == NULL) { printf("malloc error\n"); return 1; }
	for (int i = 0; i < N; i++) {
		a[i] = strtol(argv[i + 2], NULL, 10);
	}

	ans = clm(N, a);
	printf("%d\n", ans);
	free(a);

	return 0;
}