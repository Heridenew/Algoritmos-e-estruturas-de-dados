#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 50
#define MAX_LENGTH 50

void ordenar_strings_por_tamanho() {
    int n;
    scanf("%d\n", &n); 
    
    for (int i = 0; i < n; i++) {
        char linha[1000];
        char* strings[MAX_STRINGS];
        int num_strings = 0;
        
        fgets(linha, sizeof(linha), stdin);
        for (int k = 0; linha[k] != '\0'; k++) {
            if (linha[k] == '\n') {
                linha[k] = '\0';
                break;
            }
        }
        
        char* inicio = linha;
        while (*inicio) {
            while (*inicio == ' ') inicio++;  
            if (*inicio == '\0') break;  
            
            char* fim = inicio;
            while (*fim != ' ' && *fim != '\0') fim++;  
            
            int comprimento = fim - inicio;
            if (num_strings < MAX_STRINGS) {
                strings[num_strings] = (char*)malloc(comprimento + 1);
                strncpy(strings[num_strings], inicio, comprimento);
                strings[num_strings][comprimento] = '\0';  
                num_strings++;
            }
            inicio = fim;
        }
        
        // Bubble sort para ordenação por tamanho (do maior para o menor)
        for (int j = 0; j < num_strings - 1; j++) {
            for (int k = 0; k < num_strings - j - 1; k++) {
                int len1 = strlen(strings[k]);
                int len2 = strlen(strings[k + 1]);
                
                // Ordena apenas se o tamanho for diferente (maior primeiro)
                if (len1 < len2) {
                    char* temp = strings[k];
                    strings[k] = strings[k + 1];
                    strings[k + 1] = temp;
                }
            }
        }
        
        for (int j = 0; j < num_strings; j++) {
            printf("%s", strings[j]);
            if (j < num_strings - 1) printf(" ");
            free(strings[j]);  
        }
        printf("\n");
    }
}

int main() {
    ordenar_strings_por_tamanho();
    return 0;
}
