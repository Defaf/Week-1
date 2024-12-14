#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Greeting Function
void greeting(const std::string& name, int age) {
    std::cout << "Hello " << name << ", Your age is " << age << " years old.\n";
}

// Add Numbers
int addNumbers(int num1, int num2) {
    int sum = num1 + num2;
    std::cout << "Your calculation is: " << sum << "\n";
    return sum;
}

// User Information
void askInfo() {
    std::string name;
    int age;

    std::cout << "Kindly, enter your full name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::getline(std::cin, name);

    std::cout << "Now, enter your age: ";
    while (!(std::cin >> age)) {
        std::cout << "Invalid input. Please enter a valid age: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    greeting(name, age);
}

// Temperature Conversion
float convertToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

void askTemperature() {
    float tCelsius;
    std::cout << "Enter Temperature in Celsius so I can convert it to Fahrenheit: ";
    while (!(std::cin >> tCelsius)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Today's Temperature in Fahrenheit is: "
        << convertToFahrenheit(tCelsius) << " F\n";
}

// Distance Conversion
float convertToMiles(float kilometers) {
    return kilometers * 0.621371;
}

void askDistance() {
    float kilometers;
    std::cout << "Enter Distance in Kilometers so I can convert it to Miles: ";
    while (!(std::cin >> kilometers)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Your Distance in Miles is: " << convertToMiles(kilometers) << " Miles\n";
}

// Weight Conversion
float convertToKilograms(float pounds) {
    return pounds * 0.453592;
}

void askWeight() {
    float pounds;
    std::cout << "Enter your weight in Pounds so I can convert it to Kilograms: ";
    while (!(std::cin >> pounds)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Your Weight in Kilograms is: " << convertToKilograms(pounds) << " Kg\n";
}

// Currency Conversion
float convertToEuros(float dollars) {
    return dollars * 0.85;
}

void askCurrency() {
    float dollars;
    std::cout << "Enter your currency in $ so I can convert it to €: ";
    while (!(std::cin >> dollars)) {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Your Currency in Euros is: " << convertToEuros(dollars) << " €\n";
}

// Compute Average of Four Float Numbers
void computeAverage() {
    std::vector<float> numbers(4); // Vector to store 4 numbers
    float sum = 0.0f, average;

    std::cout << "Please enter 4 float numbers:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter a valid float number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        sum += numbers[i]; // Add each number to the sum
    }

    average = sum / 4; // Compute the average
    std::cout << "The average of the entered numbers is: " << average << "\n";
}

// Main Menu
void showMenu() {
    std::cout << "\nChoose an option:\n"
        << "1. Enter Information\n"
        << "2. Convert Temperature\n"
        << "3. Convert Distance\n"
        << "4. Convert Weight\n"
        << "5. Convert Currency\n"
        << "6. Compute Average of Four Numbers\n"
        << "0. Exit\n"
        << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        showMenu();
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 0 and 6: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            askInfo();
            break;
        case 2:
            askTemperature();
            break;
        case 3:
            askDistance();
            break;
        case 4:
            askWeight();
            break;
        case 5:
            askCurrency();
            break;
        case 6:
            computeAverage();
            break;
        case 0:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please select a number between 0 and 6.\n";
        }
    } while (choice != 0);

    return 0;
}
