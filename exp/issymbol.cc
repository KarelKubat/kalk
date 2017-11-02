#include "exp.h"

int Exp::issymbol () const
{
    return (type == type_variable);
}
