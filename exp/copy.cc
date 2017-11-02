#include "exp.h"
#include <string.h> 

void Exp::copy (Exp const &other)
{
    type = other.type;
    switch (type)
    {
	case type_unaryop:
	    info = (Info *) new Unaryopinfo;
	    info->un.op = other.info->un.op;
	    info->un.next = new Exp (*other.info->un.next);
	    break;

	case type_binaryop:
	    info = (Info *) new Binaryopinfo;
	    info->bin.op = other.info->bin.op;
	    info->bin.left = new Exp (*other.info->bin.left);
	    info->bin.right = new Exp (*other.info->bin.right);
	    break;

	case type_number:
	    info = (Info *) new Numberinfo;
	    info->num.val = other.info->num.val;
	    break;

	case type_variable:
	    info = (Info *) new Variableinfo;
	    info->var.name = strdup (other.info->var.name);
	    break;

	default:
	    ;
    }
}
