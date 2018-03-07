all: example

example: example.c
		$(CC) -o example example.c -Wall -std=gnu99

test:
	python test.py

clean:
		rm -f example example_.* 
