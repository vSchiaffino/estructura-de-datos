#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<cmath>

#define R 3
int P;

using namespace std;

struct Nodo {
    int valor;
    struct Nodo* hijos[R];
};

int leer_en(int *arr, int i){
    if(i>=P)
        return -1;
    return *(arr + i);
}

// Usa la formula del apunte, pero solo cambie en vez de ceil, puse floor porque ahi funciona
int calcular_niveles(int* arr) {
    int nivel = -1;
    int i = 0;
    while(leer_en(arr, i) != -1){
        i = R * i + 1;
        nivel++;
    }
    return nivel;
}

int* leer_arbol(FILE* f){
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

int cantidad_nodos(FILE* f){
    fseek(f, 0, SEEK_END);
    int tamanio = ftell(f);
    return tamanio / sizeof(int);
}

int main(){
    // Busco |P| lo saco viendo la cantidad de bytes y diviendolo por los bytes que ocupa un nodo (sizeof(int))
    FILE *file = fopen("arbol", "r");
    P = cantidad_nodos(file);
    int* arbol = leer_arbol(file);

    int niveles = calcular_niveles(arbol);
    // cout << "niveles " << niveles << endl;
    
    free(arbol);
    return 0;
}