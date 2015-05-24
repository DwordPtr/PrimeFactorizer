#include "SieveList.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void mark(bool * sieve, int x,int size){
   for(int i=x+x; x<size;i+=x){
      sieve[i] = false;
      if(i+x>size)
         return;
   }
}
void PrimesToN(int n, vector<int> &Primes){
   bool * sieve = new bool[n+1];
   for(int i=2; i<n+1;i++)
      sieve[i] = true;
   for(int i =2; i<ceil(sqrt(n+1));i++)
      if(sieve[i])
         mark(sieve,i,n+1);

   sieve[1] = false;
   for(int i=0;i<n+1;i++)
      if(sieve[i])
         Primes.push_back(i);

}
void PrimeFactorizer(int n, std::vector<int> &Primes,std::vector<int> &PrimeFactors){
   for(int i =0 ; i<Primes.size();i++)
      if(n==Primes[i]){
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
