#include "SieveList.h"
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int main(){
  bool debug = false;
  int menuInput = -1;
  bool menuInputIsValid = false;
  do{
   cout << "0. Enter an integer" << endl <<
   "1. Exit the program" << endl;
   cin >> menuInput;
   if(cin.good()&&menuInput ==0 || menuInput ==1)
    menuInputIsValid = true;
  else{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Invalid input please re-enter" << endl;
  }

 }while(!menuInputIsValid);
 if(menuInput == 1)
  return 0;

  else{
    int InputNum = 0;
    bool inputNumIsValid = false;
    do{
    cout << "Enter the Number: ";
    cin >> InputNum;
    if(cin.good() && InputNum >1) //1 doesn't have a primefactorization
      inputNumIsValid = true;
    else{
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Inalid input please re-enter" << endl;
    }
  }while(!inputNumIsValid);
    vector<int> inputPrimes;
    vector<int> inputFactorization;
    PrimesToSqrtN(InputNum,inputPrimes);
    debug&&cout << "Primes:" << endl;
    if(debug)
      for(int i=0;i<inputPrimes.size();i++)
         cout << inputPrimes[i] << endl;
    PrimeFactorizer(InputNum,inputPrimes, inputFactorization);
    debug&&cout<< "PrimeFactors Vector:" << endl;
    if(debug)
      for(int i=0; i<inputFactorization.size(); i++)
         cout << inputFactorization[i] << endl;
   cout << "Prime Factorization: ";
   PrimeFactorOutput(inputFactorization);
    }
}
