#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

struct data_t {
    void* values[SIZE];
    int types[SIZE];
};

class Lab1 {
private:
    int a = 25, b = 8;
    short c = 3, d = 2;
    float e = 1.1f;
    
    double implicit_result;
    double explicit_result;

public:
    void calculate() {
        implicit_result = ((a - b) / (c * d)) * e;

        explicit_result = (static_cast<double>(a - b) / (c * d)) * e;
    }

    void print_data(struct data_t* data_ptr) {
        cout << "--- Vymiry ta znachennya zminnykh iz struktury data_t ---" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "Element " << i << " (Typ: " << data_ptr->types[i] << "): ";
            
            switch (data_ptr->types[i]) {
                case 0: // int
                    cout << *static_cast<int*>(data_ptr->values[i]) << endl;
                    break;
                case 1: // short
                    cout << *static_cast<short*>(data_ptr->values[i]) << endl;
                    break;
                case 2: // float
                    cout << *static_cast<float*>(data_ptr->values[i]) << endl;
                    break;
                default:
                    cout << "Nevidomyy typ" << endl;
            }
        }
        cout << endl;
    }

    void display_results() {
        data_t my_data = {
            { &a, &b, &c, &d, &e },
            { 0, 0, 1, 1, 2 }
        };

        print_data(&my_data);

        cout << fixed << setprecision(3);
        cout << "--- Rezultaty obchyslen (Variant 18) ---" << endl;
        cout << "Implicit result (bez pryvedennya): " << implicit_result << endl;
        cout << "Explicit result (z static_cast):   " << explicit_result << endl;
    }
};

int main() {
    Lab1 lab1;
    lab1.calculate();
    lab1.display_results();

    return 0;
}