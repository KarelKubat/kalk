# Makefile for kalk

VER = 1.43
BINDIR ?= "$$HOME/bin"

foo:
	@cat Makefile.help
	@exit 1

kalk: kalk.o components
	c++ -g -o kalk kalk.o -Lgetline -lgetline \
	    -Lgram -lgram -Lexp -lexp -Lgetline -lgetline -lm

components:
	make -C exp
	make -C gram
	make -C getline

.cc.o:
	c++ -c -g -Wall -DVER=\"$(VER)\" $<

install: $(BINDIR)/kalk

$(BINDIR)/kalk: kalk
	install -s kalk $(BINDIR)

clean:
	rm -f kalk kalk.o
	make -C exp clean
	make -C gram clean
	make -C getline clean

kalk.o: Makefile

dist: clean
	cd .. && tar cvzf /tmp/kalk.tar.gz --exclude .git kalk/
