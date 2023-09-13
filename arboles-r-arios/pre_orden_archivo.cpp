#include<iostream>
#include <vector>

using namespace std;

#define R 3


int leer_en(FILE *file, int i){
    int valor;
    fseek(file, i*sizeof(int), SEEK_SET);
    int bytes_read = fread(&valor, sizeof(int), 1, file);
    if(bytes_read < 1)
        return -1;
    return valor;
}

// Usa el pseudocodigo del apunte
void recorrido_pre_orden(FILE *file){
    int h = 0;
    // El stack va a ser representado con una lista, usando back() y pop_back() para el pop,
    // y push_back() para el push
    // Va a ser un array de dos posiciones, la primera posicion el valor del nodo y la segunda posicion
    // va a ser la posicion en el array
    vector<vector<int>> stack;
    stack.push_back({leer_en(file, 0), 0});
    while(!stack.empty()){
        // x <- S
        vector<int> x = stack.back();
        char valor = x.at(0);
        int h = x.at(1);
        stack.pop_back();
        //  visitar(x)
        cout << string(1, valor) << endl;
        // Consigo el indice del primer hijo
        int t = R * h + 1;
        // Visito los hijos de forma descendente
        for (int i = t + R - 1; i >= t; i--)
        {
            int valor_hijo = leer_en(file, i);
            // Si entra en este if, quiere decir que no tiene hijos
            if(valor_hijo != -1){
                // S <- Ri(x)
                stack.push_back({valor_hijo, i});
            }
        }
    }
}

int main(){
    FILE *file = fopen("arbol", "r");
    recorrido_pre_orden(file);
    return 0;
}