/*Только для любителей математики: создайте класс Polar, который предназначен для хранения полярных координат (радиуса и угла). Перегрузите 
операцию + для выполнения сложения для объектов класса Polar. Сложение двух объектов выполняется путем сложения координат X объектов, 
а затем координат Y. Результат будет координатами новой точки. Таким образом, вам нужно будет преобразовать полярные координаты к прямо- 
угольным, сложить их, а затем обратно преобразовать прямоугольные координаты результата к полярным. */
#include <iostream>
#include <cmath> 
using namespace std;
class Polar {
private:
    double radius; 
    double angle; 
public:
    Polar() : radius(0), angle(0) {}
    Polar(double r, double a) : radius(r), angle(a) {}
    void getdata() {
        cout << "Введите градус: "; cin >> radius;
        cout << "Введите угол в радианах: "; cin >> angle;
    }
    void display() const {
        cout << "Полярные координаты: Радиус = " << radius << ", Угол = " << angle << " радиан" << endl;
    }
    Polar operator+(const Polar& p) const {
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = p.radius * cos(p.angle);
        double y2 = p.radius * sin(p.angle);
        double x = x1 + x2;
        double y = y1 + y2;
        double r = sqrt(x * x + y * y);
        double a = atan2(y, x);
        return Polar(r, a);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Polar p1, p2;
    cout << "Введите первые данные: " << endl;
    p1.getdata();
    cout << "Введите вторые данные: " << endl;
    p2.getdata();
    cout << "Объект 1:\n";
    p1.display();
    cout << "Объект 2:\n";
    p2.display();
    Polar p3 = p1 + p2;
    cout << "\nРезультат сложения:\n";
    p3.display();

    return 0;
}
