#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
CRat0::CRat0(const CRat0 &other){// конструктор копирования
    this->dim = other.dim;
    data = new int[dim * 2];
    for(int i = 0; i < dim*2; i++){
        this->data[i] = other.data[i];
    }
}
CRat0::CRat0(int d){
    dim = d;
    data = new int[dim*2];
    for(int i = 0; i< dim*2; i++){
        data[i] = 0;
    }
}
CRat0::CRat0(){
    dim = 2;
    cout << "Введите размерность( 2 по умолчанию): ";
    cin >> dim;
    data = new int[dim*2];
    for(int i = 0; i< dim*2; i++){
        data[i] = 0;
    }
}
CRat0 CRat0::operator + (const CRat &B){
        CRat0 rat(B.dim);
        for(int i = 0; i< (B.dim*2);i+=2){
        rat.data[i] = ((this->data[i])*(B.data[i+1]))+((B.data[i])*(this->data[i+1]));
        rat.data[i+1] = this->data[i+1]*B.data[i+1];
        }

        rat.dim = B.dim;
        return rat;
}

CRat0 CRat0::operator - (const CRat &B){
        CRat0 rat(B.dim);
        for(int i = 0; i< (B.dim*2);i+=2){
        rat.data[i] = ((this->data[i])*(B.data[i+1]))-((B.data[i])*(this->data[i+1]));
        rat.data[i+1] = this->data[i+1]*B.data[i+1];
        }

        rat.dim = B.dim;
        return rat;
}
CRat0::~CRat0(){
    if(data != NULL)
    delete [] data;
    data = NULL;
}
double CRat0::operator * (const CRat &B){//скалярное умножение
        double ch = 0, zn = 0, p = 0;
        for(int i = 0; i< this->dim*2;i=+2){
        ch = (double)(this->data[i]*B.data[i]);
        zn = (double)(this->data[i+1]*B.data[i+1]);
        p += ch/zn;
        }
        return p;
}
int CRat0::output()
{
    ofstream fout(outfile.c_str(), ios_base::app);
    for(int i = 0; i < dim*2; i++){
        fout<<" X"<<i/2<<" = ";
        fout<<data[i]<<"/"<<data[i+1]<<" ";// Выводим данные в строку
        i = i+1;
    }
    return 0;
}
