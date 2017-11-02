#include "exp.h"

Exp::Exp (Exp const &other)
{
    nobj++;
    
    copy (other);
}
