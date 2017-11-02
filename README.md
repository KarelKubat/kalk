# kalk

## Introduction

Kalk is my small calculator which emulates C's double precision
expressions. In general, you can use Kalk just the way you'd use
expressions or functions in C. Example (kalk> is the prompt):

    kalk> 3 + 12 / 11
	4.09091 ( (int)4 (long)4 )

This way Kalk can be used to simply calculate with numbers. It
shows the result as a floating number, but also as an integer or
long. The 'standard' precedence rules are respected; e.g.,
division is evaluated before addition.

Kalk knows about hexadecimal input:

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

Kalk also understands variables:
	
	kalk> a = 100
	kalk> b = 9
	kalk> a / b
	11.1111 ( (int)11 (long)11 )
	kalk> c = fmod (a, b)
	kalk> c
	1  ( (int)1 (long) 1 )

Kalk evaluates variables as late as possible. E.g., you might
change the value of 'a' and ask to evaluate 'c' again:

    kalk> a = 200
	kalk> c
	2 ( (int)2 (long)2 )

Kalk supports a variety of operators (multiplication, division, etc.) and
unary or binary functions. Unary functions include, e.g., sin(value);
binary functions take two arguments and include, e.g., pow(a,b). Kalk
internally always uses 'doubles' to represent numbers, but you can use
operators for integers too, though precision is then of course lost. E.g.,
1<<2 left-shifts the number 1 over 2 bit positions. Also, Kalk
supports three trigonometric modes: 'deg', 'rad' and 'grad'.

Using Kalk is fairly easy, you get used to it quickly. Just start it up
and type 'help'.


## Copyright and distribution

Kalk is distributed freely. As with everything that's free,
there's also absolutely no warranty. However, Kalk shouldn't do
more harm than produce a coredump (if this occurs, mail me!).

Use Kalk at your own pleasure. If you like it, tell your friends about it.
If you really like it, send me a postcard from a far-away place. If you
don't like it, tough.

I reserve the copyright to Kalk. If you make changes or additions, please
mail me so that I have the latest version too.


## Compiling Kalk

Don't mail me with questions or bug reports unless you're talking about
the latest version.

To unpack the archive, change-dir to your "sources" directory (e.g.,
/usr/local/src) and unpack the archive. It will yield a subdirectory kalk
with all sources therein.

To compile and install Kalk, simply hit 'make install'. This will
build a local kalk program and install it into
/usr/local/bin. Edit the top level Makefile if you want to install
to a different directory.
