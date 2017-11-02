#include "exp.h"

void Exp::destroy ()
{
    switch (type)
    {
	case type_unaryop:
	    delete info->un.next;
	    delete info;
	    info = 0;
	    break;

	case type_binaryop:
	    delete info->bin.left;
	    delete info->bin.right;
	    delete info;
	    info = 0;
	    break;

	case type_number:
	    delete info;
	    info = 0;
	    break;

	case type_variable:
	    delete info->var.name;
	    delete info;
	    info = 0;
	    break;

	default:
	    info = 0;
	    break;
    }

    type = type_undefined;
}
