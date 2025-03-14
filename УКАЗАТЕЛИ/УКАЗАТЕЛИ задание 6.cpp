/*Создайте свою версию библиотечной функции strcmp(s1, s2), которая срав- 
нивает две строки и возвращает -1, если s1 идет первой по алфавиту, 0, 
если в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. 
Назовите вашу функцию compstr(). Она должна принимать в качестве ар- 
гументов два указателя на строки char*, сравнивать эти строки посим- 
вольно и возвращать число int. Напишите функцию main() для проверки 
работы вашей функции с разными строками. Используйте указатели во 
всех возможных ситуациях. */
#include <iostream>
#include <windows.h>
using namespace std;
int compstr(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') { 
        if (*s1 < *s2) return -1;
        else if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') return 0;
    else if (*s1 == '\0')return -1;
    else return 1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* str1 = "мама";
    const char* str2 = "папа";
    const char* str3 = "мама";
    const char* str4 = "кринж";

    cout << "Сравнение str1 и str2: " << compstr(str1, str2) << endl;
    cout << "Сравнение str1 и str3: " << compstr(str1, str3) << endl;
    cout << "Сравнение str1 и str4: " << compstr(str1, str4) << endl; 
    cout << "Сравнение str4 и str1: " << compstr(str4, str1) << endl;

    return 0;
}
