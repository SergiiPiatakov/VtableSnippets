#include <iostream>
#include <cstdlib>

struct A0
{
};

struct A1
{
    void DoNothing () {}
};

struct A2
{
    A2  () {}
    ~A2 () {}
    void DoNothing () {}
};


struct B1
{
    int i;
};

struct B2
{
    void DoNothing () {}
};


struct C0 : A0
{
};

struct C1 : A0
{
    int j;
};

struct C2 : B1
{
};

struct C3 : B1
{
    int j;
};


struct D0 : A0
{
    virtual void DoNothing () {}
};

struct D1 : D0
{
    virtual void DoSomething () {}
};


struct E0
{
    virtual void DoNothing () {}
};

struct E1
{
    virtual void DoSomething () {}
};

struct E2 : E0, E1
{
};


int   DoThis (int)   {return 0;}
int   DoThis (float) {return 0;}
#if 0
float DoThis (int)   {return 0;}
#endif

struct F0
{
    virtual F0 * Clone () {return 0;}
};

struct F1
{
    virtual F1 * Clone () {return 0;}
};

struct F2 : F0, F1
{
    F2 * Clone () {return 0;}
};


int main ()
{
    std::cout << "A0: " << sizeof (A0) << std::endl;
    std::cout << "A1: " << sizeof (A1) << std::endl;
    std::cout << "A2: " << sizeof (A2) << std::endl;
    std::cout << "B1: " << sizeof (B1) << std::endl;
    std::cout << "B2: " << sizeof (B2) << std::endl;
    std::cout << "C0: " << sizeof (C0) << std::endl;
    std::cout << "C1: " << sizeof (C1) << std::endl;
    std::cout << "C2: " << sizeof (C2) << std::endl;
    std::cout << "C3: " << sizeof (C3) << std::endl;
    std::cout << "D0: " << sizeof (D0) << std::endl;
    std::cout << "D1: " << sizeof (D1) << std::endl;
    std::cout << "E0: " << sizeof (E0) << std::endl;
    std::cout << "E1: " << sizeof (E1) << std::endl;
    std::cout << "E2: " << sizeof (E2) << std::endl;

    D1 * d = new D1;
    std::cout << "D1 *: " << d << std::endl;
    std::cout << "D0 *: " << static_cast <D0 *> (d) << "/" << reinterpret_cast <D0 *> (d) << std::endl;
    std::cout << "A0 *: " << static_cast <A0 *> (d) << "/" << reinterpret_cast <A0 *> (d) << std::endl;

    E2 * e = new E2;
    std::cout << "E2 *: " << e << std::endl;
    std::cout << "E1 *: " << static_cast <E1 *> (e) << "/" << reinterpret_cast <E1 *> (e) << std::endl;
    std::cout << "E0 *: " << static_cast <E0 *> (e) << "/" << reinterpret_cast <E0 *> (e) << std::endl;

    return 0;
}
