/*За основу возьмите программу STRPLUS из главы 8. Добавьте класс исклю- 
чений, генерируйте исключения в конструкторе с одним аргументом в слу- 
чае, если строка инициализации слишком длинная. Генерируйте еще одно 
исключение в перегруженном операторе «+», если результат конкатенации 
оказывается слишком длинным. Сообщайте пользователю о том, какая 
именно ошибка произошла. */
#include <iostream>
#include <stdexcept> 
#include <cstring>    
#include <windows.h>
#include <string>
using namespace std;
class String {
private:
    static const int SZ = 80;
    char str[SZ];
public:
    String() { strcpy_s(str, ""); }
    String(const char* s) {
        if (strlen(s) >= SZ) {
            throw length_error("Ошибка: строка слишком длинная! Максимальный размер: " + to_string(SZ - 1));
        }
        strcpy_s(str, s);
    }

    void display() const { cout << str; }

    void getdata() {
        cout << "Введите строку: ";
        cin.getline(str, SZ);
    }

    String& operator+=(const String& ss) {
        if (strlen(str) + strlen(ss.str) >= SZ) {
            throw overflow_error("Ошибка: переполнение при сложении строк! Максимальный размер: " + to_string(SZ - 1));
        }
        strcat_s(str, ss.str);
        return *this;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        String s1, s2;
        cout << "Введите первую строку:\n";
        s1.getdata();
        cout << "Введите вторую строку:\n";
        s2.getdata();

        cout << "Первая строка: ";
        s1.display(); cout << endl;
        cout << "Вторая строка: ";
        s2.display();

        s1 += s2;
        cout << "\nПосле объединения:\n";
        s1.display();
    }
    catch (const exception& e) {
        cout << "\nИсключение: " << e.what() << endl;
    }
    try {
        String s3 = "Очень длинная строка, превышающая лимит!";
    }
    catch (const exception& e) {
        cout << "\nИсключение в конструкторе: " << e.what() << endl;
    }

    return 0;
}
