/*Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в программе STRPLUS этой главы. Эта опера- 
ция должна позволять записывать выражения типа: s1 += s2;где s2 прибавляется (объединяется) к строке s1, результат при этом оста- 
ется в s1. Операция должна также позволять использовать результат для других вычислений, например в выражениях типа s3 = s1 += s2; */
#include <iostream>
#include <cstring>  
#include <cstdlib>   
#include <windows.h>
using namespace std;

class String {
private:
    enum { SZ = 80 }; 
    char str[SZ];    
public:
    String() { strcpy_s(str, ""); }
    String(const char* s) { strcpy_s(str, s); } 
    void display() const { cout << str; }
    void getdata() {
        cout << "Введите строку: ";
        cin.getline(str, SZ);
    }
    String& operator+=(const String& ss) {
        if (strlen(str) + strlen(ss.str) < SZ) {
            strcat_s(str, ss.str);
        }
        else {
            cout << "\nПереполнение!";
            exit(1);
        }
        return *this;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    String s1, s2, s3;
    cout << "Введите первую строку:\n";
    s1.getdata();
    cout << "Введите вторую строку:\n";
    s2.getdata();
    cout << "Первая строка: ";
    s1.display(); cout << endl;
    cout << "Вторая строка: ";
    s2.display();
    s3.display();
    s1 += s2;     
    cout << "\nПосле объединения:\n";
    s1.display();
    return 0;
}
