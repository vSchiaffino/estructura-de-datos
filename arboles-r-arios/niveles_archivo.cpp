#include<iostream>
#include <vector>

using namespace std;

#define R 3

// Usa la formula del apunte, pero solo cambie en vez de ceil, puse floor porque ahi funciona
int calcular_niveles(FILE* file) {
    // Busco |P| lo saco viendo la cantidad de bytes y diviendolo por los bytes que ocupa un nodo (sizeof(int))
    fseek(file, 0, SEEK_END);
    int tamaño = ftell(file);
    int n = tamaño / sizeof(int);
    // Ahora uso la formula, aplicando propiedades de logaritmo
    double log_n = log(n);
    double log_r = log(R);
    double resultado = log_n / log_r;
    return (int)(floor(resultado));
}

int leer_en(FILE *file, int i){
    int valor;
    fseek(file, i*sizeof(int), SEEK_SET);
    int bytes_read = fread(&valor, sizeof(int), 1, file);
    if(bytes_read < 1)
        return -1;
    return valor;
}

int main(){
    FILE *file = fopen("arbol", "r");
    cout << "Niveles " << calcular_niveles(file) << endl;
    return 0;
}