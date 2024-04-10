#include <iostream>

using namespace std;

class animal {
private:
    int x, y;

public:
    animal(int x, int y) : x(x), y(y) {}

    void move() {
        ++x;
        ++y;
    }

    void consolepos() const {
        cout << "Position X: " << x << " Position Y: " << y << endl;
    }
};

class lion : public animal {
private:
    int age;
    int weight;
    int klik;
    int griva;
    int pride;

public:
    lion(int x, int y, int age, int weight, int klik, int griva, int pride) : animal(x, y), age(age), weight(weight), klik(klik), griva(griva), pride(pride) {}

    void rev() const {
        cout << "AAABAVAVA!!" << endl;
    }

    void console() const {
        consolepos();
        if (age <= 0) {
            cout << "Lion pomer(((((((." << endl;
        }
        else {
            cout << "Age: " << age << " Weight: " << weight << endl;
        }
        cout << "Klik size: " << klik << " Size grivi: " << griva << " Pride: " << pride << endl;
    }
};

int main() {
    lion Lion(1, 2, 0, 200, 5, 6, 3);
    Lion.console();
    Lion.move();
    Lion.console();
    Lion.rev();

    return 0;
}
