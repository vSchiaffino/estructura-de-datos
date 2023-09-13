#include <iostream>
#include <math.h>

using namespace std;
#define R 3

int random_int(int a, int b) {
    return rand() % (b - a + 1) + a;;
}

int nodos_totales(int i){
    // Usa la formula del apunte para saber los nodos totales
    return 
    (int)(pow((double)R,(double)(i + 1)) - 1) / 
    (R - 1);
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    if(argc < 2){
        perror("no ingresaste los niveles deseados del arbol");
        return 1;
    }
    int i = atoi(argv[1]);
    int numero_nodos = nodos_totales(i);
    FILE *file = fopen("arbol", "w");
    for (int j = 0; j < numero_nodos; j++)
    {
        int valor = 'a' + j;
        // int valor = random_int(0, 10000);
        // cout << "en j="<< j << "valor=" << valor << endl;
        fwrite(&valor, sizeof(int), 1, file);
    }
    fclose(file);
    return 0;
}