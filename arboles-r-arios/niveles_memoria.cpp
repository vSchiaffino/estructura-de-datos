#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<cmath>

#define R 3

using namespace std;

struct Nodo {
    int valor;
    struct Nodo* hijos[R];
};

int leer_en(int *arr, int i, int P){
    if(i>=P)
        return -1;
    return *(arr + i);
}

// Usa la formula del apunte, pero solo cambie en vez de ceil, puse floor porque ahi funciona
int calcular_niveles(int* arr, int P) {
    int nivel = -1;
    int i = 0;
    while(leer_en(arr, i, P) != -1){
        i = R * i + 1;
        nivel++;
    }
    return nivel;
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

int main(){
    // Busco |P| lo saco viendo la cantidad de bytes y diviendolo por los bytes que ocupa un nodo (sizeof(int))
    FILE *file = fopen("arbol", "r");
    fseek(file, 0, SEEK_END);
    int tamaño = ftell(file);
    int P = tamaño / sizeof(int);
    int* arbol = leer_arbol(file, P);

    int niveles = calcular_niveles(arbol, P);
    // cout << "niveles " << niveles << endl;
    
    free(arbol);
    return 0;
}