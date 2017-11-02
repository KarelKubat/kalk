#include "exp.h"

char const *Exp::opstring () const
{
    switch (type)
    {
	case type_unaryop:
	    switch (info->un.op)
	    {
		case unop_min:
		    return ("-");
                case unop_toggle:
                    return ("~");
		case fun_sqrt:
		    return ("sqrt");
		case fun_sin:
		    return ("sin");
		case fun_asin:
		    return ("asin");
		case fun_cos:
		    return ("cos");
		case fun_acos:
		    return ("acos");
		case fun_tan:
		    return ("tan");
		case fun_atan:
		    return ("atan");
		case fun_floor:
		    return ("floor");
		case fun_ceil:
		    return ("ceil");
		case fun_exp:
		    return ("exp");
		case fun_log:
		    return ("log");
		case fun_log10:
		    return ("log10");
		case fun_rint:
		    return ("rint");
		default:
		    internal_error ();
	    }
		
	case type_binaryop:
	    switch (info->bin.op)
	    {
		case binop_min:
		    return ("-");
		case binop_mul:
		    return ("*");
		case binop_div:
		    return ("/");
		case binop_plus:
		    return ("+");
		case binop_assign:
		    return ("=");
                case binop_lshift:
                    return ("<<");
                case binop_rshift:
                    return (">>");
                case binop_and:
                    return ("&");
                case binop_or:
                    return ("|");
                case binop_xor:
                    return ("^");
		case fun_pow:
		    return ("pow");
		case fun_fmod:
		    return ("fmod");
		default:
		    internal_error ();
	    }
	
	default:
	    internal_error ();
    }
    
    return ("");
}
