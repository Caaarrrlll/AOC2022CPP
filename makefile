main: aoc2022.cpp
	g++ -std=c++11 -Wall -Werror=pedantic aoc2022.cpp -o aoc2022.o

run:
	./aoc2022.o

clean:
	rm *.o