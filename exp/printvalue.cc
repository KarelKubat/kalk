
#include "exp.h"
#include <stdio.h>

void Exp::printvalue (double val) const
{
    int
        i,
        tmp,
	printed = 0;

    switch (format)
    {
        case output_dec:
            printf ("%g ( (int)%d (long)%ld )", val, (int) val, (long) val);
            break;
        case output_hex:
            printf ("0x%x", (int) val);
            break;
        case output_bin:
            tmp = (int) val;
            for (i = sizeof (int) * 8 - 1; i >= 0; i--)
            {
                if (tmp & (1 << i))
                {
                    putchar ('1');
                    printed++;
                }
                else if (printed)
                    putchar ('0');
            }
            if (! printed)
                putchar ('0');
            break;
        default:
            internal_error ();
    }
}
