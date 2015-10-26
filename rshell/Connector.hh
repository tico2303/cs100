#ifndef Connector_hh
#define Connector_hh

#include <string>
#include <iostream>
#include <queue>

using namespace std;

// base class for the And, Or, ; , and : classes

class Connector
{

	public:
		Connector();
		~Connector();

		void virtual execute(string cmd_str);
		void convert(queue<string> command_queue, char* args[]);
		bool is_connector(char*);

		bool get_success();
		bool set_success(bool value);

	private:
		bool success;


};

#endif















