

CC=gcc

pwd=$(shell pwd)
srcdir=$(pwd)/src
incdir=$(pwd)/include
objdir=$(pwd)/obj
bindir=$(pwd)/bin
test_srcdir=$(pwd)/test/src
test_objdir=$(pwd)/test/obj
test_bindir=$(pwd)/test/bin


obj/reader.o:
	$(shell mkdir -p $(objdir))
	$(CC) -c $(CCFLAGS) -o $(objdir)/reader.o -I $(incdir) $(srcdir)/reader.c

test/bin/reader: obj/reader.o
	$(shell mkdir -p $(test_bindir))
	$(CC) -o $(test_bindir)/reader -I $(incdir) $(test_srcdir)/reader.c $(objdir)/reader.o

clean:
	rm -fr $(objdir) $(bindir) $(test_objdir) $(test_bindir)



