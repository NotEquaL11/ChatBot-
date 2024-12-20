#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define MAX_USER_INPUT 200
#define MAX_OPERATION 20

typedef struct {
    int atomicNumber;
    char symbol[5];
    char name[20];
    double atomicMass;
    char category[20];
} Element;


void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void logInteraction(const char *userInput, const char *botResponse) {
    FILE *logFile = fopen("chatbot_log.txt", "a");
    if (logFile == NULL) {
        fprintf(stderr, "Error logging interaction.\n");
        return;
    }
    time_t currentTime = time(NULL);
    fprintf(logFile, "[%s] User: %s | Bot: %s\n", ctime(&currentTime), userInput, botResponse);
    fclose(logFile);
}

void stringReverser() {
    char str[MAX_USER_INPUT];
    printf("Enter a string to reverse:\n");
    fgets(str, MAX_USER_INPUT, stdin);
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    printf("Here’s the reversed string: %s\n", str);
    printf("Want to reverse another string or explore something else? Type 'help' for options.\n");
}

void scientificCalculator() {
    double num1, num2;
    char operation[MAX_OPERATION];
    while (1) {
        printf("\nEnter operation (+, -, *, /, ^, sqrt, sin, cos, tan, exit): ");
        scanf("%19s", operation);
        if (strcmp(operation, "exit") == 0) {
            break;
        }
        if (strcmp(operation, "sqrt") == 0) {
            printf("\nEnter a number: ");
            while (scanf("%lf", &num1) != 1) {
                printf("\nBot: Invalid input! Please enter a valid number.\n");
                clearInputBuffer();
                printf("\nEnter a number:\n");
            }
            printf("Square root of %.2lf = %.2lf\n", num1, sqrt(num1));
        } else if (strcmp(operation, "sin") == 0 || strcmp(operation, "cos") == 0 || strcmp(operation, "tan") == 0) {
            printf("\nEnter an angle in radians: ");
            while (scanf("%lf", &num1) != 1) {
                printf("\nBot: Invalid input! Please enter a valid number.\n");
                clearInputBuffer();
                printf("\nEnter an angle in radians:\n");
            }
            if (strcmp(operation, "sin") == 0) {
                printf("Sin(%.2lf) = %.2lf\n", num1, sin(num1));
            } else if (strcmp(operation, "cos") == 0) {
                printf("Cos(%.2lf) = %.2lf\n", num1, cos(num1));
            } else {
                printf("Tan(%.2lf) = %.2lf\n", num1, tan(num1));
            }
        } else {
            printf("\nEnter two numbers:\n");
            while (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("\nBot: Invalid input! Please enter two valid numbers.\n");
                clearInputBuffer();
                printf("\nEnter two numbers:\n");
            }
            if (strcmp(operation, "+") == 0) {
                printf("Result: %.2lf\n", num1 + num2);
            } else if (strcmp(operation, "-") == 0) {
                printf("Result: %.2lf\n", num1 - num2);
            } else if (strcmp(operation, "*") == 0) {
                printf("Result: %.2lf\n", num1 * num2);
            } else if (strcmp(operation, "/") == 0) {
                if (num2 != 0) {
                    printf("Result: %.2lf\n", num1 / num2);
                } else {
                    printf("Error! Division by zero.\n");
                }
            } else if (strcmp(operation, "^") == 0) {
                printf("Result: %.2lf\n", pow(num1, num2));
            }
        }
        printf("Is there anything else you'd like to calculate? Try another operation or type 'exit' to leave the calculator.\n");
    }
}

void checkPrimeNumber() {
    int num;
    printf("Enter a number to check if it's prime:\n");
    scanf("%d", &num);
    int isPrime = 1;
    if (num <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
}

void calculateFactorial() {
    int n;
    long long factorial = 1;
    printf("Enter a number to calculate its factorial:\n");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    printf("Factorial of %d = %lld\n", n, factorial);
}

void evenOddChecker() {
    int num;
    printf("Enter a number to check if it's even or odd:\n");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("%d is an even number.\n", num);
    } else {
        printf("%d is an odd number.\n", num);
    }
}

void fibonacciSequence() {
    int terms;
    printf("Enter the number of terms in the Fibonacci sequence:\n");
    scanf("%d", &terms);
    long long t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Sequence: ");
    for (int i = 1; i <= terms; ++i) {
        printf("%lld ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

void solveQuadraticEquation() {
    double a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b, and c for the quadratic equation ax^2 + bx + c = 0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and the same.\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } else {
        printf("Roots are complex and different.\n");
    }
}

void gcdAndLcmCalculator() {
    int num1, num2, gcd, lcm;
    printf("Enter two numbers to calculate GCD and LCM:\n");
    scanf("%d %d", &num1, &num2);
    for (int i = 1; i <= num1 && i <= num2; ++i) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    lcm = (num1 * num2) / gcd;
    printf("GCD = %d\n", gcd);
    printf("LCM = %d\n", lcm);
}

void temperatureConversion() {
    double temp;
    int choice;
    printf("Enter temperature: ");
    scanf("%lf", &temp);
    printf("Convert from:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            printf("Celsius to Fahrenheit = %.2lf\n", (temp * 9/5) + 32);
            printf("Celsius to Kelvin = %.2lf\n", temp + 273.15);
            break;
        case 2:
            printf("Fahrenheit to Celsius = %.2lf\n", (temp - 32) * 5/9);
            printf("Fahrenheit to Kelvin = %.2lf\n", (temp - 32) * 5/9 + 273.15);
            break;
        case 3:
            printf("Kelvin to Celsius = %.2lf\n", temp - 273.15);
            printf("Kelvin to Fahrenheit = %.2lf\n", (temp - 273.15) * 9/5 + 32);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void towersOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towersOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;  // Row win
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;  // Column win
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;  // Diagonal win
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;  // Diagonal win
    }
    return 0;  // No winner yet
}

int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // There is still an empty spot
            }
        }
    }
    return 1;  // All spots are filled, it's a draw
}

void playTicTacToe() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int player = 1;  // Player 1 starts with 'X'
    int row, col;
    int moves = 0;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        printBoard(board);
        printf("Player %d's turn. Enter row (0, 1, 2) and column (0, 1, 2) separated by a space: ", player);
        scanf("%d %d", &row, &col);

        // Check if the position is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Mark the board
        board[row][col] = (player == 1) ? 'X' : 'O';
        moves++;

        // Check for a winner
        if (checkWinner(board)) {
            printBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;
    }
}

void periodicTableFeature() {
    Element elements[] = {
        {1, "H", "Hydrogen", 1.008, "Nonmetal"},
        {2, "He", "Helium", 4.0026, "Noble Gas"},
        {3, "Li", "Lithium", 6.94, "Alkali Metal"},
        {4, "Be", "Beryllium", 9.0122, "Alkaline Earth Metal"},
        {5, "B", "Boron", 10.81, "Metalloid"},
        {6, "C", "Carbon", 12.011, "Nonmetal"},
        {7, "N", "Nitrogen", 14.007, "Nonmetal"},
        {8, "O", "Oxygen", 15.999, "Nonmetal"},
        {9, "F", "Fluorine", 18.998, "Nonmetal"},
        {10, "Ne", "Neon", 20.180, "Noble Gas"},
    };

    int numElements = sizeof(elements) / sizeof(elements[0]);
    char input[20];
    printf("Enter an element's name, symbol, or atomic number: ");
    scanf("%s", input);

    int isNumeric = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            isNumeric = 0;
            break;
        }
    }

    int found = 0;
    for (int i = 0; i < numElements; i++) {
        if ((isNumeric && atoi(input) == elements[i].atomicNumber) ||
            (strcasecmp(input, elements[i].symbol) == 0) ||
            (strcasecmp(input, elements[i].name) == 0)) {
            printf("\nElement Details:\n");
            printf("Name: %s\n", elements[i].name);
            printf("Symbol: %s\n", elements[i].symbol);
            printf("Atomic Number: %d\n", elements[i].atomicNumber);
            printf("Atomic Mass: %.4lf\n", elements[i].atomicMass);
            printf("Category: %s\n", elements[i].category);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No element found with the given input. Please try again.\n");
    }
}

void unitConverter() {
    double value;
    int choice, unitType;

    printf("Choose type of unit conversion:\n");
    printf("1. Length (km, m, cm)\n");
    printf("2. Weight (kg, g)\n");
    printf("3. Temperature (Celsius, Fahrenheit)\n");
    scanf("%d", &unitType);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    switch(unitType) {
        case 1:
            printf("1. km to m\n2. m to cm\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("%.2lf km = %.2lf m\n", value, value * 1000);
            } else if (choice == 2) {
                printf("%.2lf m = %.2lf cm\n", value, value * 100);
            }
            break;
        case 2:
            printf("1. kg to g\n2. g to kg\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("%.2lf kg = %.2lf g\n", value, value * 1000);
            } else if (choice == 2) {
                printf("%.2lf g = %.2lf kg\n", value, value / 1000);
            }
            break;
        case 3:
            printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9/5) + 32);
            } else if (choice == 2) {
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * 5/9);
            }
            break;
    }
}

void currencyConverter() {
    double amount, convertedAmount;
    int choice;

    printf("Currency Converter:\n");
    printf("1. USD to EUR\n2. EUR to USD\n");
    scanf("%d", &choice);

    printf("Enter the amount: ");
    scanf("%lf", &amount);

    if (choice == 1) {
        convertedAmount = amount * 0.85;
        printf("%.2lf USD = %.2lf EUR\n", amount, convertedAmount);
    } else if (choice == 2) {
        convertedAmount = amount * 1.18;
        printf("%.2lf EUR = %.2lf USD\n", amount, convertedAmount);
    }
}

void asciiConverter() {
    char ch;
    int asciiValue;

    printf("Enter a character to convert to ASCII: ");
    scanf("%c", &ch);
    getchar();

    asciiValue = (int)ch;
    printf("ASCII value of '%c' is: %d\n", ch, asciiValue);

    printf("Enter an ASCII value to convert to character: ");
    scanf("%d", &asciiValue);
    printf("Character for ASCII %d is: %c\n", asciiValue, (char)asciiValue);
}

void palindromeChecker() {
    char str[MAX_USER_INPUT];
    int length, start, end, flag = 1;

    printf("Enter a string to check if it is a palindrome: ");
    fgets(str, MAX_USER_INPUT, stdin);
    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);
    start = 0;
    end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if (flag) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

void leapYearChecker() {
    int year;

    printf("Enter a year to check if it's a leap year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
}

void decimalBinaryHexaConverter() {
    int choice, num;

    printf("Choose the conversion:\n");
    printf("1. Decimal to Binary\n2. Binary to Decimal\n3. Decimal to Hexadecimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter decimal number: ");
        scanf("%d", &num);
        printf("Binary: ");
        for (int i = 31; i >= 0; i--) {
            printf("%d", (num >> i) & 1);
        }
        printf("\n");
    } else if (choice == 2) {
        printf("Enter binary number: ");
        scanf("%d", &num);
        int decimal = 0, base = 1, remainder;
        while (num > 0) {
            remainder = num % 10;
            decimal += remainder * base;
            num /= 10;
            base *= 2;
        }
        printf("Decimal: %d\n", decimal);
    } else if (choice == 3) {
        printf("Enter decimal number: ");
        scanf("%d", &num);
        printf("Hexadecimal: %X\n", num);
    }
}

void palindromeNumberChecker() {
    int num, originalNum, reversedNum = 0, remainder;

    printf("Enter a number to check if it's a palindrome: ");
    scanf("%d", &num);

    originalNum = num;

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    if (originalNum == reversedNum) {
        printf("%d is a palindrome number.\n", originalNum);
    } else {
        printf("%d is not a palindrome number.\n", originalNum);
    }
}

void guessTheNumberGame() {
    int number, guess, attempts = 0;

    srand(time(0));
    number = rand() % 100 + 1;

    printf("Guess the number between 1 and 100: ");
    do {
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again: ");
        } else if (guess < number) {
            printf("Too low! Try again: ");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);
}

void numberSystemConverter() {
    int choice, num;
    char binary[32], hex[32];
    
    printf("Number System Converter:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Hexadecimal\n");
    printf("3. Binary to Decimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            {
                int binary[32], i = 0;
                
                if (num == 0) {
                    printf("Binary: 0\n");
                    break;
                }
                
                while (num > 0) {
                    binary[i++] = num % 2;
                    num = num / 2;
                }
                
                printf("Binary: ");
                for (int j = i - 1; j >= 0; j--) {
                    printf("%d", binary[j]);
                }
                printf("\n");
            }
            break;
        
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            {
                char hex[20];
                int i = 0;
                
                if (num == 0) {
                    printf("Hexadecimal: 0\n");
                    break;
                }
                
                while (num > 0) {
                    int rem = num % 16;
                    if (rem < 10)
                        hex[i] = rem + '0';
                    else
                        hex[i] = rem - 10 + 'A';
                    i++;
                    num = num / 16;
                }
                
                printf("Hexadecimal: ");
                for (int j = i - 1; j >= 0; j--) {
                    printf("%c", hex[j]);
                }
                printf("\n");
            }
            break;
        
        case 3:
            printf("Enter a binary number: ");
            scanf("%s", binary);
            {
                int decimal = 0;
                int length = strlen(binary);
                
                for (int i = 0; i < length; i++) {
                    if (binary[i] == '1') {
                        decimal += pow(2, length - 1 - i);
                    }
                }
                
                printf("Decimal: %d\n", decimal);
            }
            break;
        
        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            {
                int decimal = 0;
                int length = strlen(hex);
                
                for (int i = 0; i < length; i++) {
                    int val;
                    if (hex[i] >= '0' && hex[i] <= '9') {
                        val = hex[i] - '0';
                    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                        val = hex[i] - 'A' + 10;
                    }
                    decimal += val * pow(16, length - 1 - i);
                }
                
                printf("Decimal: %d\n", decimal);
            }
            break;
        
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
    }
}

void displayHelp() {
    printf("\nHelp:\n");
    printf("1. String Reverser: Reverses the given string.\n");
    printf("2. Scientific Calculator: Performs basic arithmetic operations.\n");
    printf("3. Prime Number Checker: Checks if a number is prime.\n");
    printf("4. Factorial Calculator: Calculates the factorial of a number.\n");
    printf("5. Even or Odd Checker: Checks whether a number is even or odd.\n");
    printf("6. Fibonacci Sequence Generator: Generates a Fibonacci sequence up to a specified term.\n");
    printf("7. Solve Quadratic Equation: Solves a quadratic equation of the form ax^2 + bx + c = 0.\n");
    printf("8. GCD and LCM Calculator: Calculates the greatest common divisor (GCD) and least common multiple (LCM).\n");
    printf("9. Temperature Converter: Converts temperatures between Celsius and Fahrenheit.\n");
    printf("10. Towers of Hanoi Puzzle: Solves the classic Towers of Hanoi puzzle.\n");
    printf("11. Tic-Tac-Toe Game: Play a game of Tic-Tac-Toe.\n");
    printf("12. Periodic Table Feature: Displays periodic table information.\n");
    printf("13. Unit Converter: Converts between different units of measurement.\n");
    printf("14. Currency Converter: Converts between different currencies.\n");
    printf("15. ASCII Converter: Converts a character to its ASCII value and vice versa.\n");
    printf("16. Palindrome Checker: Checks if a given string is a palindrome.\n");
    printf("17. Leap Year Checker: Checks if a given year is a leap year.\n");
    printf("18. Number System Converter: Converts between binary, hexadecimal, and decimal.\n");
    printf("19. Palindrome Number Checker: Checks if a given number is a palindrome.\n");
    printf("20. Guess the Number Game: Play a number guessing game.\n");
    printf("0. Exit: Exits the chatbot.\n");
}


int main() {
    int choice;

    printf("Welcome to the Chatbot! How can I assist you today?\n");

    while (1) {
        printf("\nChatbot Menu:\n");
        printf("1. String Reverser\n");
        printf("2. Scientific Calculator\n");
        printf("3. Prime Number Checker\n");
        printf("4. Factorial Calculator\n");
        printf("5. Even or Odd Checker\n");
        printf("6. Fibonacci Sequence Generator\n");
        printf("7. Solve Quadratic Equation\n");
        printf("8. GCD and LCM Calculator\n");
        printf("9. Temperature Converter\n");
        printf("10. Towers of Hanoi Puzzle\n");
        printf("11. Tic-Tac-Toe Game\n");
        printf("12. Periodic Table Feature\n");
        printf("13. Help\n");
        printf("14. Unit Converter\n");
        printf("15. Currency Converter\n");
        printf("16. ASCII Converter\n");
        printf("17. Palindrome Checker\n");
        printf("18. Leap Year Checker\n");
        printf("19. Number System Converter (Binary/Hex/Decimal)\n");
        printf("20. Palindrome Number Checker\n");
        printf("21. Guess the Number Game\n");
        printf("0. Exit\n");

        printf("\nEnter the serial number of the operation you want to perform: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character left by scanf

        switch (choice) {
            case 0:
                printf("Exiting the chatbot. Goodbye!\n");
                return 0;
            case 1:
                stringReverser();
                break;
            case 2:
                scientificCalculator();
                break;
            case 3:
                checkPrimeNumber();
                break;
            case 4:
                calculateFactorial();
                break;
            case 5:
                evenOddChecker();
                break;
            case 6:
                fibonacciSequence();
                break;
            case 7:
                solveQuadraticEquation();
                break;
            case 8:
                gcdAndLcmCalculator();
                break;
            case 9:
                temperatureConversion();
                break;
            case 10:
                {
                    int disks;
                    printf("Enter the number of disks for the Towers of Hanoi puzzle: ");
                    scanf("%d", &disks);
                    getchar();
                    towersOfHanoi(disks, 'A', 'B', 'C');
                }
                break;
            case 11:
                playTicTacToe();
                break;
            case 12:
                periodicTableFeature();
                break;
            case 13:
                displayHelp();
                break;
            case 14:
                unitConverter();
                break;
            case 15:
                currencyConverter();
                break;
            case 16:
                asciiConverter();
                break;
            case 17:
                palindromeChecker();
                break;
            case 18:
                leapYearChecker();
                break;
            case 19:
                numberSystemConverter();
                break;
            case 20:
                palindromeNumberChecker();
                break;
            case 21:
                guessTheNumberGame();
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 21.\n");
                break;
        }
    }

    return 0;
}
