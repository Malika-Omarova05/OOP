/*Напишите программу, копирующую один файл с целочисленными данны- 
ми в другой. Используйте для этого потоковые итераторы. Пользова- 
тель должен ввести имена обоих файлов. Можно использовать цикл while. 
В этом цикле, наверное, будут читаться последовательно значения из вход- 
ного итератора и сразу записываться в выходной, после чего будет произ- 
водиться инкремент обоих итераторов. В качестве исходного можно взять 
файл ITER.DAT, созданный программой FOUTITER. */
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    string inputFile = "ITER1.DAT";
    string outputFile;
    ofstream fout(inputFile);
    if (!fout) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return 1;
    }

    cout << "Введите целые числа для записи в " << inputFile << " (для завершения введите -1): ";
    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;
        fout << num << " ";
    }
    fout.close();
    cout << "Введите имя файла для копирования данных: ";
    cin >> outputFile;
    ifstream fin(inputFile);
    ofstream foutCopy(outputFile);
    if (!fin || !foutCopy) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    istream_iterator<int> inIter(fin), endIter;
    ostream_iterator<int> outIter(foutCopy, " ");
    copy(inIter, endIter, outIter);

    foutCopy.close();
    fin.close();
    ifstream finOutput(outputFile);
    if (!finOutput) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return 1;
    }

    cout << "Содержимое файла " << outputFile << ": ";
    istream_iterator<int> fileIter(finOutput);
    while (fileIter != istream_iterator<int>()) {
        cout << *fileIter << " ";
        ++fileIter;
    }
    cout << endl;

    finOutput.close();
    return 0;
}
