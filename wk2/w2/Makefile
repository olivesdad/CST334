CC = g++

CFLAGS = -D DEBUG

all: sizeof def const decl args

sizeof : sizeof.c
	gcc $(CFLAGS) -o sizeof sizeof.c

const : const.c
	gcc $(CFLAGS) -o const const.c

def : def.c
	gcc $(CFLAGS) -o def def.c

decl : decl.c
	gcc $(CFLAGS) -o decl decl.c

args : args.c
	gcc -o args args.c

clean :
	rm -f sizeof while def const decl args
