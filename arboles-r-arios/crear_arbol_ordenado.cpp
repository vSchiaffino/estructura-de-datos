#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>

#define R 2

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

int nodos_totales(int i){
    // Usa la formula del apunte para saber los nodos totales
    return 
    (int)(pow((double)R,(double)(i + 1)) - 1) / 
    (R - 1);
}

bool insertar(unsigned int *arr, unsigned int valor, int i, int p){
    if(i >= p){
        return false;
    }

    if(*(arr+i) == 0){
        *(arr+i) = valor;
        return true;
    }
    
    if(*(arr+i) > valor){
        // izq
        int hijo_izq = i * R + 1;
        insertar(arr, valor, hijo_izq, p);
    }
    else{
        // izq
        int hijo_der = i * R + 2;
        insertar(arr, valor, hijo_der, p);
    }
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    if(argc < 2){
        perror("no ingresaste los niveles deseados del arbol");
        return 1;
    }
    int i = atoi(argv[1]);
    int numero_nodos = nodos_totales(i);

    unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int)*numero_nodos);
    vector<unsigned int> lista;

    // Llenar el arr de null
    for (int j = 0; j < numero_nodos; j++)
    {
        *(arr + j) = 0;
    }

    for (int j = 0; j < numero_nodos; j++)
    {
        unsigned int valor;
        bool resultado = false;
        while(resultado == false){
            valor = random_int(1, 4294967295);
            if(isElementInVector(lista, valor)){
                continue;
            }
            resultado = insertar(arr, valor, 0, numero_nodos);
        }
        lista.push_back(valor);
        // cout << j <<" inserto " << valor << endl;
    }

    // for (int j = 0; j < numero_nodos; j++)
    // {
    //     cout << to_string(j) << ": " << to_string(arr[j]) << endl;
    // }

    // FILE *file = fopen("arbol", "w");
    // fclose(file);
    free(arr);
    return 0;
}

