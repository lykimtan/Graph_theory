#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    f = fopen("test.txt", "r");
    if (f == NULL) {
        perror("Loi khi mo file");
        exit(EXIT_FAILURE);
    }

    int n;
    if (fscanf(f, "%d", &n) != 1) {
        fprintf(stderr, "Loi khi doc tu file");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", n);

    fclose(f);
    return 0;
}
