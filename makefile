main: aoc2022.cpp
	g++ -std=c++20 -O3 -Wall -Werror=pedantic aoc2022.cpp -o aoc2022.o

run:
	./aoc2022.o

clean:
	rm *.o