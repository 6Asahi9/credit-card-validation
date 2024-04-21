#include <iostream>
#include <string>

//! go to test credit card account numbers website
//! follow the instructions
//* LuHn algorithm
//? 1. double every second digit from right to left . 
//! if doubled number is 2 digits froms step 1
//? 2. add all teh single digit from step 1
//? 3. add all the odd numbered digits from right to left
//? 4. sum the result from step 2 and sept 3
//? 5. if step 4 is divisible by 10, number is valid  

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardNumber);
int main(){
    std::string cardNumber;
    int result = 0;

    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    result = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);

    if(result % 10 == 0){
        std::cout << cardNumber << " is valid" << std::endl;
    }
    else{
        std::cout << cardNumber << " is not valid" << std::endl;
    }
    
    return 0;
}
int getDigit(const int number){


    //lets say we got a number 9*2 = 18 , we need to split this number 
    // 18 % 10 = 8         18/10 = 1   then...     1 % 10 = 1
    //             8 + 1 = 9 
    return number % 10 + (number /10 % 10);
}
int sumOddDigits(const std::string cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        //!  decimal equivalent of the character '0' is 48. 
        sum += cardNumber[i] - '0' ;
    }
    return sum;
}
int sumEvenDigits(const std::string cardNumber){

    int sum = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        //!  decimal equivalent of the character '0' is 48. 
        sum += getDigit((cardNumber[i] - '0' )*2);
    }
    return sum;
}
