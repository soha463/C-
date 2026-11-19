#include <iostream>
using namespace std;

class Person
{
    char name[64];
    int age;
    char address[64];
    float basic, hra, da, pf, net;

public:

    // Constructor
    Person()
    {
        cout << "\nEnter Name: ";
        cin.getline(name, 64);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Address: ";
        cin.getline(address, 64);

        cout << "Enter Basic Salary: ";
        cin >> basic;
        cin.ignore();

        hra = basic * 0.20;
        da = basic * 0.10;
        pf = basic * 0.12;

        net = basic + hra + da - pf;
    }

    // Inline functions
    inline int getAge()
    {
        return age;
    }

    inline char* getName()
    {
        return name;
    }

    // Salary Slip
    inline void salarySlip()
    {
        cout << "\n----- SALARY SLIP -----";
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nBasic Salary: " << basic;
        cout << "\nHRA: " << hra;
        cout << "\nDA: " << da;
        cout << "\nPF: " << pf;
        cout << "\nNet Salary: " << net << endl;
    }
};

// Find youngest and oldest person
inline void findAge(Person p[], int n)
{
    int young = 0, old = 0;

    for (int i = 1; i < n; i++)
    {
        if (p[i].getAge() < p[young].getAge())
            young = i;

        if (p[i].getAge() > p[old].getAge())
            old = i;
    }

    cout << "\n===== AGE RESULTS =====";

    cout << "\nYoungest Person: " << p[young].getName();
    cout << "\nAge: " << p[young].getAge();

    cout << "\n\nEldest Person: " << p[old].getName();
    cout << "\nAge: " << p[old].getAge() << endl;
}

int main()
{
    Person p[10];

    findAge(p, 10);

    cout << "\n===== SALARY SLIPS =====";

    for (int i = 0; i < 10; i++)
    {
        p[i].salarySlip();
    }

    return 0;
}