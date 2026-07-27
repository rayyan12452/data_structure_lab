#include <stdio.h>

int main() {
    int i, n;
    int t1 = 0, t2 = 1;
    int next_term = t1 + t2;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n >= 1)
        printf("%d ", t1);
    if (n >= 2)
        printf("%d ", t2);

    for (i = 3; i <= n; i++) {
        printf("%d ", next_term);
        t1 = t2;
        t2 = next_term;
        next_term = t1 + t2;
    }

    return 0;
}