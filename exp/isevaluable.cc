#include "exp.h"

int Exp::isevaluable () const
{
    if (depth >= MAXDEPTH)
	return (0);

    switch (type)
    {
	case type_unaryop:
	    return (info->un.next->isevaluable ());
	
	case type_binaryop:
	    return (info->bin.left->isevaluable () &&
		    info->bin.right->isevaluable ());
	
	case type_number:
	    return (1);

	case type_variable:
	    for (register int i = 0; i < varlistsize; i++)
		if (! strcmp (varlist [i]->info->bin.left->info->var.name,
			      info->var.name))
		    return (1);
	    return (0);

	default:
	    internal_error ();
    }

    return (0);					// this suppresses a
						// `gcc -Wall' warning
}
    
