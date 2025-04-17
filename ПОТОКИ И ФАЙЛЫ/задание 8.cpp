/* Основываясь на программе LINKLIST из главы 10 «Указатели», напишите программу, позволяющую пользователю выбрать одно 
из четырех действий нажатием соответствующей кнопки. Действия таковы: 
♦ добавить ссылку в список (от пользователя требуется ввести целое число) 
♦ показать данные по всем ссылкам из списка; 
♦ записать в файл данные для всех ссылок (создание или переписывание файла); 
♦ считать все данные из файла и создать новый список ссылок, куда и поместить их. 
Первые два действия могут использовать методы, уже имеющиеся в LINKLIST. От вас требуется написать функции для чтения и 
записи файла. И для того, и для другого можно использовать один и тот же файл. В нем должны храниться только данные; нет 
никакого смысла хранить содержимое указателей, которые, возможно, уже не будут нужны во время чтения списка. */
#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkList {
private:
    Node* head;

public:
    LinkList() : head(nullptr) {}

    // Добавить ссылку в список
    void add_link(int value) {
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Показать данные всех ссылок
    void display_links() const {
        Node* temp = head;
        if (!temp) {
            cout << "Список пуст.\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }

    // Записать в файл данные всех ссылок
    void write_to_file(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Ошибка: невозможно открыть файл для записи.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            file << temp->data << "\n";
            temp = temp->next;
        }
        file.close();
        cout << "Данные успешно записаны в файл " << filename << ".\n";
    }

    // Считать данные из файла и создать новый список
    void read_from_file(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Ошибка: невозможно открыть файл для чтения.\n";
            return;
        }
        head = nullptr; // Очистить текущий список
        int value;
        while (file >> value) {
            add_link(value);
        }
        file.close();
        cout << "Данные успешно считаны из файла " << filename << ".\n";
    }

    ~LinkList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    LinkList list;
    int choice;

    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить ссылку в список\n";
        cout << "2. Показать данные всех ссылок\n";
        cout << "3. Записать данные всех ссылок в файл\n";
        cout << "4. Считать данные из файла и создать новый список\n";
        cout << "5. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Введите целое число: ";
            cin >> value;
            list.add_link(value);
            break;
        }
        case 2:
            list.display_links();
            break;
        case 3: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            list.write_to_file(filename);
            break;
        }
        case 4: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            list.read_from_file(filename);
            break;
        }
        case 5:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}
