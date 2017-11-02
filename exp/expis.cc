#include "exp.h"

Exp const &Exp::operator= (Exp const &other)
{
    if (this != &other)
    {
	destroy ();
	copy (other);
    }
    return (*this);
}
