/* Рассмотрите класс Distance из программы ENGLCON, глава 6 «Объекты и 
классы». Используя цикл, аналогичный приводимому в программе DISKFUN 
в этой главе, получите несколько значений от пользователя и запишите 
их в файл. Добавьте их к уже записанным там данным (при их наличии). 
При окончании пользователем ввода прочитайте файл и выведите на эк- 
ран все значения.*/
#include <iostream> 
#include <fstream>   
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int ft, float in) :feet(ft), inches(in) {}
    void getdist() {
        cout << "\nВведите футы:"; cin >> feet;
        cout << "Введите дюймы:"; cin >> inches;
    }
    void showdist() {
        cout << feet << "\'-" << inches << '\"';
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    char ch;
    Distance dist;  
    fstream file;   
    file.open("DIST.txt ", ios::binary | ios::app | ios::out | ios::in);
    do {
        cout << "\nРасстояние ";
        dist.getdist();
        file.write((char*)&dist, sizeof(dist));
        cout << "Продолжать (y/n)?";
        cin >> ch;
    }
    while (ch == 'y'); 
    file.seekg(0);  
    file.read((char*)&dist, sizeof(dist));
    int count = 0;
    while (!file.eof()) {
        cout << "\nРасстояние " << ++count << ":";
        dist.showdist();
        file.read((char*)&dist, sizeof(dist)); 
    }
    cout << endl;
    return 0;
}
