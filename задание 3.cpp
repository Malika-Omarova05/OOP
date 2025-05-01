/*Добавьте механизм обработки исключений в программу из упражнения 2. 
Рассмотрите два исключения: при превышении размера очереди и при по- 
пытке удаления данных из пустой очереди. Это можно сделать, добавив но- 
вый элемент данных в класс очереди — счетчик текущего числа элементов в 
очереди. Инкрементируйте счетчик при добавлении нового элемента, декре- 
ментируйте, соответственно, при удалении элемента из головы очереди. Ге- 
нерируйте исключение, если счетчик превысил размер массива или если он 
стал меньше 0.  Можно попробовать сделать main() интерактивной, чтобы 
пользователь мог вводить и извлекать данные. Так будет проще проверить 
работу написанных функций. С помощью механизма исключений программа 
должна обеспечивать повторную попытку ввода данных пользователем без 
нарушения целостности содержимого очереди. */
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;
    };
    Node* f;
    Node* r;
    int count;      
    int maxSize;   
public:
    Queue(int size) : f(nullptr), r(nullptr), count(0), maxSize(size) {}

    void enqueue(T value) {
        if (count >= maxSize) {
            throw overflow_error("Ошибка: превышен размер очереди!");
        }
        Node* newNode = new Node{ value, nullptr };
        if (r) r->next = newNode;
        r = newNode;
        if (!f) f = newNode;
        count++;
    }

    void dequeue() {
        if (!f) {
            throw underflow_error("Ошибка: попытка удаления элемента из пустой очереди!");
        }
        Node* temp = f;
        f = f->next;
        delete temp;
        count--;

        if (!f) r = nullptr;  
    }

    void display() {
        if (!f) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        Node* temp = f;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "Введите максимальный размер очереди: ";
    cin >> size;
    Queue<int> q(size);
    while (true) {
        try {
            int choice;
            cout << "\n1. Добавить элемент в очередь\n2. Удалить элемент из очереди\n3. Показать очередь\n4. Выйти\nВыбор: ";
            cin >> choice;

            if (choice == 1) {
                int val;
                cout << "Введите значение: ";
                cin >> val;
                q.enqueue(val);
            }
            else if (choice == 2) {
                q.dequeue();
            }
            else if (choice == 3) {
                q.display();
            }
            else if (choice == 4) {
                break;
            }
            else {
                cout << "Неверный ввод! Попробуйте снова." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Исключение: " << e.what() << endl;
        }
    }

    return 0;
}
