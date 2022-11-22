#include <iostream>
using namespace std;
class Dollar
{
public:
    Dollar() {}
    ~Dollar() {}

    virtual void get() = 0;
    virtual float amount() = 0;
};
class Rupees : virtual public Dollar
{
    float Rs, dl;

public:
    Rupees() : Dollar()
    {
        cout << "Constructor called for Rupees\n"
             << endl;
    }
    void get()
    {
        try
        {
            cout << "Enter amount of Rupees: " << endl;
            cin >> Rs;
            cout << "Enter Conversion rate in Dollar:";
            cin >> dl;
            if (dl == 0)
                throw " Dollar can't be 0 ";
        }
        catch (...)
        {
            cout << "Exception handled and not a valid input\n"
                 << endl;
        }
    }
    float amount()
    {
        float result = Rs * dl;
        cout << "The amount of Rupees is: " << result << endl;
    }
};
class Euro : virtual public Dollar
{
    float euro, dl;

public:
    Euro() : Dollar()
    {
        cout << "Constructor called for Euro\n"
             << endl;
    }
    void get()
    {
        cout << "Enter amount of Euro: " << endl;
        cin >> euro;
        cout << "Enter conversion rate: ";
        cin >> dl;
    }
    float amount()
    {
        float result = euro * dl;
        cout << "The amount of Euro is: " << result << endl;
        return result;
    }

    Euro operator++()
    {
        Euro x;
        x.euro = ++euro;
        x.dl = ++dl;
        cout << "amount after incrementing is: " << endl;
    }
};

class Pound : virtual public Dollar
{
    float p, dl;

public:
    Pound() : Dollar()
    {
        cout << "Constructor called for Pound\n"
             << endl;
    }
    void get()
    {
        cout << "Enter amount of Pound: " << endl;
        cin >> p;
        cout << "Enter conversion rate: ";
        cin >> dl;
    }
    float amount()
    {
        float result = p * dl;
        cout << "The amount of Pound is: " << result << endl;
        return result;
    }

    friend void operator++(Pound &x)
    {
        x.p = x.p + 1;
        cout << "amount of Pound after incrementing is: " << endl;
    }
};
int main()
{
    Dollar *d1, *d2, *d3;
    Rupees r;
    Euro t;

    Pound s;
    d1 = &r;
    d2 = &t;

    d3 = &s;

    d1->get();
    d1->amount();
    d2->get();
    d2->amount();
    
    ++t;
    d2->amount();

    d3->get();
    d3->amount();

    ++s;
    d3->amount();
    return 0;
}