/*Вернемся к обсуждению денежных строк из упражнения 6. Напишите метод ldtoms() для преобразования числа типа long double  в денежную строку, 
представляющую это число. Для начала вам нужно проверить, что значение long double  не очень большое. Мы предполагаем, что вы не будете пы- 
таться преобразовать число, больше чем 9 999 999 999 999 990.00. Затем преобразуем long double  в строку (без знака доллара и запятых), храня- 
щуюся в памяти, используя объект ostrstream, как рассматривалось ранее в этой главе. Получившаяся отформатированная строка может быть поме- 
щена в буфер, называющийся ustring. Затем вам нужно будет создать другую строку, начинающуюся со знака доллара, далее копируем цифру за цифрой 
из строки ustring, начиная слева и вставляя запятые через каждые три цифры. Также вам нужно подавлять нули в начале строки. Например, вы должны
вывести $3 124.95, а не $0 000 000 000 003 124.95. Не забудьте закончить строку нулевым символом '\0'. Напишите функцию main() для тестирования
этой функции путем многократного ввода пользователем чисел типа long double  и вывода результата в виде денежной строки. */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib> 
using namespace std;

string ldtoms(long double value) {
    if (value > 9999999999999990.00) {
        return "Заданное число слишком большое!";
    }
    ostringstream out;
    out << fixed << setprecision(2) << value;
    string a = out.str();
    string res = "$";
    bool nul = true;
    int count = 0;
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] == '.') nul = false;
        if (nul && a[i] == '0') continue;
        nul = false;
        res += a[i];
        if (i < a.find('.') && !nul) {
            count++;
            if (count == 3 && i < a.find('.') - 1) {
                res += ',';
                count = 0;
            }
        }
    }
    return res + '\0';
}
long double mstold(const char* money) {
    char str[50];
    int j = 0;
    for (int i = 0; money[i] != '\0'; i++) {
        if ((money[i] >= '0' && money[i] <= '9') || money[i] == '.') 
            str[j++] = money[i];
    }
    str[j] = '\0';
    return strtold(str, nullptr);
}

int main() {
    setlocale(LC_ALL, "rus");
    char m[50];
    cout << "Введите денежное значение (например, $1,234,567,890.123): ";
    cin >> m;
    long double value = mstold(m);
    cout << "Эквивалентное значение: " << value << endl;
    cout << "Денежная строка: " << ldtoms(value) << endl;

    return 0;
}
