#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readstr(void);
char *readstr(void) {
	char *str;
	int ch, len;
	len = 0;
	str = malloc(1);
	if (!str) return str;
	ch = getchar();
	while (ch != '\n') {
		str[len] = (char)ch;
		len++;
		str = realloc(str, len);
		if (!str) return str;
		ch = getchar();
	}
	str[len] = '\0';
	return str;
}

int main(void) {
	FILE *f, *g;
	int c, t;
	char *namef, *nameg;
	errno_t err;

	namef = readstr();
	if (!namef) { printf("malloc error\n"); return 2; }
	nameg = readstr();
	if (!nameg) { printf("malloc error\n"); free(namef); return 2; }

	err = fopen_s(&f, namef, "r");
	if (err != 0) { printf("Error opening source file: %s\n", strerror(err)); free(namef); free(nameg); return 1; }
	err = fopen_s(&g, nameg, "a");
	if (err != 0) { printf("Error opening target file: %s\n", strerror(err)); free(namef); free(nameg); fclose(f); return 1; }
	
	while ((c = fgetc(f)) != EOF) {
		t = fputc(c, g);
		if (t == EOF) { printf("fputc error\n"); fclose(f); fclose(g); free(namef); free(nameg); return 3; }
	}

	printf("done!\n");
	fclose(f);
	fclose(g);
	free(namef);
	free(nameg);
	return 0;
}