#ifndef SIEVE_H
#define SIEVE_H
#include <vector>
#include <cmath>
#include <string>
void PrimesToSqrtN(int n,std::vector< int > &Primes);
void mark(bool * sieve,int x,int size);
void PrimeFactorizer(int n, std::vector<int> &Primes,std::vector<int> &PrimeFactors);
void PrimeFactorOutput(std::vector<int>& PrimeFactorization);
#endif
