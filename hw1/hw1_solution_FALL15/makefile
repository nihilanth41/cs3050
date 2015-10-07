mode: driver.c mode.o mergeSort.o parser.o statistics.h
	gcc -Dexecute_mode -Wall -O3 driver.c mode.o mergeSort.o parser.o -o hw1_solution

parser.o: parser.c
	gcc -c parser.c

mode.o: mode.c
	gcc -c mode.c

mergeSort.o: mergeSort.c
	gcc -c mergeSort.c

clean:
	rm -rf *.o hw1_solution
