#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class simple_calculator {
protected:
    double a, b;

public:
    void setTwoInputs();
    void setSingleInput();
    void getInputs();
    double sum() { return a + b; }
    double diff() { return a - b; }
    double product() { return a * b; }
    double divide() {
        if (b == 0) {
            cout << "Error: Division by zero." << endl;
            return NAN;
        }
        return a / b;
    }
};

void simple_calculator::setSingleInput() {
    cout << "Enter your input: ";
    cin >> a;
}

void simple_calculator::setTwoInputs() {
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;
}

void simple_calculator::getInputs() {
    cout << "Input a: " << a << ", Input b: " << b << endl;
}

class scientific_calculator : public simple_calculator {
public:
    double power() { return pow(a, b); }
    double sin_func() { return sin(a); }
    double cos_func() { return cos(a); }
    double tan_func() { return tan(a); }
    double arctan_func() { return atan(a); }
    double arcsin_func() {
        if (a >= -1 && a <= 1) return asin(a);
        cout << "Error: sin-1(a) is not defined for this input." << endl;
        return NAN;
    }
    double arccos_func() {
        if (a >= -1 && a <= 1) return acos(a);
        cout << "Error: cos-1(a) is not defined for this input." << endl;
        return NAN;
    }
    double arccosec_func() {
        if (a == 0) {
            cout << "Error: cosec-1(a) is not defined at 0." << endl;
            return NAN;
        }
        return asin(1 / a);
    }
    double arcsec_func() {
        if (a == 0) {
            cout << "Error: sec-1(a) is not defined at 0." << endl;
            return NAN;
        }
        return acos(1 / a);
    }
    double arccot_func() {
        if (a == 0) {
            cout << "Error: cot-1(a) is not defined at 0." << endl;
            return NAN;
        }
        return atan(1 / a);
    }
    double cosec() {
        if (sin(a) == 0) {
            cout << "Error: sin(a) is zero. Cosec undefined." << endl;
            return NAN;
        }
        return 1 / sin(a);
    }
    double sec() {
        if (cos(a) == 0) {
            cout << "Error: cos(a) is zero. Sec undefined." << endl;
            return NAN;
        }
        return 1 / cos(a);
    }
    double cot() {
        if (tan(a) == 0) {
            cout << "Error: tan(a) is zero. Cot undefined." << endl;
            return NAN;
        }
        return 1 / tan(a);
    }
    double ln() {
        if (a <= 0) {
            cout << "Error: ln is only defined for a > 0." << endl;
            return NAN;
        }
        return log(a);
    }
    double loga() {
        if (a <= 0 || b <= 0 || a == 1) {
            cout << "Error: log base must be > 0 and \u2260 1, and value must be > 0." << endl;
            return NAN;
        }
        return log(b) / log(a);
    }
};

class complex {
private:
    double a, b;
public:
    void set1data(double p, double q) { a = p; b = q; }
    void input() {
        cout << "Enter the real part: ";
        cin >> a;
        cout << "Enter the imaginary part: ";
        cin >> b;
    }
    void display() { cout << a << " + i" << b << endl; }

    friend complex comp_sum(complex n1, complex n2);
    friend complex comp_diff(complex n1, complex n2);
    friend complex comp_product(complex n1, complex n2);
    friend complex conjugate(complex n1);
    friend complex comp_square(complex n1);
    friend complex comp_cube(complex n1);
    friend double comp_magnitude(complex n1);
    friend double comp_argument(complex n1);
};

complex comp_sum(complex n1, complex n2) {
    complex c;
    c.set1data(n1.a + n2.a, n1.b + n2.b);
    return c;
}

complex comp_diff(complex n1, complex n2) {
    complex c;
    c.set1data(n1.a - n2.a, n1.b - n2.b);
    return c;
}

complex comp_product(complex n1, complex n2) {
    complex c;
    c.set1data((n1.a * n2.a - n1.b * n2.b), (n1.a * n2.b + n1.b * n2.a));
    return c;
}

complex conjugate(complex n1) {
    complex c;
    c.set1data(n1.a, -n1.b);
    return c;
}

complex comp_square(complex n1) {
    return comp_product(n1, n1);
}

complex comp_cube(complex n1) {
    return comp_product(comp_product(n1, n1), n1);
}

double comp_magnitude(complex n1) {
    return sqrt(n1.a * n1.a + n1.b * n1.b);
}

double comp_argument(complex n1) {
    return atan2(n1.b, n1.a);
}


class point {
    protected:
        
        int* d;
    
    public:
    int dimension;
        void setdimsn() {
            cout << "Enter the dimensions of points - ";
            cin >> dimension;
            d = new int[dimension];
        }
    
        void getdimsn() {
            cout << "The dimensions of points are - " << dimension << endl;
        }
    
        void setdata() {
            cout << "Enter the values of dimensions" << endl;
            for (int a = 0; a < dimension; a++) {
                cout << "Value of D" << a + 1 << " - ";
                cin >> d[a];
            }
        }
    
        void getdata() {
            cout << "The point is - (";
            for (int a = 0; a < dimension; a++) {
                cout << d[a];
                if (a != dimension - 1)
                    cout << ", ";
            }
            cout << ")" << endl;
        }
    
        friend point sum(point p1, point p2);
        friend float magnitude(point p1);
        friend point diff(point p1, point p2);
        friend float angle(point p1, point p2);
        friend point setvalue(point p1);
        friend float distance(point p1,point p2);
    };
    
    point sum(point p1, point p2) {
        point p3;
        p3.dimension = p1.dimension;
        p3.d = new int[p3.dimension];
        for (int i = 0; i < p3.dimension; i++) {
            p3.d[i] = p1.d[i] + p2.d[i];
        }
        return p3;
    }
    
    point diff(point p1, point p2) {
        point p3;
        p3.dimension = p1.dimension;
        p3.d = new int[p3.dimension];
        for (int i = 0; i < p3.dimension; i++) {
            p3.d[i] = p1.d[i] - p2.d[i];
        }
        return p3;
    }
    
    float magnitude(point p1) {
        float total = 0;
        for (int i = 0; i < p1.dimension; i++) {
            total += pow(p1.d[i], 2);
        }
        return sqrt(total);
    }
    
    float angle(point p1, point p2) {
        float dot = 0;
        for (int i = 0; i < p1.dimension; i++) {
            dot += p1.d[i] * p2.d[i];
        }
        float mag1 = magnitude(p1);
        float mag2 = magnitude(p2);
        return acos(dot / (mag1 * mag2));  // in radians
    }
    
    point setvalue(point p1) {
        point A;
        A.dimension = p1.dimension;
        A.d = new int[A.dimension];
        for (int i = 0; i < A.dimension; i++) {
            A.d[i] = p1.d[i];
        }
        return A;
    }
    
    float distance(point p1,point p2) {
        float total = 0;
        for (int i = 0; i < p1.dimension; i++) {
            total += pow(p1.d[i]-p2.d[i], 2);
        }
        return sqrt(total);
    }



int main() {
    int type, choice;
    cout << "Select Calculator Type:\n1. Basic Calculator\n2. Scientific Calculator\n3. Complex Number Calculator\n4. Coordinate Points" << endl;
    cin >> type;

    cout << fixed << setprecision(4);

    switch (type) {
        case 1: {
            simple_calculator calc;
            cout << "Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division" << endl;
            cin >> choice;

            calc.setTwoInputs();

            switch (choice) {
                case 1: cout << "Result: " << calc.sum() << endl; break;
                case 2: cout << "Result: " << calc.diff() << endl; break;
                case 3: cout << "Result: " << calc.product() << endl; break;
                case 4: cout << "Result: " << calc.divide() << endl; break;
                default: cout << "Invalid choice." << endl;
            }
            break;
        }

        case 2: {
            scientific_calculator calc;
            cout << "Choose operation:\n"
                 << "1. Power (a^b)\n2. sin(a)\n3. cos(a)\n4. tan(a)\n5. cosec(a)\n"
                 << "6. sec(a)\n7. cot(a)\n8. ln(a)\n9. log base a of b\n"
                 << "10. sin-1(a)\n11. cos-1(a)\n12. tan-1(a)\n"
                 << "13. cosec-1(a)\n14. sec-1(a)\n15. cot-1(a)" << endl;
            cin >> choice;

            if (choice == 1 || choice == 9)
                calc.setTwoInputs();
            else
                calc.setSingleInput();

            switch (choice) {
                case 1: cout << "Result: " << calc.power() << endl; break;
                case 2: cout << "Result: " << calc.sin_func() << endl; break;
                case 3: cout << "Result: " << calc.cos_func() << endl; break;
                case 4: cout << "Result: " << calc.tan_func() << endl; break;
                case 5: cout << "Result: " << calc.cosec() << endl; break;
                case 6: cout << "Result: " << calc.sec() << endl; break;
                case 7: cout << "Result: " << calc.cot() << endl; break;
                case 8: cout << "Result: " << calc.ln() << endl; break;
                case 9: cout << "Result: " << calc.loga() << endl; break;
                case 10: cout << "Result: " << calc.arcsin_func() << endl; break;
                case 11: cout << "Result: " << calc.arccos_func() << endl; break;
                case 12: cout << "Result: " << calc.arctan_func() << endl; break;
                case 13: cout << "Result: " << calc.arccosec_func() << endl; break;
                case 14: cout << "Result: " << calc.arcsec_func() << endl; break;
                case 15: cout << "Result: " << calc.arccot_func() << endl; break;
                default: cout << "Invalid choice." << endl;
            }
            break;
        }

        case 3: {
            complex c1, c2, result;
            cout << "Choose Complex Operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n"
                 << "4. Conjugate\n5. Square\n6. Cube\n7. Magnitude\n8. Argument" << endl;
            cin >> choice;

            if (choice >= 1 && choice <= 3) {
                cout << "Enter first complex number:\n"; c1.input();
                cout << "Enter second complex number:\n"; c2.input();
            } else {
                cout << "Enter complex number:\n"; c1.input();
            }

            switch (choice) {
                case 1: result = comp_sum(c1, c2); result.display(); break;
                case 2: result = comp_diff(c1, c2); result.display(); break;
                case 3: result = comp_product(c1, c2); result.display(); break;
                case 4: result = conjugate(c1); result.display(); break;
                case 5: result = comp_square(c1); result.display(); break;
                case 6: result = comp_cube(c1); result.display(); break;
                case 7: cout << "Magnitude: " << comp_magnitude(c1) << endl; break;
                case 8: cout << "Argument (in radians): " << comp_argument(c1) << endl; break;
                default: cout << "Invalid choice." << endl;
            }
            break;
        }

        case 4: {
            int choice;
            point A, B;
        
            A.setdimsn();
            A.setdata();
        
            B.setdimsn();
            B.setdata();
        
            A.getdata();
            B.getdata();
        
            cout << "Enter:" << endl
                 << "1 for magnitude of A" << endl
                 << "2 for addition (A + B)" << endl
                 << "3 for difference (A - B)" << endl
                 << "4 for distance between A and B" << endl
                 << "5 for angle between A and B" << endl;
        
            cin >> choice;
        
            switch (choice) {
                case 1:
                    cout << "The magnitude of coordinate A is: " << magnitude(A) << endl;
                    break;
        
                case 2:
                    if (A.dimension != B.dimension) {
                        cout << "Error: Dimension mismatch! Cannot perform addition." << endl;
                    } else {
                        point result = sum(A, B);
                        cout << "Sum of coordinates: ";
                        result.getdata();
                    }
                    break;
        
                case 3:
                    if (A.dimension != B.dimension) {
                        cout << "Error: Dimension mismatch! Cannot perform subtraction." << endl;
                    } else {
                        point result = diff(A, B);
                        cout << "Difference of coordinates: ";
                        result.getdata();
                    }
                    break;
        
                case 4:
                    if (A.dimension != B.dimension) {
                        cout << "Error: Dimension mismatch! Cannot calculate distance." << endl;
                    } else {
                        cout << "Distance between coordinates: " << distance(A, B) << endl;
                    }
                    break;
        
                case 5:
                    if (A.dimension != B.dimension) {
                        cout << "Error: Dimension mismatch! Cannot calculate angle." << endl;
                    } else {
                        cout << "Angle between coordinates (in radians): " << angle(A, B) << endl;
                    }
                    break;
        
                default:
                    cout << "Invalid input." << endl;
            }
        
            break;
        }
        

        default:
            cout << "Invalid calculator type." << endl;
            break;
    }

    return 0;
}
