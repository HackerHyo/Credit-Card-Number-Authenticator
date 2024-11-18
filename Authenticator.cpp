/*
Luhn Algorithm is a way to test the validity of a credit card number. 
1. Double every second number from right to left
2. Sum up all individual digits from Step 1
3. Add all odd numbered digits from right to left
4. Sum up Steps 2 and 3 results
5. If Step 4 result is divisible evenly by 10, it is valid

This program uses Luhn's Algorithm to test the validity of inputted credit card numbers. It will also check if the input contains letters and also if it contains exactly 16 characters.
*/
#include <iostream>

using namespace std;

void formatNumber(string &cardNumber){
    string newNumber = cardNumber;
    cardNumber = "";
    int count = 0;
    for(int i = 0; i <= newNumber.size() - 1; i++){
        if(count == 3){
            cardNumber += newNumber[i];
            cardNumber += ' ';
            count = 0;
        }
        else{
            cardNumber += newNumber[i];
            count += 1;
        }
    }
}

bool checkLetters(string cardNumber){
    int check = 0;
    for(int i = 0; i < cardNumber.size(); i++){
        check = cardNumber[i] - '0';
        if (check < 0 || check > 9){
            return false;
            break;
        }
    }
    return true;
}

int getDigit(const int number){
    //if number is 2 digits, it will take each digit to make a sum. if number is 1 digit, it will return the same value
    return number % 10 + (number / 10 % 10);
}

int sumOdd(const string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}

int sumEven(const string cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        /*
        converts each of the characters picked out to int by converting the char to its decimal value by subtracting it with another char '0'
        this subtraction converts the result into the difference between the two's decimal value, leaving it with a range of 0-9 values
        for example, if the char '0' is subtracted from '3', the decimal value of '3' is 51 and of '0' is 48. So the result is 3 in decimal form. '0' is interchangeable with 48 as well.
        */
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}

int main() {
    string cardNumber;
    int result = 0;

    cout << "Enter in your card number here: ";
    getline(cin, cardNumber);

    if(cardNumber.size() != 16){
        cout << "It seems like your number is longer than 16 digits, and therefore doesn't qualify as a credit card number.";
    }
    else if (!checkLetters(cardNumber)){
        cout << "It seems like your number contains letters and/or special characters, so it's not really a number.";
    }
    else{
        result = sumEven(cardNumber) + sumOdd(cardNumber);
        formatNumber(cardNumber);
        if(result % 10 == 0){
            cout << cardNumber << " is valid!";
        }
        else
        {
            cout << cardNumber << " is not valid!";
        }
        return 0;
    }
}