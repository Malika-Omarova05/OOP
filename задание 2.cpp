/*Очередь — это тип хранилища данных. Она напоминает по своей сути 
стек, только вместо правила LIFO (последний вошел — первый вышел) 
использует правило FIFO (первый вошел — первый вышел). В общем, 
как очередь у окошка в банке. Если вы заносите в массив числа 1, 2, 3, 
обратно вы их получите в той же последовательности. Стеку требуется 
для работы только один индекс массива (top, вершина массива. См. 
программу STAKARAY из главы 7). Очереди же требуется два индекса: индекс
хвоста, куда добавляются новые элементы, и индекс головы очереди, откуда
исчезают старые. Хвост постепенно сдвигается, как и голова. Если хвост 
или голова достигает конца массива, он переставляется на начало. 
Напишите шаблон класса для работы с очередью. Предположим, что про- 
граммист не будет совершать ошибок при написании ее модели. Напри- 
мер, вместимость очереди не будет превышена, а из пустой очереди не 
будет производиться попыток удаления данных. Определите несколько 
очередей разных типов и поработайте с их данными. */
#include <iostream>
using namespace std;
template <typename mlk>
struct node {
    mlk value;
    node* next;
};
template <typename mlk>
node<mlk>* postroenie(node<mlk>*& ko) {
    cout << "Вводите элементы очереди (введите 0 для завершения): " << endl;
    mlk val;
    node<mlk>* no = nullptr;
    cin >> val;
    while (val != 0) {
        node<mlk>* t = new node<mlk>;
        t->value = val;
        t->next = nullptr;
        if (no == 0) {
            no = ko = t;
        }
        else {
            ko->next = t;
            ko = t;
        }
        cin >> val;
    }
    cout << "Очередь построена" << endl;
    return no;
}
template <typename mlk>
void print(node<mlk>* no) {
    node<mlk>* r = no;
    cout << "Начало очереди" << endl;
    while (r != 0) {
        cout << "\t" << r->value << "\n";
        r = r->next;
    }
    cout << "Конец очереди!" << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    node<int>* into = nullptr;
    node<double>* doubleo = nullptr;
    node<long>* longo = nullptr;
    
    cout << "Создание очереди int: " << endl;
    into = postroenie(into);
    print(into);

    cout << "Создание очереди double:" << endl;
    doubleo = postroenie(doubleo);
    print(doubleo);

    cout << "Создание очереди char:" << endl;
    longo = postroenie(longo);
    print(longo);

    return 0;
}