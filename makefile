calcmake: main.c functions.c operations.c
	gcc -o rnpcalc -Wall -pedantic main.c functions.c operations.c -I.