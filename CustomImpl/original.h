struct B
{
    virtual int Preserved () {return +1;}
    virtual int Overrided () {return +2;}
};

struct D : B
{
    int Overrided () {return -2;}
};
