OBJ = \
copy.o destroy.o dgr2rad.o eval.o evaluate.o exp.o exp1.o exp2.o expis.o \
help.o internal.o isevaluable.o isknown.o isnumber.o issymbol.o list.o \
opstring.o print.o printvalue.o rad2dgr.o reset.o set1.o set2.o set3.o \
set4.o setdgr.o setoutput.o fact.o setdepth.o \

.cc.o:
	c++ -c -Wall -g $<

libexp.a: $(OBJ)
	ar rvs libexp.a $(OBJ)

clean:
	rm -f $(OBJ) libexp.a
