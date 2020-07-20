#include <iostream>
class ArrInt{
private:

    int*   data;
    int tam; // tam;

public:
    ArrInt(int size, int A[]){         // Constructor
        data = new int[size];
        tam = size;
        for(int i=0;i<size;i++){
            data[i]=A[i];
        }
    }
    ~ArrInt() {               // Destructor
        delete[] data;
    }
    ArrInt(const ArrInt& other){ // constructor copia 
        data = new int[other.tam];  
        std::copy(other.data, other.data + other.tam, data);  
        tam = other.tam;
    }
    ArrInt& operator=(const ArrInt& other) { //operador de asignacion 
        if(this == &other) 
            return *this; 
        delete[] data; 
        data = new int[other.tam];
        std::copy(other.data, other.data + other.tam, data);
        tam = other.tam;
        return *this;   
    }
    //constructor de movimiento 
    ArrInt(ArrInt&& other) {//referencia de rvalue en entrada
        data = other.data; 
        tam = other.tam;
        other.data = nullptr; 
        other.tam = 0;
    }
    ArrInt& operator=(ArrInt&& other){//referencia de rvalue en entrada 
        if (this == &other) return *this;

        delete[] data;   

        data = other.data;  
        tam = other.tam;

        other.data = nullptr; 
        other.tam = 0;

        return *this;
    }
    void Print(int size){
        for(int i=0; i<size;i++){
            std::cout<<data[i]<<" ";
        }
    }
};
ArrInt crea_ArrInt(int size, int O[]){
    return ArrInt(size,O);
}
int main(){
    int A[]={1,2,3,4,5};
    int C[]={6,7,8,9,10};
    int D[]={11,12,13,14,15};
    ArrInt h1(15,A);    //constructor
    ArrInt h2(h1);        //constructor copia (lvalue en input)
    ArrInt h3 = crea_ArrInt(15,C); //constructor move (rvalue en input) 

    h2 = h3;      //operador de asignacion (lvalue en input)  
    h2 = crea_ArrInt(15,D);//operador de asignacion move(rvalue en input)
    h2.Print(15);
}
