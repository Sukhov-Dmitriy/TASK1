#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
int main()
{
    setlocale(LC_ALL,"ru");
    char c;
    int n = 1;// количество данных

    string filename("inputfile.txt");//передачи названия файла
    ifstream File(filename.c_str());//c_str //Открытие файла

    if (!File.is_open()) // если файл не открыт
    {
        cout << "File isn't open!\n";
        return 0;
    }
    while (File.get(c)){ // определеие количества данных
        if (c=='\n')
            n++;
    }
    cout<<"number of data equal to "<< n<<endl;
    File.clear();
    File.seekg(0);// флаг переведен на начало файла


    CRatFactory *f[2];// массив фабрик
    f[0] = new CRatFactory0;
    f[1] = new CRatFactory1;

    CRat **arr = new CRat*[n];// массив для данных из файла;

    for(int i = 0; i < n; i++){// получение всех данных из файла
    arr[i] = CreateData(File, f);
    }
    File.close();

    for(int i = 0; i < n; i++){//Вывод всех данных
        arr[i]->output();
    }
    test1();//Прохождение тестов
    test2();
    test3();
    test4();
    //закрытие/очищение
    for(int i = 0; i < n; i++){

    delete arr[i];

    }
    delete f[0];
    delete f[1];
    delete [] arr;

    CRat0 a(2);
    a.data[0] = 1;
    a.data[1] = 3;
    a.data[2] = 1;
    a.data[3] = 2;

    CRat0 b(2);
    b.data[0] = 1;
    b.data[1] = 4;
    b.data[2] = 1;
    b.data[3] = 2;
    CRat1 ck;
    ck = a+b;
    ck.show();
    return 0;
}

