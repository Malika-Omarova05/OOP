/* Внесем некоторое разнообразие в пример HORSE из главы 10, создав класс для внесения в него лошадей экстракласса. Предположим, что любая ло- 
шадь, которая на скачках к середине дистанции находится впереди всех, становится практически непобедимой. Относительно класса лошадей соз- 
дадим порожденный класс comhorse (для конкурентоспособной лошади). Перегрузим функцию horse_tick() в этом классе таким образом, чтобы каж- 
дая лошадь могла проверять, является ли она ведущей и нет ли поблизости соперников (скажем, ближе, чем на 0.1 форлонг (1/80 часть мили или 
20.1 м.)). Если есть, то ей следует немного ускориться. Может быть, не настолько, чтобы побеждать на всех скачках, но в достаточной мере для 
того, чтобы оставаться конкурентоспособной. Как каждая лошадь узнает, где находятся остальные? Моделирующий ее объект должен иметь доступ к 
области памяти, в которой хранятся данные о соперниках. В программе HORSE это hArray. Будьте внимательны: вы создаете класс для передовой 
лошади, он должен быть наследником класса всех лошадей. Поэтому классу comhorse потребуется перегрузить hArray. Вам может потребоваться 
создать еще один производный класс, comtrack, для отслеживания позиции лошади. Можно непрерывно проверять, лидирует ли ваша лошадь, и если она 
впереди всех, но лишь ненамного, следует ее немного ускорить. */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Horse {
protected:
    string name;
    float position; 
    float speed; 
public:
    Horse(string n, float s) : name(n), position(0), speed(s) {}
    virtual void horse_tick(float time) {
        position += speed * time; 
    }
    virtual float getPosition() const {
        return position;
    }
    virtual string getName() const {
        return name;
    }
    virtual ~Horse() {}
};

class gon : public Horse {
public:
    gon(string n, float s) : Horse(n, s) {}
    void horse_tick(float time, const vector<Horse*>& hArray) {
    
        bool leading = true;
        for (const auto& horse : hArray) {
            if (horse != this && fabs(horse->getPosition() - this->position) < 0.1f) {
                speed += 0.5; 
                break;
            }
            if (horse->getPosition() > this->position) {
                leading = false;
            }
        }
        if (leading) {
            cout << name << " лидирует!" << endl;
        }
        Horse::horse_tick(time); 
    }
};

class gonka {
private:
    vector<Horse*> hArray; 
    float timeStep;       
public:
    gonka(float t) : timeStep(t) {}
    void addHorse(Horse* horse) {
        hArray.push_back(horse);
    }
    void startRace(float raceDuration) {
        float timee = 0;
        while (timee < raceDuration) {
            cout << "\nВремя: " << timee << " секунд" << endl;
            for (auto& horse : hArray) {
                gon* comHorse = dynamic_cast<gon*>(horse);
                if (comHorse) {
                    comHorse->horse_tick(timeStep, hArray); 
                }
                else {
                    horse->horse_tick(timeStep); 
                }
                cout << horse->getName() << " находится на позиции: " << horse->getPosition() << endl;
            }
            timee += timeStep;
        }
    }
    ~gonka() {
        for (auto& horse : hArray) {
            delete horse; 
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    gonka track(1.0f); 

    track.addHorse(new Horse("Обычная лошадь 1", 3.0f));
    track.addHorse(new Horse("Обычная лошадь 2", 3.5f));
    track.addHorse(new gon("Конкурентоспособная лошадь 1", 4.0f));
    track.addHorse(new gon("Конкурентоспособная лошадь 2", 3.8f));

    cout << "Начало гонки!\n";
    track.startRace(10.0f); 

    return 0;
}
