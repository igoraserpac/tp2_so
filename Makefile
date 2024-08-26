all: main.o lru.o nru.o segunda_chance.o utils.o
	gcc lru.o nru.o segunda_chance.o utils.o main.o -o tp2virtual
	rm *.o

main.o: main.c 
	gcc -c main.c 

lru.o: lru/lru.c 
	gcc -c lru/lru.c 

nru.o: nru/nru.c 
	gcc -c nru/nru.c 

segunda_chance.o: segunda_chance/segunda_chance.c 
	gcc -c segunda_chance/segunda_chance.c 

utils.o: utils/utils.c 
	gcc -c utils/utils.c 

rm:
	rm *.o