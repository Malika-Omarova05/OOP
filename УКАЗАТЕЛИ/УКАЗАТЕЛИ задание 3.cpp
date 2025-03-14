/*Используйте массив указателей на строки, представляющие собой назва- 
ния дней недели, из примера PTROSTR этой главы. Напишите функции для 
сортировки этих строк в алфавитном порядке, используя в качестве осно- 
вы функции bsort() и order() из программы PTRSORT этой главы. Сортиро- 
вать необходимо указатели на строки, а не сами строки. */
#include <iostream>
#include <cstring> 
using namespace std;
const int DAYS = 7;
void bsort(const char* s[], const int n);
void order(const char** a, const char** b);
int main() {
    setlocale(LC_ALL, "rus");
    const char* arrptrs[DAYS] = {
        "Понедельник", "Вторник", "Среда", "Четверг",
        "Пятница", "Суббота", "Воскресенье"
    };
    cout << "Исходный порядок:" << endl;
    for (int j = 0; j < DAYS; j++)
        cout << arrptrs[j] << endl;
    bsort(arrptrs, DAYS);
    cout << "\nОтсортированный порядок:" << endl;
    for (int j = 0; j < DAYS; j++)
        cout << arrptrs[j] << endl;
    return 0;
}
void bsort(const char* s[], const int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = 0; k < n - 1 - j; k++) {
            if (strcmp(s[k], s[k + 1]) > 0) {
                const char* temp = s[k];
                s[k] = s[k + 1];
                s[k + 1] = temp;
            }
        }
    }
}
