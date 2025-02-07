/* Создайте структуру с именем sterling, хранящую денежные суммы в старой 
английской системе, описанной в упражнениях 8 и 11 главы 3 «Циклы и 
ветвления». Поля структуры могут быть названы pounds, shillings и pence 
и иметь тип int. Программа должна запрашивать у пользователя значение 
денежной суммы в новых десятичных фунтах (значение должно хранить- 
ся в переменной типа double), затем переводить эту сумму в старую систе- 
му, сохранять переведенное значение в переменной типа sterling и выво- 
дить на экран полученную сумму в фунтах, шиллингах и пенсах. */
#include <iostream>
using namespace std;
struct sterling {
    int pounds;    
    int shillings; 
    int pence;     
};

int main() {
    setlocale(LC_ALL, "rus");
    double des;
    sterling old;

    cout << "Введите сумму в десятичных фунтах: ";
    cin >> des;

    old.pounds = static_cast<int>(des);
    double a = (des - old.pounds) * 20;
    old.shillings = static_cast<int>(a);
    old.pence = static_cast<int>((a - old.shillings) * 12);

    cout << "Эквивалент в старой системе: " << old.pounds << " фунтов, "
        << old.shillings << " шиллингов, " << old.pence << " пенсов." << endl;

    return 0;
}
