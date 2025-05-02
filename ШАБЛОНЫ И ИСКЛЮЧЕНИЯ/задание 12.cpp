#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;
class FileException : public runtime_error {
public:
    FileException(const string& message) : runtime_error(message) {}
};

class dofile {
private:
    fstream file;
    string filename;

public:
    dofile(const string& fname, ios::openmode mode) : filename(fname) {
        file.open(filename, mode);
        if (!file) {
            throw FileException("Ошибка: Не удалось открыть файл " + filename);
        }
    }
    void write(const string& data) {
        if (!file) {
            throw FileException("Ошибка: Файл закрыт или недоступен для записи!");
        }
        file << data << endl;
        if (!file) {
            throw FileException("Ошибка: Ошибка записи в файл " + filename);
        }
    }

    string read() {
        if (!file) {
            throw FileException("Ошибка: Файл закрыт или недоступен для чтения!");
        }
        string line;
        if (!getline(file, line)) {
            throw FileException("Ошибка: Не удалось прочитать строку из файла " + filename);
        }
        return line;
    }

    void rewind() {
        if (!file) {
            throw FileException("Ошибка: Файл не открыт!");
        }
        file.clear(); 
        file.seekg(0, ios::beg);
        file.seekp(0, ios::beg);
    }

    void close() {
        if (file.is_open()) {
            file.close();
        }
    }

    ~dofile() {
        close();
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    try {
        dofile file("test.txt", ios::in | ios::out | ios::app);
        file.write("Привет, мир!");
        file.write("Это тестовая строка.");
        file.rewind();
        cout << "Содержимое файла:\n";
        cout << file.read() << endl;
        cout << file.read() << endl;

    }
    catch (const FileException& e) {
        cout << "\nИсключение: " << e.what() << endl;
    }

    return 0;
}
