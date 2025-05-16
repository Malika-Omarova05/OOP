/*Начните с класса person. Создайте мультимножество для хранения указа- 
телей на объекты этого класса. Определите его с помощью функциональ- 
ного объекта comparePersons, чтобы сортировка производилась автомати- 
чески по именам людей. Определите с полдюжины элементов, внесите их 
в мультимножество. Выведите его содержимое. Задайте имена людей 
таким образом, чтобы некоторые из них совпадали. Тем самым можно бу- 
дет удостовериться в том, что мультимножество может хранить несколько 
объектов с одинаковым ключом. */
// хранящихся по указателям 
#include <iostream> 
#include <set> 
#include <Windows.h>
#pragma warning (disable:4786) 
#include <string> 
using namespace std;
class person
{
private:
    string lastName;
    string firstName;
    long phoneNumber;
public:
    person() :             
        lastName("пусто"), firstName("пусто"), phoneNumber(0L) {} 
    person(string lana, string fina, long pho) : lastName(lana), firstName(fina), phoneNumber(pho) {}
    friend bool operator<(const person&, const person&);
    void display()const {
        cout << endl << lastName << ",\t " << firstName << "\t \tТелефон: 0" << phoneNumber;
    }
    long get_phone()const {
        return phoneNumber;
    }
};         
bool operator<(const person& p1, const person& p2) {
    if (p1.lastName == p2.lastName)
        return (p1.firstName < p2.firstName) ? true : false;
    return (p1.lastName < p2.lastName) ? true : false;
}

class comparePersons {
public:
    bool operator()(const person* ptrP1, const person* ptrP2)const {
        return *ptrP1 < *ptrP2;
    }
};
int main() {  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    multiset<person*, comparePersons>setPtrsPers;
    multiset<person*, comparePersons>::iterator iter;
    person* ptrP1 = new person("Омарова ", "Малика ", 550322111);
    person* ptrP2 = new person("Сталбекова ", "Айжамал ", 553327563);
    person* ptrP3 = new person("Мухамеджанова ", "Танзиля ", 778435150);
    person* ptrP4 = new person("Жолдошев ", "Жоомарт ", 779207404);
    person* ptrP5 = new person("Мелисбеков ", "Кубанычбек ", 556946473);
    person* ptrP6 = new person("Торобеков  ", "Бекжан ", 558435150);
    person* ptrP7 = new person("Аскарбеов ", "Ардак ", 777049982);
    person* ptrP8 = new person("Омарова ", "Малика ", 550322111);
    setPtrsPers.insert(ptrP1);
    setPtrsPers.insert(ptrP2);
    setPtrsPers.insert(ptrP3);
    setPtrsPers.insert(ptrP4);
    setPtrsPers.insert(ptrP5);
    setPtrsPers.insert(ptrP6);
    setPtrsPers.insert(ptrP7);
    setPtrsPers.insert(ptrP8);
    
    cout << "\n \nМножество упорядочено при создании:";
    for (iter = setPtrsPers.begin(); iter != setPtrsPers.end(); iter++)
        (**iter).display();
    iter = setPtrsPers.begin();            
    while (iter != setPtrsPers.end())
    {
        delete* iter;              
        setPtrsPers.erase(iter++);  
    }
    cout << endl;
    return 0;
}