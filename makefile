all: PrimeFactorization

PrimeFactorization: main.o SeiveList.o
	g++ main.o SeiveList.o -o PrimeFactors

main.o:  main.cpp
	g++ -c main.cpp

SeiveList.o:   SeiveList.cpp
	g++ -c SeiveList.cpp

clean: 
	rm *o PrimeFactorization 
