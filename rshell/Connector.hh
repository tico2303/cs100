#ifndef Connector_hh
#define Connector_hh

#include <string>
#include <iostream>
#include <queue>
#include "Command.hh"


using namespace std;

// base class for the And, Or, ; , and : classes

class Connector :public Command
{

	public:
		Connector( bool intial);
		~Connector();

		void virtual execute(string cmd_str);
		void convert(queue<string> command_queue, char* args[]);
		//bool is_connector(char*);

		bool get_success();
		void set_success(bool value);

	private:
		bool success;


};

#endif















