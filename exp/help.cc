#include "exp.h"
#include <stdio.h>

void Exp::help () const
{
    puts
(
"\n"
"Expressions have the form `symbol = expression'. To evaluate the expression\n"
"type the name of the `symbol'. The command `list' shows the defined symbols.\n"
"Default output format is decimal, use `hex', `dec' and `bin' to switch.\n"
"\n"
"Implemented functions are: pow(val1, val2), sqrt(val), ceil(val), floor(val)\n"
"    [a]sin(val), [a]cos(val, [a]tan(val), exp(val), log(val), log10(val),\n"
"    rint(val), fmod(val1, val2), fact(val).\n"
"\n"
"Implemented operators are: - (binary and unary), +, *, /.\n"
"Binary integer operators are: <<, >>, &, |, ^.\n"
"% is a shorthand for fmod().\n"
"\n"
"Numbers consist either of decimal digits, optionally in E-notation, or can\n"
"be entered as hexadecimals with a `0x' prefix. Implemented constants are\n"
"E (2.71..) and PI (3.14..). Use postfix k for kilo (*1024, as in 10k), m for\n"
"mega, g for giga, t for tera.\n"
"\n"
"Trigonometric mode can be set with `rad' (circle\n"
"is 2pi), `deg' (circle is 360) or `grad' (circle is 400).\n"
"\n"
"Type the interrupt character (usually ^C) or the end-of-file mark\n"
"(usually ^D) or `quit' to stop."
 );
}
