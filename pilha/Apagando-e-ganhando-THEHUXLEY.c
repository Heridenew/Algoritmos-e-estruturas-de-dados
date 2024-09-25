#include <stdio.h>
#include <string.h>

void findMaxNumber(char *number, int N, int D) {
    int keep = N - D; // Quantidade de dígitos a manter
    char stack[N];
    int top = -1;

    for (int i = 0; i < N; i++) {
        while (top >= 0 && stack[top] < number[i] && D > 0) {
            top--;
            D--;
        }
        if (top < keep - 1) {
            stack[++top] = number[i];
        } else {
            D--;
        }
    }

    stack[keep] = '\0';
    printf("%s\n", stack);
}

int main() {
    int N, D;
    char number[100001];

    while (1) {
        scanf("%d %d", &N, &D);
        if (N == 0 && D == 0) break;

        scanf("%s", number);
        findMaxNumber(number, N, D);
    }

    return 0;
}
