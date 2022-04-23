CC=gcc
CFLAGS=-O3 -c -Wall

all: all2ppm all2pbm

all2ppm: all2ppm.o ppm_save.o
	$(CC) all2ppm.o ppm_save.o -o all2ppm

all2pbm: all2pbm.o ppm_save.o
	$(CC) all2pbm.o ppm_save.o -o all2pbm
	
ppm_save.o:
	$(CC) $(CFLAGS) ../src/ppm_save.o
	
all2ppm.o:
	$(CC) $(CFLAGS) ../src/all2ppm.o

all2pbm.o:
	$(CC) $(CFLAGS) ../src/all2pbm.o
	
clean:
	rm -f *.o all2ppm all2pbm
