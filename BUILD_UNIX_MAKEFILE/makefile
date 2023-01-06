CC=gcc
CPP=g++
CFLAGS=-O3 -c -Wall

all: all2ppm all2pbm all2pam

all2ppm: all2ppm.o ppm_save.o
	$(CPP) all2ppm.o ppm_save.o -o all2ppm

all2pbm: all2pbm.o ppm_save.o
	$(CPP) all2pbm.o ppm_save.o -o all2pbm
	
all2pam: all2pam.o ppm_save.o
	$(CPP) all2pam.o ppm_save.o -o all2pam
	
ppm_save.o:
	$(CC) $(CFLAGS) ../src/ppm_save.c
	
all2ppm.o:
	$(CC) $(CFLAGS) ../src/all2ppm.c

all2pbm.o:
	$(CC) $(CFLAGS) ../src/all2pbm.c

all2pam.o:
	$(CC) $(CFLAGS) ../src/all2pam.c
	
clean:
	rm -f *.o all2ppm all2pbm all2pam
