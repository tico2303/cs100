//Command.hh

#ifndef Command_hh
#define Command_hh
#include <string>


//base class

class Command
{

public:
	Command(string cmd_str);
	virtual void execute( string cmd_str) = 0;
	~Command();


protected:
	string usrln;
	queue<string> cmd_q;



};
#endif
















