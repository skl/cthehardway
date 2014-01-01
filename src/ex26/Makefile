PREFIX?=/usr/local
CFLAGS=-Wall -g

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d ${DESTDIR}/${PREFIX}/bin/
	install devpkg ${DESTDIR}/${PREFIX}/bin/

clean:
	rm -f devpkg *.o
	rm -rf *.dSYM

.PHONY: all clean
