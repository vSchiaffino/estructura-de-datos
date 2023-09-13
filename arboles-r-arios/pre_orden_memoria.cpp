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

int leer_en(int *arr, int i){
    return *(arr + i);
}

// Usa la formula del apunte, pero solo cambie en vez de ceil, puse floor porque ahi funciona
int calcular_niveles(int n) {
    double log_n = log(n);
    double log_r = log(R);
    double resultado = log_n / log_r;
    return (int)(floor(resultado));
}

// Usa el pseudocodigo del apunte
void recorrido_pre_orden(int* arr, int P){
    int h = 0;
    // El stack va a ser representado con una lista, usando back() y pop_back() para el pop,
    // y push_back() para el push
    // Va a ser un array de dos posiciones, la primera posicion el valor del nodo y la segunda posicion
    // va a ser la posicion en el array
    vector<vector<int>> stack;
    stack.push_back({leer_en(arr, 0), 0});
    while(!stack.empty()){
        // x <- S
        vector<int> x = stack.back();
        char valor = x.at(0);
        int h = x.at(1);
        stack.pop_back();
        //  visitar(x)
        // cout << string(1, (char)valor) << endl;
        // Consigo el indice del primer hijo
        int t = R * h + 1;
        // Visito los hijos de forma descendente
        for (int i = t + R - 1; i >= t; i--)
        {
            if(i < P){
                int valor_hijo = leer_en(arr, i);
                stack.push_back({valor_hijo, i});
            }
        }
    }
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
    recorrido_pre_orden(arbol, P);
    
    free(arbol);
    return 0;
}