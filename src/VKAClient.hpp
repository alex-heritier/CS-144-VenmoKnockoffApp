
#ifndef VKA_CLIENT_HPP
#define VKA_CLIENT_HPP

#include <string>
#include <thread>
#include <mutex>

#include "ServerConnection.hpp"
#include "User.hpp"

using namespace vkastd;
class VKAClient {
public:
	VKAClient();
	void createUser(string &, string &);
	void login(string &, string &);
	void pay(string &, string &, int);
	void addFunds(string &, string &, int);
	void addFundSource(string &, string &, string &, string &);
private:
	// variables
	User user;
	ServerConnection serverConnection;
	std::thread readThread;
	std::string response;
	std::mutex responseMutex;
	// methods
	void captureResponses();
	template<class F>
	void waitForResponse(F);
};

#endif
