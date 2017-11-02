#include "exp.h"
#include <stdio.h>

void Exp::print () const
{
    switch (type)
    {
	case type_unaryop:
	    switch (info->un.op)
	    {
		case unop_min:
                case unop_toggle:
		    printf ("%s(", opstring ());
		    info->un.next->print ();
		    putchar (')');
		    break;
		case fun_sqrt:
		case fun_sin:
		case fun_asin:
		case fun_cos:
		case fun_acos:
		case fun_tan:
		case fun_atan:
		case fun_floor:
		case fun_ceil:
		case fun_exp:
		case fun_log:
		case fun_log10:
		case fun_rint:
		    printf ("%s(", opstring ());
		    info->un.next->print ();
		    putchar (')');
		    break;

		default:
		    internal_error ();
	    }
	    break;
	
	case type_binaryop:
	    switch (info->bin.op)
	    {
		case binop_min:
		case binop_plus:
		case binop_mul:
		case binop_div:
		case binop_assign:
                case binop_lshift:
                case binop_rshift:
                case binop_and:
                case binop_or:
                case binop_xor:
		    putchar ('(');
		    info->bin.left->print ();
		    printf ("%s", opstring ());
		    info->bin.right->print ();
		    putchar (')');
		    break;
		case fun_pow:
		case fun_fmod:
		    printf ("%s(", opstring ());
		    info->bin.left->print ();
		    putchar (',');
		    info->bin.right->print ();
		    putchar (')');
		    break;
		
		default:
		    internal_error ();
	    }
	    break;
	
	case type_number:
            printvalue (info->num.val);
            break;

	case type_variable:
	    printf ("%s", info->var.name);
	    break;

	default:
	    internal_error ();
    }
}
