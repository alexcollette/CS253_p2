all:	match

lineCount: match.c
	gcc -Wall match.c -o match

clean:
	rm -f *.o match *~


