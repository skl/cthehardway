PREFIX?=/usr/local/devpkg
CFLAGS=-Wall -g -I/usr/include/apr-1.0
LDFLAGS=-L/usr/lib/apr-util-1 -lapr-1 -pthread -laprutil-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d ${DESTDIR}/${PREFIX}/bin/
	install devpkg ${DESTDIR}/${PREFIX}/bin/

clean:
	rm -f devpkg *.o
	rm -rf *.dSYM

.PHONY: all clean
