

all: directCalling

directCalling: mifuncion.o directCalling.o
	gcc -o directCalling mifuncion.o directCalling.o

mifuncion.o: mifuncion.c constantes.h
	gcc -c mifuncion.c

directCalling.o: directCalling.c constantes.h
	gcc -c directCalling.c
