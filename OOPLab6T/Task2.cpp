#include <iostream>
#include <cmath>

using namespace std;

class Function
{
protected:
    double a, b;

public:
    Function(double a, double b) : a(a), b(b) {}
    virtual double calculate(double x) = 0;
};

class Line : public Function
{
public:
    Line(double a, double b) : Function(a, b) {}
    double calculate(double x)
    {
        cout << "Line: " << endl;
        return a * x + b;
    }
};

class Ellipse : public Function
{
public:
    Ellipse(double a, double b) : Function(a, b) {}
    double calculate(double x)
    {
        // return sqrt(a * a - x * x) + b;
        // return pow((x / a), 2) + pow((y / b), 2);
        cout << "Ellipse: " << endl;
        return b * sqrt(1 - (x * x) / (a * a));
    }
};

class Hyperbola : public Function
{
public:
    Hyperbola(double a, double b) : Function(a, b) {}
    double calculate(double x)
    {
        cout << "Hyperbola: " << endl;
        // return sqrt(a * a + x * x) + b;
        return b * sqrt((x * x) / (a * a) - 1);
    }
};

int main()
{
    Function *f1 = new Line(1, 2);
    Function *f2 = new Ellipse(3, 2);
    Function *f3 = new Hyperbola(1, 2);
    cout << f1->calculate(1) << endl;
    cout << f2->calculate(2) << endl;
    cout << f3->calculate(2) << endl;
    return 0;
}
