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
protected:
    int age;
    string childName;

public:
    Father(string name, int salary, int age, string childName) : Worker(name, salary), age(age), childName(childName) {}
    void print()
    {
        cout << "Father: "
                "\nName: "
             << name << "\nSalary: " << salary << "\nAge: " << age << "\nName of a child: " << childName << endl;
    }
    virtual ~Father() {}
};

class FatherWorker : public Father, public virtual Worker
{
protected:
    int childAge;

public:
    FatherWorker(string name, int salary, int age, string childName, int childAge) : Worker(name, salary), Father(name, salary, age, childName), childAge(childAge) {}
    virtual ~FatherWorker() {}
    void print()
    {
        cout << "FatherWorker: "
             << "\nName: "
             << name << "\nSalary: " << salary << "\nAge: " << age << "\nName of a child: " << childName << "\nAge of a child: " << childAge << endl;
    }
};

int main()
{
    Worker *w1 = new Father("Ivan", 1000, 20, "Dmytro");
    Worker *w2 = new FatherWorker("Petro", 2000, 30, "Valentina", 5);
    w1->print();
    cout << endl;
    w2->print();
    return 0;
}