#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>

#define R 2
int P;

using namespace std;

int nodos_totales(int i){
    // Usa la formula del apunte para saber los nodos totales
    return 
    (int)(pow((double)R,(double)(i + 1)) - 1) / 
    (R - 1);
}

unsigned int leer_en(FILE *file, int i){
    if(i>=P)
        return -1;
    int valor;
    fseek(file, i*sizeof(int), SEEK_SET);
    fread(&valor, sizeof(unsigned int), 1, file);
    return valor;
}

int buscar_valor(FILE *file, int valor)
{
    int index = -1;
    int i = 0;
    while (index == -1)
    {
        unsigned int valor_actual = leer_en(file, i);
        if (valor_actual == valor)
            index = i;
        if (valor < valor_actual)
            i = (2 * i + 1);
        else
            i = (2 * i + 2);
    }

    return index;
}


int cantidad_nodos(FILE* f){
    fseek(f, 0, SEEK_END);
    int tamanio = ftell(f);
    return tamanio / sizeof(int);
}

int main(int argc, char* argv[]){
    int valor_buscado = atoi(argv[1]);
    FILE *file = fopen("arbol", "r");
    P = cantidad_nodos(file);
    int index = buscar_valor(file, valor_buscado);
    // cout << "index: " << index << "valor: " << leer_en(file, index) << endl;
}