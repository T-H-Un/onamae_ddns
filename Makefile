CC = gcc
CFLAGS = -O4 -Wall -I/usr/local/include
DEST = /usr/local/bin
LDFLAGS = -L/usr/local/lib
PROGRAM = onamae_ddns

$(PROGRAM) : ddns.o
	gcc -o $(PROGRAM) ddns.o
ddns.o : ddns.cpp
	gcc -c ddns.cpp
install : $(PROGRAM)
	install -s $(PROGRAM) $(DEST)
clean : 
	rm -f *.o *~ $(PROGRAM)
