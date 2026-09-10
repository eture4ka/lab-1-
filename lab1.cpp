#include <iostream>

using namespace std;

class Lab1 {
private:
    int a = 25;
    int b = 8;
    short c = 3, d = 2;
    float e = 1.1f;
    float formula;

public:
    void obchislennya() {
        formula = (static_cast<float>(a - b) / (c * d)) * e;
    }

    void vyvid() {
        cout << "res = " << formula << endl;
    }
};

int main() {
    Lab1 lab1;
    lab1.obchislennya();
    lab1.vyvid();

    return 0;
}