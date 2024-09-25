#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void convertToBase(int number, int base) {
    char result[65]; // Buffer para armazenar o resultado
    char digits[] = "0123456789ABCDEF"; // Dígitos possíveis para bases até 16
    int index = 0;

    // Tratamento para o caso do número ser zero
    if (number == 0) {
        printf("0\n");
        return;
    }

    // Conversão do número para a base desejada
    while (number > 0) {
        result[index++] = digits[number % base];
        number /= base;
    }

    // Impressão do resultado em ordem reversa
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n); // Leitura da quantidade de números a serem convertidos

    for (int i = 0; i < n; i++) {
        int x, b;
        scanf("%d %d", &x, &b); // Leitura do número e da base de destino
        convertToBase(x, b); // Conversão e impressão do resultado
    }

    return 0;
}


