//Command.hh

#ifndef Command_hh
#define Command_hh
#include <string>


//base class

class Command
{

public:
	Command(string userline);
	virtual void execute( string cmd_str) = 0;
	 
	~Command();

protected:
	queue<char*> cmd_q;

};
#endif
















