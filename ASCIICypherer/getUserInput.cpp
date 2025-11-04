#include "includeAllStuff.h"
#include <iostream>

std::string getUserInput()
{
	std::string userInput{};
	std::cout << "Enter your input now: ";
	std::getline(std::cin, userInput);
	return userInput;
}

void executeUserChoice()
{
	// check what the user wants to conver to
	std::string userChoice{};
	std::cout << "Enter your choice:\n1. ascii to int\n2. int to ascii\n: ";
	std::getline(std::cin, userChoice);
	std::string userInput{getUserInput()};

	(userChoice == "1") ? std::cout << asciiToInt(userInput.c_str()) : std::cout << intToAscii(stoi(userInput));

}
