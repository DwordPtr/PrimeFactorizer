all: PrimeFactorization

PrimeFactorization: main.o SieveList.o
	g++ main.o SieveList.o -o PrimeFactors

main.o:  main.cpp
	g++ -c main.cpp

SieveList.o:   SieveList.cpp
	g++ -c SieveList.cpp

clean: 
	rm *o PrimeFactors
