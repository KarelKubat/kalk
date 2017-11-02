#include "exp.h"
#include <string.h> 

void Exp::set (char const *varname)
{
    destroy ();
    type = type_variable;
    
    info = (Info *) new Variableinfo;
    info->var.name = strdup (varname);
}
