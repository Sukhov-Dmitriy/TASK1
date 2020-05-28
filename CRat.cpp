#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
void CRat::show(){
    for(int i = 0; i < this->dim*2; i++){
        cout <<data[i]<< endl;
    }
}


void CRat::operator= (const CRat& other){
    this->dim = other.dim;
    delete [] this->data;
    data = new int[dim * 2];
    for(int i = 0; i < dim*2; i++){
        this->data[i] = other.data[i];
    }
}
