#include "SieveList.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
/*This method is used to step through the prime arrays and pull x * n
where x is a constant and n is positive integer and k*n < the size of the boolean array*/
void mark(bool * sieve, int x,int size){
   for(int i=x+x; x<size;i+=x){
      sieve[i] = false;
      if(i+x>size)
         return;
   }
}
/*This method takes n and returns via refrence a vector of primes less than or equal to sqrt(n) */
void PrimesToSqrtN(int n, vector<int> &Primes){
   bool * sieve = new bool[n+1];
   int sqrtN = ceil(sqrt(n));
   for(int i=2; i<sqrtN;i++)
      sieve[i] = true;
   for(int i =2; i<ceil(sqrt(n+1));i++)
      if(sieve[i])
         mark(sieve,i,n+1);

   sieve[1] = false;
   for(int i=0;i<n+1;i++)
      if(sieve[i])
         Primes.push_back(i);

}
/*This method takse a number n and  a vector that should a list primes up to sqrt(n) inclusively generated PrimesToSqrtN
 It returns via refrence a vector of the prime factors of n with repeted elements as needed*/
void PrimeFactorizer(int n, std::vector<int> &Primes,std::vector<int> &PrimeFactors){
   /*1 has the empty set of primes 
   this code should never get used but it provides some 
   redundancy and conceptual integrity*/
   if(n==1){ 
      return;
   }
   /*if the seive returns no primes than n is prime so its prime factorization is {n} */
   else if(Primes.size() == 0){
      PrimeFactors.push_back(n);
      return;
   }
   int i = 0;
   while(i<Primes.size()){
      if(n%Primes[i] !=0)
         i++;
      else{
         PrimeFactors.push_back(Primes[i]);
         n = n/Primes[i];
      }
      if(n==1)
         return;
   }
}
/*This method takes a list of prime factors and outputs the values 
in a terminal approriate way*/
void PrimeFactorOutput(vector<int>& PrimeFactorization){
   int i=0;
   while(i<PrimeFactorization.size()){
      int factor_count = 0; //we can assume the list is sorted order
      while(PrimeFactorization[i] == PrimeFactorization[i+factor_count])
         factor_count+=1; //factor count will never be zero
      if(factor_count>1)
         cout << PrimeFactorization[i] << "^" <<factor_count;
      else
         cout << PrimeFactorization[i];
      
      i+=factor_count;
      if(i<PrimeFactorization.size()) // if theres more factors
         cout << "*";
   } 
   cout << endl;
}
