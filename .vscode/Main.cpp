#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v(10); 
    for(int i = 0; i < v.size(); i++){
        v[i] = i; 
    }

    int numero_a_buscar = 7;
    int lower = 0;
    int upper = v.size() - 1;
    int half;
    bool buscar = false;
    //Trabajamos con N elementos en el vector, como la busqueda se basa en dividir el vector a la mitad (n/2) en cada iteracion,
    //por ende si el elemento a buscar esta en la mitad se vuelve a dividir (n/2)/2 y asi susesivamente hasta encontrar el elemento 
    // o agotar las posibilidades
    while(lower <= upper && !buscar){
        half = lower + (upper - lower) / 2; // <- n/2 despues (n/2)/2, luego (n/2)/4 etc. O expresado de una forma mas general; n/(2^k)
        if(v[half] == numero_a_buscar){ // en el peor de los casos se reduce el arreglo a un solo elemento, pero aun se debe hacer una ultima iteracion para verificar si es el buscado o no
            buscar = true;              // llegando a la siguiente formula n/(2^k)=1, 
            cout << "Encontrado en la posicion: " << half << " |s el numero: "<< numero_a_buscar << endl;
        }
        else if(v[half] > numero_a_buscar){ 
            upper = half - 1; //<- reduce el rango de busqueda a la mitad izquierda
        }
        else{ 
            lower = half + 1;//<- reduce el rango de busqueda a la mitad derecha
        }
    }
    if (!buscar) {
        cout << "El numero no esta en la lista." << endl;
    }
    return 0;
}
// Mejor caso: T(1) cuando el elemento buscado esta en la mitad del vector
// Peor caso: T(log n + 1) cuando el elemento no esta en el vector o esta en los extremos del vector
// Complejidad : O(log n)