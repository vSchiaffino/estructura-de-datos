#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>

#define R 2
#define MAX_VAL 1024

using namespace std;

bool isElementInVector(vector<unsigned int> vec, unsigned int element) {
    for (unsigned int item : vec) {
        if (item == element) {
            return true;
        }
    }
    return false;
}

unsigned int random_int(unsigned int a, unsigned int b) {
    return rand() % (b - a + 1) + a;
}

int nodos_totales(int i) {
    // Usa la formula del apunte para saber los nodos totales
    return (int)(pow((double)R, (double)(i + 1)) - 1) / (R - 1);
}

// void insertar(unsigned int *arr, int i, int nivel, int p) {
//     if (i >= p) {
//         return;
//     }

//     int indice_hijo_izq = R * i + 1;
//     int indice_hijo_der = indice_hijo_izq + 1;

//     cout << "soy " << i <<" hijo derecho: " << indice_hijo_der << " hijo izq: " << indice_hijo_izq << endl;

//     int dif = MAX_VAL / (pow(R, i+2));

//     cout << "nivel " << i << " da dif " << dif << endl;

//     *(arr+indice_hijo_izq) = *(arr+i) - dif;
//     *(arr+indice_hijo_der) = *(arr+i) + dif;

//     insertar(arr, indice_hijo_izq, nivel+1, p);
//     insertar(arr, indice_hijo_der, nivel+1, p);
// }

void insertar(unsigned int *arr, int i, int nivel, int p) {
    
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("No ingresaste los niveles deseados del árbol");
        return 1;
    }
    int nivel_max = atoi(argv[1]);
    int numero_nodos = nodos_totales(nivel_max);


    unsigned int *arr = (unsigned int *)malloc(sizeof(unsigned int) * numero_nodos);

    // Llenar el arr de null
    for (int j = 0; j < numero_nodos; j++) {
        *(arr + j) = 0;
    }
    
    (*arr) = MAX_VAL / 2;

    for (int nivel = 1; nivel <= nivel_max; nivel++)
    {
        int dif = MAX_VAL / (pow(R, nivel+1));

    }
    
    


    for (int j = 0; j < numero_nodos; j++) {
        cout << j << ": " << arr[j] << endl;
    }

    // int random_index = random_int(0, numero_nodos - 1);
    // cout << arr[random_index];

    // FILE *file = fopen("arbol", "w");
    // fwrite(arr, sizeof(unsigned int), numero_nodos, file);

    // fclose(file);
    // free(arr);
    return 0;
}