#include <iostream>

using namespace std;

class Worker
{
protected:
    string name;
    int salary;

public:
    Worker(string name, int salary) : name(name), salary(salary) {}
    virtual void print() = 0;
    virtual ~Worker() {}
};

class Father : public virtual Worker
{
public:
    Father(string name, int salary) : Worker(name, salary) {}
    void print()
    {
        cout << "Father: " << name << " " << salary << endl;
    }
    virtual ~Father() {}
};

class FatherWorker : public Father, public virtual Worker
{
public:
    FatherWorker(string name, int salary) : Worker(name, salary), Father(name, salary) {}
    virtual ~FatherWorker() {}
    void print()
    {
        cout << "FatherWorker: " << name << " " << salary << endl;
    }
};

int main()
{
    Worker *w1 = new Father("Ivan", 1000);
    Worker *w2 = new FatherWorker("Petro", 2000);
    w1->print();
    w2->print();
    return 0;
}