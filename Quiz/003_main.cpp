struct A
{
    virtual A & instance () {return * this;}
};

struct B
{
    virtual B & instance () {return * this;}
};

struct C : A, B
{
    C & instance () override {return * this;}
};

int main ()
{
    return 0;
}
