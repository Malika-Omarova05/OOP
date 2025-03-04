/*Добавьте в класс Distance из программы ENGLPLUS этой главы перегруженную операцию -, которая вычисляет разность двух интервалов. Она 
должна позволять выполнение выражений типа dist3 = dist1-dist2;. Предполагаем, что эта операция никогда не будет использоваться для вычитания 
большего интервала из меньшего (так как отрицательного интервала быть не может). */
#include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(float fltfeet) {
        feet = static_cast<int>(fltfeet);
        inches = 12 * (fltfeet - feet); 
    }
    Distance(int ft, float in) {
        feet = ft; inches = in;
    }
    void getdata() {
        cout << "Введите фунты: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void showdist() {
        cout << feet << "\'-" << inches << '\"';
    }
    Distance operator+(Distance); 
    Distance operator-(Distance); 
};
Distance Distance::operator+(Distance d2) {
    int f = feet + d2.feet;      
    float i = inches + d2.inches;
    if (i >= 12.0) {
        i -= 12.0; f++;
    }       
    return Distance(f, i);
}
Distance Distance::operator-(Distance d2) {
    int f = feet - d2.feet;      
    float i = inches - d2.inches;
    if (i < 0) {
        i += 12.0; f--;
    }        
    return Distance(f, i);
}
int main() {
    setlocale(LC_ALL, "rus");
    Distance d1, d2, d3;
    cout << "Введите первую длину: \n";
    d1.getdata();
    cout << "Введите вторую длину: \n";
    d2.getdata();
    cout << "\nd1 = "; d1.showdist();
    cout << "\nd2 = "; d2.showdist();
    d3 = d1 + d2;
    cout << "\nСумма = "; d3.showdist();
    d3 = d1 - d2;
    cout << "\nРазность = "; d3.showdist();
    cout << endl;
    return 0;
}
