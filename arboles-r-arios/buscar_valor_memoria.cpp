#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>

#define R 2

using namespace std;

int nodos_totales(int i){
    // Usa la formula del apunte para saber los nodos totales
    return 
    (int)(pow((double)R,(double)(i + 1)) - 1) / 
    (R - 1);
}

unsigned int leer_en(int *arr, int i, int P){
    if(i>=P)
        return -1;
    return *(arr + i);
}

int* leer_arbol(FILE* f, int P){
    int* arr = (int*)malloc(sizeof(int) * P);
    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < P; i++)
    {
        int valor;
        fread(&valor, sizeof(int), 1, f);
        *(arr+i) = valor;
    }
    
    return arr;
}

int buscar_valor(int *arr, int valor, int P)
{
    int index = -1;
    int i = 0;
    while (index == -1)
    {
        unsigned int valor_actual = leer_en(arr, i, P);
        if (valor_actual == valor)
            index = i;
        if (valor < valor_actual)
            i = (2 * i + 1);
        else
            i = (2 * i + 2);
    }

    return index;
}

int main(int argc, char* argv[]){
    int valor_buscado = atoi(argv[1]);

    FILE *file = fopen("arbol", "r");
    fseek(file, 0, SEEK_END);
    int tamaño = ftell(file);
    int P = tamaño / sizeof(int);
    int* arr = leer_arbol(file, P);

    int index = buscar_valor(arr, valor_buscado, P);
    // cout << "index: " << index << " " << "valor: " << leer_en(arr, index, P) << endl;
}