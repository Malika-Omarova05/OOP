/*Взяв за основу приведенную программу, добавьте перегружаемое присваи- 
вание и перегружаемый конструктор копирования к классу Array. Затем 
добавьте к main() выражение Array arr2(arr1); и arr3 = arr1; для проверки того, 
что перегружаемые операции работают. Конструктор копирования должен 
создать новый объект Array со своим собственным местом в памяти, вы- 
деленным для хранения элементов массива. И конструктор копирования, 
и оператор присваивания должны копировать содержимое старого объек- 
та класса Array в новый. Что будет, если вы присвоите объект Array одного 
размера объекту Array другого размера? */
#include <iostream> 
using namespace std;
class Array {
private:
    int* ptr;
    int size;
public:
    Array() : ptr(0), size(0) {}
    Array(int s) :size(s) {
        ptr = new int[s];
    }
    Array(Array&);
    ~Array() {
        delete[] ptr;
    }
    int& operator[](int j) {
        return *(ptr + j);
    }
    Array& operator=(Array&);
};
Array::Array(Array& a) {
    size = a.size;          
    ptr = new int[size];    
    for (int j = 0; j < size; j++)
        *(ptr + j) = *(a.ptr + j);  
}
Array& Array::operator=(Array& a) {
    delete[] ptr;
    size = a.size;
    ptr = new int[a.size];
    for (int j = 0; j < a.size; j++)
        *(ptr + j) = *(a.ptr + j);
    return *this;
}
int main() {
    const int ASIZE = 10;  
    Array arr1(ASIZE);   
    for (int j = 0; j < ASIZE; j++) arr1[j] = j * j;
    Array arr2(arr1);  
    cout << "\narr2:";
    for (int j = 0; j < ASIZE; j++) cout << arr2[j] << " ";
    Array arr3, arr4;  
    arr4 = arr3 = arr1;  
    cout << "\narr3:";
    for (int j = 0; j < ASIZE; j++) cout << arr3[j] << " ";
    cout << "\narr4:";
    for (int j = 0; j < ASIZE; j++) cout << arr4[j] << " ";
    cout << endl;
    return 0;
}