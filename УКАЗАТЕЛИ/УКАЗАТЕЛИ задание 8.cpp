/*Исправьте функцию additem() из программы LINKLIST так, чтобы она до- 
бавляла новый элемент в конец списка, а не в начало. Это будет означать, 
что первый вставленный элемент будет выведен первым и результат рабо- 
ты программы будет следующим: 
25 
36 
49 
64 
Для того чтобы добавить элемент, вам необходимо будет пройти по цепи 
до конца списка, а затем изменить указатель последнего элемента так, что- 
бы он указывал на новый элемент. */
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
        newlink->next = NULL;

        if (first == NULL) {
            first = newlink;
        }
        else {
            link* c = first;
            while (c->next != NULL) { 
                c = c->next;
            }
            c->next = newlink; 
        }
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
