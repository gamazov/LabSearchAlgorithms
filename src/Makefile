all:
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D LINEAR
	./a.out ../test/100.txt express
	./a.out ../test/500.txt express
	./a.out ../test/1000.txt express
	./a.out ../test/5000.txt express
	./a.out ../test/10000.txt express
	./a.out ../test/50000.txt express
	./a.out ../test/100000.txt express
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D BINARYSORTED
	./a.out ../test/100.txt express
	./a.out ../test/500.txt express
	./a.out ../test/1000.txt express
	./a.out ../test/5000.txt express
	./a.out ../test/10000.txt express
	./a.out ../test/50000.txt express
	./a.out ../test/100000.txt express
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D BINARYANDSORT
	./a.out ../test/100.txt express
	./a.out ../test/500.txt express
	./a.out ../test/1000.txt express
	./a.out ../test/5000.txt express
	./a.out ../test/10000.txt express
	./a.out ../test/50000.txt express
	./a.out ../test/100000.txt express
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D MULTIMAP
	./a.out ../test/100.txt express
	./a.out ../test/500.txt express
	./a.out ../test/1000.txt express
	./a.out ../test/5000.txt express
	./a.out ../test/10000.txt express
	./a.out ../test/50000.txt express
	./a.out ../test/100000.txt express
linear:
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D LINEAR
binarysorted:
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D BINARYSORTED
binaryandsort:
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D BINARYANDSORT
multimap:
	g++ -std=c++11 -Wall -Werror -Wextra main.cpp -D MULTIMAP
clean:
	rm -f a.out output.txt