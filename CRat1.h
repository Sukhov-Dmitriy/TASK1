#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CRat1 : public CRat{
private:

public:
    CRat1(const CRat1 &other);// êîíñòðóêòîð êîïèðîâàíèÿ
    CRat1(const CRat &other);
    CRat1(int d);
    CRat1();
    CRat1 operator - (const CRat &B);
    ~CRat1();
    double operator * (const CRat &B);//Ñêàëÿðíîå óìíîæåíèå
    int output();
    using CRat::operator =;
};
