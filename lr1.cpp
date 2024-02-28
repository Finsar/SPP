#include <iostream>
#include <Windows.h>

using namespace std;


int main() {
    int k = 7;
    int m = 9;
    int n = 4;

    if (k%2==1 || m%2==1) {
        cout << "ODD" << endl;
    }
    else if(k%2==0 && n%2==0)
        cout << "EVEN" << endl;

    else {

        cout << "1" << endl;
    }
}
