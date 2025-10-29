out: clean compile execute

# added all theother files needed
compile: main.cpp product.cpp CSVRead.cpp testCases.cpp
	g++ -g -Wall -std=c++14 main.cpp product.cpp CSVRead.cpp testCases.cpp -o mainexe 

execute: mainexe
	./mainexe

clean:
	rm -f mainexe