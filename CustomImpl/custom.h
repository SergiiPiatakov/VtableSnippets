// Forward declaration.
class B;
class D;

int Preserved (B * p);
int Overrided (B * p);

// Implementation.
int BPreserved (B *) {return +1;}
int BOverrided (B *) {return +2;}
int DOverrided (D *) {return -2;}

// The Virtual Tables.
void * bvtab [] = {
    reinterpret_cast <void *> (& BPreserved)
  , reinterpret_cast <void *> (& BOverrided)
};

void * dvtab [] = {
    reinterpret_cast <void *> (& BPreserved)
  , reinterpret_cast <void *> (& DOverrided)
};

// Class hierarchy.
struct B
{
    B ()
    {
        vtab = bvtab;
    }

    // Call wrappers.
    int Preserved () {return ::Preserved (this);}
    int Overrided () {return ::Overrided (this);}

    void * vtab;
};

struct D : B
{
    D ()
    {
        vtab = dvtab;
    }
};

// Overloading resolution.
int Preserved (B * p)
{
    return reinterpret_cast <int (**)(B *)> (p->vtab) [0](p);
}

int Overrided (B * p)
{
    return reinterpret_cast <int (**)(B *)> (p->vtab) [1](p);
}
