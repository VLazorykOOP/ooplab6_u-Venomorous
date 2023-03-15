#include <iostream>

using namespace std;

class Base
{
protected:
    int x;

public:
    Base() : x(0) {}
    ~Base() {}
};

class DerivedV : virtual public Base
{
protected:
    int y;

public:
    DerivedV() : y(0) {}
    ~DerivedV() {}
};

class DerivedLeftV : virtual public Base, virtual public DerivedV
{
protected:
    int zL;

public:
    DerivedLeftV() : zL(0) {}
    ~DerivedLeftV(){};
};

class DerivedRightV : virtual public Base, virtual public DerivedV
{
protected:
    int zR;

public:
    DerivedRightV() : zR(0) {}
    ~DerivedRightV(){};
};

class DerivedEndV : public DerivedLeftV, public DerivedRightV
{
protected:
    int zE;

public:
    DerivedEndV() : zE(0) {}
    ~DerivedEndV(){};
};

class Derived : public Base
{
protected:
    int y;

public:
    Derived() : y(0) {}
    ~Derived() {}
};

class DerivedLeft : public Base, public Derived
{
protected:
    int zL;

public:
    DerivedLeft() : zL(0) {}
    ~DerivedLeft(){};
};

class DerivedRight : virtual public Base, virtual public Derived
{
protected:
    int zR;

public:
    DerivedRight() : zR(0) {}
    ~DerivedRight(){};
};

class DerivedEnd : public DerivedLeft, public DerivedRight
{
protected:
    int zE;

public:
    DerivedEnd() : zE(0) {}
    ~DerivedEnd(){};
};

int main()
{
    DerivedEnd *d = new DerivedEnd();

    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    cout << sizeof(DerivedLeft) << endl;
    cout << sizeof(DerivedRight) << endl;
    cout << sizeof(DerivedEnd) << endl;

    cout << sizeof(DerivedV) << endl;
    cout << sizeof(DerivedLeftV) << endl;
    cout << sizeof(DerivedRightV) << endl;
    cout << sizeof(DerivedEndV) << endl;

    return 0;
}