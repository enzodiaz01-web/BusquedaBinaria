#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v(10); 
    for(int i = 0; i < v.size(); i++){
        v[i] = i; 
    }

    int numero_a_buscar = 0;
    int lower = 0;
    int upper = v.size() - 1;
    int half;
    bool buscar = false;
    //Trabajamos con N elementos en el vector, como la busqueda se basa en dividir el vector a la mitad (n/2) en cada iteracion,
    //por ende si el elemnto a buscar esta en la mitad vuelve a dividir (n/2)/2 y asi susesivamente hasta encontrar el elemento 
    // o agotar las posibilidades
    while(lower <= upper && !buscar){
        half = lower + (upper - lower) / 2; // <- n/2 despues (n/2)/2, llegando a la siguiente formula n/(2^k)=1
        if(v[half] == numero_a_buscar){ 
            buscar = true;
            cout << "Encontrado en la posicion: " << half << endl;
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
// Complejidad : O(log n)
//mejor caso: T(1) cuando el elemento buscado esta en la mitad del vector
//peor caso: T(log n + 1) cuando el elemento no esta en el vector o esta en los extremos del vector