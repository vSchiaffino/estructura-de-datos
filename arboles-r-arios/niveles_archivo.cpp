#include<iostream>
#include <vector>

using namespace std;

#define R 3
int P;
int veces;

int leer_en(FILE *file, int i){
    if(i >= P)
        return -1;
    veces++;
    int valor;
    fseek(file, i*sizeof(int), SEEK_SET);
    fread(&valor, sizeof(int), 1, file);
    return valor;
}

int calcular_niveles(FILE* file){
    int nivel = -1;
    int i = 0;
    while(leer_en(file, i) != -1){
        i = R * i + 1;
        nivel++;
    }
    return nivel;
}


int cantidad_nodos(FILE* f){
    fseek(f, 0, SEEK_END);
    int tamanio = ftell(f);
    return tamanio / sizeof(int);
}

int main(){
    FILE *file = fopen("arbol", "r");
    P = cantidad_nodos(file);
    int niveles = calcular_niveles(file);
    cout << niveles << endl;

    // cout << "tengo " << P << " nodos" << endl;
    // cout << "lei " << veces << " veces" << endl;
    // cout << "Niveles " << niveles << endl;
    return 0;
}