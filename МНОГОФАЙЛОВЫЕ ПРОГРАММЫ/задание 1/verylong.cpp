#include "verylong.h"
#include <iostream>
using namespace std;
VeryLong::VeryLong() :a(0) {}
VeryLong::VeryLong(long double a1) :a(a1) {}

void VeryLong::getdata() {
	cout << "Ââåäèòå ÷èñëî -> "; cin >> a;
}

VeryLong VeryLong::operator-(const VeryLong& other){
	return VeryLong(a - other.a);
}
VeryLong VeryLong::operator+(const VeryLong& other) {
	return VeryLong(a + other.a);
}
VeryLong VeryLong::operator*(const VeryLong& other) {
	return VeryLong(a * other.a);
}
VeryLong VeryLong::operator/(const VeryLong& other) {
	if (other.a != 0) return VeryLong(a / other.a);
	else cout << "Íà íîëü äåëèòü íåëüçÿ!" << endl;
}
void VeryLong::putdata() {
	cout << a;
}

