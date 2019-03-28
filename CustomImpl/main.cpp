#if 1
#include "original.h"
#else
#include "custom.h"
#endif

int main (int, char **)
{
    B b;
    D d;
    B * bb = & b;
    B * bd = & d;
    D * dd = & d;

    if (+1 != bb->Preserved () ) return 1;
    if (+2 != bb->Overrided () ) return 2;

    if (+1 != bd->Preserved () ) return 3;
    if (-2 != bd->Overrided () ) return 4;

    if (+1 != dd->Preserved () ) return 5;
    if (-2 != dd->Overrided () ) return 6;

    return 0;
}
