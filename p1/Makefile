CC = gcc 

SRCS = src/prime.c src/gcd.c src/sort.c
EXES = prime gcd sort


all: $(EXES)



prime: src/prime.c
	$(CC) -c src/prime.c -o prime
gcd: src/gcd.c
	$(CC) -c src/gcd.c -o gcd
sort: src/sort.c
	$(CC) -c src/sort.c -o sort	

clean: 
	rm -f $(EXES)
