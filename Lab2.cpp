#include <iostream>
#include <cmath>
using namespace std;
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void p_p(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float& per, float& plo) {
    float side1 = distance(x1, y1, x2, y2);
    float side2 = distance(x2, y2, x3, y3);
    float side3 = distance(x3, y3, x4, y4);
    float side4 = distance(x4, y4, x1, y1);

    per = side1 + side2 + side3 + side4;
    float s = (side1 + side2 + side3 + side4) / 2;
    plo = sqrt((s - side1) * (s - side2) * (s - side3) * (s - side4));
}
int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "Enter coord x1 y1 x2 y2 x3 y3 x4 y4: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    float per, plo;
    p_p(x1, y1, x2, y2, x3, y3, x4, y4, per, plo);

    cout << "Per: " << per << endl;
    cout << "Plosha: " << plo << endl;
    return 0;

}