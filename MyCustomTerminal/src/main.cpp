#include "../include/allthestuff.h"

int main(void)
{
	std::vector<std::string> BLACKLIST {"rm -rf /", "rm -rf *", "rm -rf ." ":(){:|:&};:", 
						"wget", "chmod -R 777 /", "echo 't'"};
		
	bool finished = false;
	while (!finished)
	{

		std::string userCommand;
		std::cout << "Enter a command to run: \n";
		std::getline(std::cin, userCommand);
		
		bool accepted = true;
		int executionResult{};

		for (int i{}; i < BLACKLIST.size(); i++)
		{
			if (userCommand == BLACKLIST.at(i))
			{
				std::cout << "Command Disallowed. Try again.\n";
				accepted = false;
				break; //dont need to loop anymore
			}
			
		}

		if (accepted)
		{				
			executionResult = system(userCommand.c_str());
		}

		if (executionResult == -1)
		{			
			std::cerr << "Execution failed for:\n'" << userCommand <<"'\n";
		}
	}


	return 0;
}
