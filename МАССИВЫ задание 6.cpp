/* В игре бридж каждому из игроков раздают 13 карт, таким образом колода расходуется полностью. Модифицируйте программу CARDARAY этой 
главы так, чтобы после перемешивания колоды она делилась на четыре части по 13 карт каждая. Каждая из четырех групп карт затем должна 
быть выведена. */
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <windows.h>
using namespace std;
enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
class card{
private:
    int number;
    Suit suit;
public:
    card() : number(0), suit(clubs) {}  
    void set(int n, Suit s) 
    {
        suit = s; number = n;
    }
    void display();        
};
void card::display(){
    if (number >= 2 && number <= 10)
        cout << number;
    else {
        switch (number) {
        case jack:  wcout << L'J'; break;
        case queen: wcout << L'Q'; break;
        case king:  wcout << L'K'; break;
        case ace:   wcout << L'A'; break;
        }
    }
    switch (suit) {
    case clubs:    wcout << L"\u2663"; break;    // ♣
    case diamonds: wcout << L"\u2666"; break;    // ♦
    case hearts:   wcout << L"\u2665"; break;    // ♥
    case spades:   wcout << L"\u2660"; break;    // ♠
    }
}
int main() {
    SetConsoleOutputCP(CP_UTF8);  // Устанавливаем кодировку консоли на UTF-8
    setlocale(LC_ALL, "ru_RU.UTF-8");
    card deck[52];
    int j;
    cout << endl;
    for (j = 0; j < 52; j++) {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    wcout << L"Исходная колода:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display();
        wcout << L"  ";
        if (!((j + 1) % 13))
            wcout << endl;
    }
    srand(time(NULL));
    for (j = 0; j < 52; j++) {
        int k = rand() % 52;
        card temp = deck[j];
        deck[j] = deck[k];
        deck[k] = temp;
    }
    wcout << L"\nПеремешанная колода:\n";
    for (j = 0; j < 52; j++) {
        deck[j].display();
        wcout << L"  ";
        if (!((j + 1) % 13))
            wcout << endl;
    }
    card hand[4][13];
    for (int i = 0; i < 52; i++) {
        hand[i / 13][i % 13] = deck[i];
    }
    for (int player = 0; player < 4; player++) {
        wcout << L"\nКарты игрока " << player + 1 << L":\n";
        for (int card = 0; card < 13; card++) {  
            hand[player][card].display();
            wcout << L"  ";
        }
        wcout << endl;
    }
    return 0;
}
