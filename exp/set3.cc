#include "exp.h"

void Exp::set (double val)
{
    destroy ();

    type = type_number;
    info = (Info *) new Numberinfo;
    info->num.val = val;
}
