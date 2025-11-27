#include <stdio.h>

int compare(char* ad);
int compare(char* ad) {
	FILE *f;
	int a, b, c;
	c = 1;
	f = fopen(ad, "r");
	if (f == NULL) { perror(ad); exit(2); }
	b = fscanf(f, "%d ", &a);
	if (b == 0) { printf("scanf error\n"); fclose(f); exit(3); }
	b = a;
	while ((fscanf(f, "%d ", &b) == 1) && (c == 1)) {
		if (b != a) { c = 0; }
	}
	fclose(f);
	if (c == 1) { return 1; }
	else { return 0; }
}

int main(void) {
	int n;
	char address[] = "test.txt";
	n = compare(address);
	if (n == 1) { printf("All equal"); }
	else { printf("Some differ"); }

	return 0;
}