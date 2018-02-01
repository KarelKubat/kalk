# kalk

## Introduction

kalk is my small calculator which emulates C's double precision expressions. I
wrote kalk back in 1994 at the Univ. of Groningen (Netherlands) when I was
playing around with LALR-1 grammars and lexical analyzers, and it still seems
useful; it's in fact my favorite calculator.

In general, you can use kalk just the way you'd use
expressions or functions in C. Example (`kalk>` is the prompt):

    kalk> 3 + 12 / 11
	4.09091 ( (int)4 (long)4 )

This way kalk can be used to simply calculate with numbers. It
shows the result as a floating number, but also as an integer or
long. The 'standard' precedence rules are respected; e.g.,
division is evaluated before addition.

kalk knows about hexadecimal input:

    kalk> 0xdeadbeef
	3.73593e+9

You can use the output formats dec (decimal), hex (hexadecimal) and
bin (binary):

    kalk> a=12
	12 ( (int)12 (long)12 )
	kalk> hex
	kalk> a
	0xc
	kalk> bin
	kalk> a
	1100
	kalk> dec
	kalk> a
	12 ( (int)12 (long)12 )

Postfixing a number with `k` multiplies by 1024; postfixing with `m`
multiplies by 1024*1024; postfixing by `g` multiplies by 1024*1024*1024:

    kalk> a=4k
    4096 ( (int)4096 (long)4096 )
    kalk> b=5m
    5.24288e+06 ( (int)5242880 (long)5242880 )
    kalk> c=6g
    6.44245e+09 ( (int)-2147483648 (long)6442450944 )

For example, 12 Gigs plus 512 Megs is 12.5 Gigs:

    kalk> (12g + 512m) / 1g
    12.5 ( (int)12 (long)12 )

kalk also understands variables:

	kalk> a = 100
	kalk> b = 9
	kalk> a / b
	11.1111 ( (int)11 (long)11 )
	kalk> c = fmod (a, b)
	kalk> c
	1  ( (int)1 (long) 1 )

kalk evaluates variables as late as possible. E.g., you might
change the value of `a` and ask to evaluate `c` again:

    kalk> a = 200
	kalk> c
	2 ( (int)2 (long)2 )

kalk understands program arguments, which can be used to "preload" an
expression before going into interactive mode:

    # As if 1 + 3 were typed as the first input
    $ kalk 1 + 3
    4
    kalk>
    
    # 1 * 100 + 2 is given as one argument here to prevent the shell
    # from expanding the *
    $ kalk "1 * 100 + 2"
    102
    kalk>

kalk supports a variety of operators (multiplication, division, etc.) and
unary or binary functions. Unary functions include, e.g., `sin(value)`;
binary functions take two arguments and include, e.g., `pow(a,b)`. kalk
internally always uses 'doubles' to represent numbers, but you can use
operators for integers too, though precision is then of course lost. E.g.,
`1<<2` left-shifts the number 1 over 2 bit positions. Also, kalk
supports three trigonometric modes: `deg`, `rad` and `grad`.

Using kalk is fairly easy, you get used to it quickly. Just start it up
and type `help`.


## Copyright and distribution

kalk is distributed freely. As with everything that's free,
there's also absolutely no warranty. However, kalk shouldn't do
more harm than produce a coredump (if this occurs, mail me!).

Use kalk at your own pleasure. If you like it, tell your friends about it.
If you really like it, send me a postcard from a far-away place. If you
don't like it, tough.

I reserve the copyright to kalk. If you make changes or additions, please
mail me so that I have the latest version too.


## Compiling kalk

Don't mail me with questions or bug reports unless you're talking about
the latest version.

To unpack the archive, change-dir to your "sources" directory (e.g.,
`$HOME/src`) and unpack the archive or clone the repository. It will yield a
subdirectory `kalk` with all sources therein.

To compile and install kalk, simply hit `make install`. This will
build a local kalk program and install it into
`$HOME/bin`. Edit the top level Makefile if you want to install
to a different directory.

### Modifying kalk: Dependencies

In addition to a C++ compiler, you will need `bison` and `flex` when you
want to change kalk's grammar by e.g. introducting a new function.
