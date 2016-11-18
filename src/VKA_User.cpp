
#include <iostream>
#include <string>

#include "NonexistentCommandException.hpp"
#include "VKAClient.hpp"

using namespace std;

void processCommand(string &, VKAClient &);
void processCreateUser(vector<string> &);
void processLogin(vector<string> &);
void processPay(vector<string> &);
void processAddFunds(vector<string> &);

void processCommand(string &command, VKAClient &app)
{
	string createUserCommand   = "create_user";
	string loginCommand        = "login";
	string payCommand          = "pay";
	string addFundsCommand     = "add_funds";

	vector<string> params;
	if (command == createUserCommand) {
		processCreateUser(params);
		app.createUser(params[0], params[1]);
	} else if (command == loginCommand) {
		processLogin(params);
		app.login(params[0], params[1]);
	} else if (command == payCommand) {
		processPay(params);
		app.pay(params[0], params[1], std::stoi(params[2]));
	} else if (command == addFundsCommand) {
		processAddFunds(params);
		app.addFunds(params[0], params[1],  std::stoi(params[2]));
	} else {
		throw NonexistentCommandException(command);
	}
}

void processCreateUser(vector<string> &params)
{
	string username;
	string password;

	cout << "What is your username?" << endl;
	cout << "> ";
	getline(std::cin, username);

	cout << "What is your password?" << endl;
	cout << "> ";
	getline(std::cin, password);

	params.push_back(username);
	params.push_back(password);
}

void processLogin(vector<string> &params)
{
	string username;
	string password;

	cout << "What is your username?" << endl;
	cout << "> ";
	getline(std::cin, username);

	cout << "What is your password?" << endl;
        cout << "> ";
        getline(std::cin, password);

	params.push_back(username);
	params.push_back(password);
}

void processPay(vector<string> &params)
{
	string myUsername;
	string otherUsername;
	string amount;

	cout << "Who are you?" << endl;
	cout << "> ";
	getline(std::cin, myUsername);

	cout << "Who are you paying?" << endl;
	cout << "> ";
	getline(std::cin, otherUsername);

	cout << "How much are you sending in cents?" << endl;
	cout << "> ";
	getline(std::cin, amount);

	params.push_back(myUsername);
	params.push_back(otherUsername);
	params.push_back(amount);
}

void processAddFunds(vector<string> &params)
{
	string username;
	string fundTag;
	string amount;
	
	cout << "Who are you?" << endl;
	cout << "> ";
	getline(std::cin, username);

	cout << "What fund source are you pulling from?" << endl;
        cout << "> ";
        getline(std::cin, fundTag);

        cout << "How much are you withdrawing in cents?" << endl;
        cout << "> ";
        getline(std::cin, amount);

	params.push_back(username);
        params.push_back(fundTag);
        params.push_back(amount);
}

int main(int argc, char **argv)
{
	VKAClient app;

	string cmd;
	while(true) {
		cout << endl;
        	cout << "Enter a command." << endl;
        	cout << "> ";
        	getline(std::cin, cmd);

        	try {
            		processCommand(cmd, app);
        	} catch (const NonexistentCommandException &e) {
           		cout << "Nonexistent command entered." << endl;
        	}
    	}
	return 0;
}
