#include <iostream>
#include <string>
#include <vector>

// Returns one line of user input after printing a prompt
std::string input(std::string prompt) { 
    std::cout << prompt;
    std::string response;
    std::getline(std::cin, response);
    if (response.empty()) {
        std::cout << "Input is empty. Exiting program." << std::endl;
        exit(0); 
    }
    return response;
}

// Converts single roman numeral to decimal value, returns 0 if it is not valid.
int convert_roman_number(char roman) { 
    switch(roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; 
    }
}


// Converts roman numeral to decimal value
int to_decimal(std::string &roman) {
    int final = 0;
    int previous = 0;
    int check = 0;
    for (int i = roman.size() - 1; i >= 0; i--) { //iterate through string in reverse
        int number = convert_roman_number(roman[i]);

        // Gives error if the roman numeral value is not valid.
        if (number == 0) { 
            std::cerr << "The roman numeral string " << roman << " is invalid." << std::endl;
            exit(1);            
        } 
        
        // Checks the value two to the right of the current number. This is used to invalidate expressions such as "IIX" or "CCD"
        if (number < check) { 
            std::cerr << "The roman numeral string " << roman << " is invalid." << std::endl;
            exit(2);
        }
        
        // For cases such as IX or CD
        if (number < previous) { 
            
            // For the roman numerals up to 4000, this conditional should make sure that the preceding value is valid.
            if (number * 10 < previous || previous - number == number || (previous - number) % 100 == number) { 
                std::cerr << "The roman numeral string " << roman << " is invalid." << std::endl;
                exit(3);
            }
            
            final -= number; 
            check = previous; 
        } else {
            final += number; // Base case
        }
       
        previous = number;
    }
    return final;
}   

// Converts Integer value between 0 < x < 4000
std::string to_roman(int number) { 
    
    // Validating the integer:
    if (number > 3999) {
        std::cerr << number << " is too large" << std::endl;
        exit(4);
    }
    if (number <= 0) {
        std::cerr << "Input cannot be zero or negative" << std::endl;
        exit(5);
    }

    // Makes two vectors which act like a map corresponding Roman Numerals with their decimal value
    std::vector<int> int_values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> roman_values = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    std::string roman = "";
    
    /* Loops through int_values and if 'number' is greater than the value of int_values[i],
    it subtracts that value int_values[i] from number, and concatenates the string 'roman'
    with the corresponding roman numeral. */
    for (int i = 0; i < int_values.size(); ++i) {
        while (number >= int_values[i]) {
            roman += roman_values[i];
            number -= int_values[i];
        }
    }

    return roman;
}

// Runs the program until an empty or invalid input is given.
int main() {
    while (true) {
        std::string user_value = input("Type in a number under 4000 or a string of roman numerals: ");
        if (isdigit(user_value[0])) {
            std::cout << to_roman(stoi(user_value)) << std::endl;
        } else {
            std::cout << to_decimal(user_value) << std::endl;
        }
    }
}