#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CRat0 : public CRat{
private:

public:
    CRat0(const CRat0 &other);// ����������� �����������
    CRat0(int d);
    CRat0();
    CRat0 operator + (const CRat &B);
    CRat0 operator - (const CRat &B);
    ~CRat0();
    double operator * (const CRat &B);//��������� ���������
    int output();
};
