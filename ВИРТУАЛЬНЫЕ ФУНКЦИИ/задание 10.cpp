/*Упражнение 4 в главе 10 включало в себя добавление к классу linklist перегружаемого деструктора. Допустим, мы заполняем объект этого класса 
данными, а затем присваиваем один класс целиком другому, используя стандартный оператор присваивания: list2 = list1; Допустим, что впоследствии 
мы удалим объект класса list1. Можем ли мы все еще использовать list2 для доступа к введенным данным? Увы, нет, так как при удалении list1 все 
его ссылки были удалены. Единственное, что было известно объекту linklist про удаленный объект, это указатель на него. Но его удалили, указатель 
в list2 стал недееспособным, и все попытки получить доступ к данным приведут к получению мусора вместо данных, а в худшем случае — к зависанию 
программы. Один из способов избежать этих проблем — перегрузить оператор присваивания, чтобы он вместе с объектом копировал бы все его ссылки. 
Но тогда придется пройти по всей цепочке, поочередно копируя все ссылки. Как отмечалось ранее, следует также перегружать конструктор копирования. 
Чтобы была возможность удалять объекты linklist в main(), можно создавать их с помощью указателя и new. В таком случае проще будет проверять работу 
новых операций. Не переживайте, если обнаружите, что в процессе копирования порядок следования данных изменился. Понятно, что копирование всех данных 
не является самым эффективным решением проблемы с точки зрения экономии памяти. Сравните этот подход с представленным в примере STRIMEM (глава 10), 
где использовался только один набор данных для всех объектов, и хранилась информация о том, сколько объектов указывали на эти данные. */
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int d, Node* n = nullptr) : data(d), next(n) {}
};

class LinkList {
private:
    Node* head;
    void copyList(const Node* source) {
        if (!source) {
            head = nullptr;
            return;
        }

        head = new Node(source->data); 
        Node* current = head;
        source = source->next;

        while (source) {
            current->next = new Node(source->data); 
            current = current->next;
            source = source->next;
        }
    }

public:
    LinkList() : head(nullptr) {}
    LinkList(const LinkList& other) {
        copyList(other.head);
    }
    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this; 
        clear(); 
        copyList(other.head);
        return *this;
    }

    void add(int value) {
        if (!head) {
            head = new Node(value);
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }

    void inputList() {
        cout << "Введите элементы списка (введите -1 для завершения):\n";
        int value;
        while (true) {
            cin >> value;
            if (value == -1) break;
            add(value);
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~LinkList() {
        clear();
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    LinkList list1;
    cout << "Введите данные для списка 1:\n";
    list1.inputList(); 
    cout << "Список 1: ";
    list1.display();
    LinkList list2;
    list2 = list1; 
    cout << "Список 2 после присваивания: ";
    list2.display();
    list1.clear(); 
    cout << "Список 2 после удаления list1: ";
    list2.display(); 
    return 0;
}
