#pragma once 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class VeryLong {
private:
	long double a;
public:
	VeryLong();
	VeryLong(long double a1);
	void getdata();
	VeryLong operator-(const VeryLong& other);
	VeryLong operator+(const VeryLong& other);
	VeryLong operator*(const VeryLong& other);
	VeryLong operator/(const VeryLong& other);
	void putdata();
};

//class VeryLong {
//private:
//    string number;
//    bool isNegative;
//
//    // Âñïîìîãàòåëüíûå ìåòîäû
//    string subtractStrings(const string& num1, const string& num2) const;
//    string divideStrings(const string& num1, const string& num2) const;
//
//public:
//    VeryLong(string num = "0");
//
//    // Ïåðåãðóçêà îïåðàòîðîâ
//    VeryLong operator-(const VeryLong& other);
//    VeryLong operator/(const VeryLong& other);
//
//    void display() const;
//};
//
//#endif
