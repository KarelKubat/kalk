/*
class Expression: internal representation of an expression.
*/

#ifndef _EXP_H_
#define _EXP_H_

#define ZERO	    1e-6			    // 0 for practical
						    // purposes
#define MAXVAL	    9e9				    // biggest number

#define MAXDEPTH    1000			    // maximum recursion
						    // depth in evaluation

#include <string.h>
#include <stdlib.h>
#include <math.h>

class Exp
{
    public:
        enum Trigformat                             // trigonometric format:
        {                                           // degrees (360 circle),
            dgr_deg,                                // rad (2pi circle),
            dgr_rad,                                // grad (400 circle)
            dgr_grad,
        };
        enum Outputformat                           // how to print values
        {                                           // decimal, hexadecimal
            output_dec,                             // or binary
            output_hex,
            output_bin,
        };
	enum Unaryop				    // implemented unary
	{					    // operators and
	    unop_min,				    // functions with one
            unop_toggle,			    // argument
	    fun_sqrt,	
	    fun_sin,
	    fun_asin,
	    fun_cos,
	    fun_acos,
	    fun_tan,
	    fun_atan,
	    fun_ceil,
	    fun_floor,
	    fun_exp,
	    fun_log,
	    fun_log10,
	    fun_rint,
	    fun_fact,
	};
	enum Binaryop				    // implemented binary
	{					    // operators and functions
	    binop_min,				    // with two arguments
	    binop_plus,
	    binop_mul,
	    binop_div,
	    binop_assign,
            binop_lshift,
            binop_rshift,
            binop_and,
            binop_or,
            binop_xor,
	    fun_pow,
	    fun_fmod,
	};
	enum Type				    // type of this
	{					    // expression:
	    type_unaryop,			    // unary op, binary op,
	    type_binaryop,			    // or a number
	    type_number,			    // or a variable
	    type_variable,
	    type_undefined,			    // undef: for emergencies
	};
	struct Unaryopinfo			    // representation of
	{                                           // unary operator or
	    Unaryop op;				    // func with 1 arg
	    Exp *next;
	};
	struct Binaryopinfo			    // representation of
	{					    // binary op or function
	    Binaryop op;			    // with 2 args
	    Exp *left, *right;
	};
	struct Numberinfo			    // representation of
	{					    // numeric constant
	    double val;
	};
	struct Variableinfo			    // representation of
	{					    // variable info
	    char *name;
	};
	union Info				    // representation of
	{					    // either 1-arg or 2-arg
	    Unaryopinfo un;			    // information
	    Binaryopinfo bin;
	    Numberinfo num;
	    Variableinfo var;
	};
    
	~Exp ();				    // destructor
    
	Exp ();					    // constructors
	Exp (Exp const &other);

	Exp const &operator= (Exp const &other);    // overloaded assignment

	void set (Unaryop op, Exp const &e);	    // define expression
	void set (Binaryop op, Exp const &e1,
		  Exp const &e2);
	void set (double val);
	void set (char const *varname);

	void reset ();				    // free all memory

	int issymbol () const;			    // true if it's a symbol
	int isnumber () const;			    // true if it's a number
	int isknown () const;			    // true if all components
						    // can be evaluated
    
	double eval () const;			    // evaluate expression

	void help () const;			    // show help

	void list () const;			    // list symbols
        
        void printvalue (double val) const;         // output
        void setoutput (Outputformat f) const;      // define output
        void setdgr (Trigformat f) const;           // define trig format

	void setdepth(void);			    // reset eval depth

    private:
	void copy (Exp const &other);		    // copy/destroy primitives
	void destroy ();

	double evaluate () const;		    // evaluate expression
						    // wi/ MAXDEPTH

	double fact(double v) const;		    // Factorial 

	int isevaluable () const;		    // check if known
						    // wi/ MAXDEPTH
    
	void print () const;			    // print out expression

	char const *opstring () const;		    // return operator as a
						    // string

	void internal_error () const;		    // something is very wrong
        
        double rad2dgr (double v) const;            // Deg/Grad/Rad to Rad and
        double dgr2rad (double v) const;            // vv. conversions
    
	Type type;				    // type of this expression
	Info *info;				    // info part of this exp

	static Exp **varlist;			    // list of all symbol exps
	static int varlistsize;			    // # of symbol expressions
    
	static int nobj;			    // # of objects

	static int depth;			    // depth of evaluation
        
        static Outputformat format;                 // current output format
        
        static Trigformat trigformat;               // trigonometric format
};

#endif
