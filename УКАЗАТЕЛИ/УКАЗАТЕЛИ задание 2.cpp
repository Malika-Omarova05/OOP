/*Используйте класс String из примера NEWSTR этой главы. Добавьте к нему 
метод upit(), который будет переводить символы строки в верхний регистр. 
Вы можете использовать библиотечную функцию toupper(), которая прини- 
мает отдельный символ в качестве аргумента и возвращает символ, пере- 
веденный в верхний регистр (если это необходимо). Эта функция исполь- 
зует заголовочный файл Cctype. Добавьте в функцию main() необходимые 
строки для тестирования метода upit(). */
#include <iostream> 
#include <cstring>     
using namespace std;
class String {
private:
    char* str;                      
public:
    String(const char* s) {
        size_t length = strlen(s);   
        str = new char[length + 1];  
        strcpy_s(str, length + 1, s); 
    }
    ~String() {
        cout << "Удаляем строку\n";
        delete[] str;              
    }
    void display() {
        cout << str << endl;
    }
    void upit() {
        for (size_t i = 0; i < strlen(str); i++) {
            str[i] = toupper(str[i]); 
        }
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    String s1("Тише едешь - дальше будешь.");  
    cout << "s1 = ";
    s1.display();
    s1.upit();
    cout << "Строка после изменений:\n";
    s1.display();
    return 0;
}
