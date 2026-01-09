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
    while(lower <= upper && !buscar){
        half = (lower + upper) / 2;
        if(v[half] == numero_a_buscar){ 
            buscar = true;
            cout << "Encontrado en la posicion: " << half << endl;
        }
        else if(v[half] > numero_a_buscar){ 
            upper = half - 1; 
        }
        else{ 
            lower = half + 1;
        }
    }
    if (!buscar) {
        cout << "El numero no esta en la lista." << endl;
    }
    return 0;
}