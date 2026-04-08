#include <stdio.h>
#include <stdlib.h>

int main(){
    char input_1[50];
    char extra_1;
    int n;

    printf("Digite o tamanho do array: ");

    while (fgets(input_1, sizeof(input_1), stdin)) {
        if (sscanf(input_1, "%d %c", &n, &extra_1) == 1 && n > 0) {
            break;
        } else {
            printf("Tamanho inválido!\nDigite o tamanho do array: ");
        }
    }

    char input_2[50];
    char extra_2;
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    for (int i = 0; i < n; i++){
        do{
            printf("Digite o %d° número: ", i+1);
            if (!fgets(input_2, sizeof(input_2), stdin)) {
                printf("Erro na leitura!\n");
                free(arr);
                return 1;
            }
            if (sscanf(input_2, "%d %c", &arr[i], &extra_2) != 1){
                printf("Valor inválido!\n");
            } else {
                break;
            }
        } while(1);
    }

    for (int j = 0; j < n; j++){
        printf("%d° elemento: %d\n", j+1, arr[j]);
    }
    free(arr);
    arr = NULL;
    return 0;
}
