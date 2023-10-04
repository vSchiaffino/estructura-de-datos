#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>

#define R 2
#define MAX_VAL 4294967296
// #define MAX_VAL 1024

using namespace std;

unsigned int random_int(unsigned int a, unsigned int b) {
    return rand() % (b - a + 1) + a;
}

int nodos_totales(int i) {
    // Usa la formula del apunte para saber los nodos totales
    return (int)(pow((double)R, (double)(i + 1)) - 1) / (R - 1);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc < 2) {
        perror("No ingresaste los niveles deseados del árbol");
        return 1;
    }
    int nivel_max = atoi(argv[1]);
    int numero_nodos = nodos_totales(nivel_max);

    unsigned int *arr = (unsigned int *)malloc(sizeof(unsigned int) * numero_nodos);
    
    (*arr) = MAX_VAL / 2;

    for (int nivel = 1; nivel <= nivel_max; nivel++)
    {
        int dif = MAX_VAL / (pow(R, nivel+1));
        int nodos_nivel = pow(R, nivel);
        bool resta = true;
        int indice_base = 0;
        for(int j = 0;j < nodos_nivel;j++){
            int inicio_nivel_anterior = pow(2, nivel-1)-1;
            int mod_inicio = j / 2;
            int indice = pow(2, nivel) + j - 1;
            int valor_base = arr[inicio_nivel_anterior + mod_inicio];
            int menos = (indice % 2 == 1) ? -1 : 1;
            int valor = valor_base + menos * dif;

            *(arr+indice) = valor;
        }
    }

    unsigned int inicio_nivel_final = pow(2, nivel_max)-1;

    cout << arr[inicio_nivel_final];
    FILE *file = fopen("arbol", "w");
    fwrite(arr, sizeof(unsigned int), numero_nodos, file);

    fclose(file);
    free(arr);
    return 0;
}