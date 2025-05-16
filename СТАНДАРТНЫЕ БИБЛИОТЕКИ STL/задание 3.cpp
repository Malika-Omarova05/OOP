/*Начните с создания списка целых чисел. Используйте два обычных (не обратных) итератора: один для продвижения в прямом направлении, дру- 
гой для продвижения в обратном направлении. Вставьте их в цикл while для переворачивания содержимого списка. Ради экономии нескольких 
выражений можно использовать алгоритм swap() (только при этом следует убедиться, что подход работает как с четными, так и с нечетными эле- 
ментами). */
#include <iostream>
#include <list> 
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    int j;
    list<int>theList;
    list<int>::iterator iter1;
    list<int>::iterator iter2;
    for (j = 2; j < 16; j += 2) 
        theList.push_back(j);
    cout << "До переворачивания:"; 
    for (iter1 = theList.begin(); iter1 != theList.end(); iter1++)
        cout << *iter1 << " ";
    iter1 = theList.begin();     
    iter2 = theList.end();       
    --iter2;                     
    while (iter1 != iter2)
    {
        swap(*iter1, *iter2);       
        ++iter1;                    
        if (iter1 == iter2)          
            break;
        --iter2;                    
    }
    cout << "\nПосле переворачивания:"; 
    for (iter1 = theList.begin(); iter1 != theList.end(); iter1++)
        cout << *iter1 << " ";
    cout << endl;
    return 0;
}