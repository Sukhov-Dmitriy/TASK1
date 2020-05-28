#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CRat1 : public CRat{
private:

public:
    CRat1(const CRat1 &other);// конструктор копировани€
    CRat1(int d);
    CRat1();
    CRat1 operator + (const CRat &B);
    CRat1 operator - (const CRat &B);
    ~CRat1();
    double operator * (const CRat &B);//—кал€рное умножение
    int output();
};
