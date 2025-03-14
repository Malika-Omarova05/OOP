/*Добавьте деструктор в программу LINKLIST. Он должен удалять все эле- 
менты списка при удалении объекта класса linklist. Элементы должны 
удаляться по очереди, в соответствии с их расположением в списке. Про- 
тестируйте деструктор путем вывода сообщения об удалении каждого из 
элементов списка; удалено должно быть также количество элементов, ка- 
кое было положено в список (деструктор вызывается автоматически для 
каждого существующего объекта). */
#include <iostream>
using namespace std;
struct link {
    int data;
    link* next;
};
class linklist {
private:
    link* first;
public:
    linklist() {
        first = NULL;
    }
    ~linklist() {
        link* c = first;
        while (c) {
            link* temp = c;
            c = c->next;
            cout << "Удаляем элемент со значением: " << temp->data << endl;
            delete temp;
        }
    }
    void additem(int d) {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = first;
        first = newlink;
    }
    void display() {
        link* c = first;
        while (c) {
            cout << c->data << endl;
            c = c->next;
        }
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    linklist li;
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display();
    return 0;
}
