PREFIX?=/usr/local/devpkg
CFLAGS=-Wall -g -I/usr/local/opt/apr/include/apr-1 -I/usr/local/opt/apr-util/include/apr-1
LDFLAGS=-L/usr/local/opt/apr/lib -L/usr/local/opt/apr-util/lib -lapr-1 -pthread -laprutil-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d ${DESTDIR}/${PREFIX}/bin/
	install devpkg ${DESTDIR}/${PREFIX}/bin/

clean:
	rm -f devpkg *.o
	rm -rf *.dSYM

.PHONY: all clean
