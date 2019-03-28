#include <iostream>
#include <cstdlib>

struct B
{
    virtual ~B () {}

    void DoX () {std::cout << "BX" << std::endl;}
    virtual
    void DoY () {std::cout << "BY" << std::endl;}
    virtual
    void DoZ () {std::cout << "BZ" << std::endl;}
};

struct D : B
{
    void DoX () {std::cout << "DX" << std::endl;}
    void DoY () {std::cout << "DY" << std::endl;}
};

int main ()
{
    B * bb = new B;
    bb->DoX ();
    bb->DoY ();
    bb->DoZ ();
    delete bb;
    std::cout << "---" << std::endl;

    B * bd = new D;
    bd->DoX ();
    bd->DoY ();
    bd->DoZ ();
    delete bd;
    std::cout << "---" << std::endl;

    D * dd = new D;
    dd->DoX ();
    dd->DoY ();
    dd->DoZ ();
    delete dd;
    std::cout << "---" << std::endl;

    return EXIT_SUCCESS;
}
