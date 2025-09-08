#include <iostream>
#include <cstdlib> // for system()

int main(void)
{
	std::string userCommand;
	
	std::cout << "Enter a command to run: \n";
	std::getline(std::cin, userCommand);

	int executionResult = system(userCommand.c_str());
	if (executionResult == -1)
	{
		std::cerr << "Execution failed for:\n'" << userCommand << "'\n\n";
	}

	return 0;
}
