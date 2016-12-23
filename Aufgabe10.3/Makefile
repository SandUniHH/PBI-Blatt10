# Bocher Diedrich Sandmeier
#
# compile command: make
# test the program: make test

CC=gcc # compiler to be used

quersumme.x: quersumme.c
	$(CC) -o quersumme.x quersumme.c -Wall -Werror

test:
	./quersumme.x 453 345 43534 3533535 3252353242353 243 1313511515 3625525252525 1234434 | diff - quersumme.txt
