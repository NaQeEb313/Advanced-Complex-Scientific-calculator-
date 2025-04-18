#include <iostream>
#include <cmath>
using namespace std;

class simple_calculator {
protected:
    double a, b;

public:
    void setdata();
    void getdata();
    double sum() { return a + b; }
    double diff() { return a - b; }
    double product() { return a * b; }
    double divide() { return a / b; }
};

void simple_calculator::setdata() {
    cout << "Enter your first input" << endl;
    cin >> a;
    cout << "Enter your second input" << endl;
    cin >> b;
}

void simple_calculator::getdata() {
    cout << "your first input was " << a << endl;
    cout << "your second input was " << b << endl;
}

class scientific_calculator : public simple_calculator {
public:
    double power() { return pow(a, b); }
    double sin_func() { return sin(a); }
    double cos_func() { return cos(a); }
    double tan_func() { return tan(a); }
    double cosec() { return 1 / sin(a); }
    double sec() { return 1 / cos(a); }
    double cot() { return 1 / tan(a); }
    double ln() { return log(a); }
    double loga() { return log(a) / log(b); }
};

int main() {
    int t, q;
    cout << "1 for normal calculator\n2 for scientific calculator" << endl;
    cin >> t;

    switch (t) {
    case 1: {
        simple_calculator A;
        cout << "Enter your choice\n1 additions\n2 subtraction\n3 multiplication\n4 division" << endl;
        cin >> q;
        A.setdata();
        switch (q) {
        case 1:
            cout << A.sum() << endl;
            break;
        case 2:
            cout << A.diff() << endl;
            break;
        case 3:
            cout << A.product() << endl;
            break;
        case 4:
            cout << A.divide() << endl;
            break;
        default:
            cout << "invalid input" << endl;
        }
        break;
    }

    case 2: {
        scientific_calculator A;
        cout << "Enter your choice\n1 power\n2 sin(x)\n3 cos(x)\n4 tan(x)\n5 cosec(x)\n6 sec(x)\n7 cot(x)\n8 ln(x)\n9 loga(x)" << endl;
        cin >> q;
        A.setdata();
        switch (q) {
        case 1:
            cout << A.power() << endl;
            break;
        case 2:
            cout << A.sin_func() << endl;
            break;
        case 3:
            cout << A.cos_func() << endl;
            break;
        case 4:
            cout << A.tan_func() << endl;
            break;
        case 5:
            cout << A.cosec() << endl;
            break;
        case 6:
            cout << A.sec() << endl;
            break;
        case 7:
            cout << A.cot() << endl;
            break;
        case 8:
            cout << A.ln() << endl;
            break;
        case 9:
            cout << A.loga() << endl;
            break;
        default:
            cout << "Invalid input" << endl;
        }
        break;
    }
    }

    return 0;
}