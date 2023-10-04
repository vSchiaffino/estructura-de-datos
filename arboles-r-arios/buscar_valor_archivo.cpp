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

unsigned int leer_en(FILE *file, int i){
    int valor;
    fseek(file, i*sizeof(int), SEEK_SET);
    int bytes_read = fread(&valor, sizeof(unsigned int), 1, file);
    if(bytes_read < 1)
        return -1;
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

int main(int argc, char* argv[]){
    int valor_buscado = atoi(argv[1]);


    FILE *file = fopen("arbol", "r");
    int index = buscar_valor(file, valor_buscado);
    // cout << "index: " << index << "valor: " << leer_en(file, index) << endl;
}