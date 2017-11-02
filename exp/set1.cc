#include "exp.h"

void Exp::set (Unaryop op, Exp const &e)
{
    destroy ();

    type = type_unaryop;
    info = (Info *) new Unaryopinfo;
    info->un.op = op;
    info->un.next = new Exp (e);

    if (e.type == type_number)
	set (eval ());
}
