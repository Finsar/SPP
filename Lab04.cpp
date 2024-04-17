#include <iostream>

using namespace std;

class Animal {
private:
    int x, y;

public:
    Animal(int x, int y) : x(x), y(y) {}

    void move() {
        ++x;
        ++y;
    }

    void consolePos() const {
        cout << "Position X: " << x << " Position Y: " << y << endl;
    }
};

class Lion : public Animal {
private:
    int age, weight, klik, griva, pride;

public:
    Lion(int x, int y, int age, int weight, int klik, int griva, int pride)
        : Animal(x, y), age(age), weight(weight), klik(klik), griva(griva), pride(pride) {}

    void roar() const {
        cout << "Roarrr!!" << endl;
    }

    void console() const {
        consolePos();
        if (age <= 0) {
            cout << "Lion is dead." << endl;
        }
        else {
            cout << "Age: " << age << " Weight: " << weight << endl;
        }
        cout << "Klik size: " << klik << " Size of mane: " << griva << " Pride: " << pride << endl;
    }
};

int main() {
    Lion lion(1, 2, 0, 200, 5, 6, 3);
    lion.console();
    lion.move();
    lion.console();
    lion.roar();

    return 0;
}
