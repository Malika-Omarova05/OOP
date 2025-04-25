#include "verylong.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    VeryLong obj, obj1;
    obj.getdata();
    obj1.getdata();
    VeryLong sum = obj + obj1;
    VeryLong raz = obj - obj1;
    VeryLong pro = obj * obj1;
    VeryLong del = obj / obj1;
    obj.putdata(); cout << "+"; obj1.putdata(); cout << "="; sum.putdata(); cout << endl;
    obj.putdata(); cout << "-"; obj1.putdata(); cout << "="; raz.putdata(); cout << endl;
    obj.putdata(); cout << "*"; obj1.putdata(); cout << "="; pro.putdata(); cout << endl;
    obj.putdata(); cout << "/"; obj1.putdata(); cout << "="; del.putdata(); cout << endl;
    return 0;
}
