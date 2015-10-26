#ifndef Connector_hh
#define Connector_hh

#include "Command.hh"
#include <string>

// base class for the And, Or, ; , and : classes
`
class Connector : public Command
{

public:
	Connector();
	~Connector();
	void virtual execute(string cmd_str);



private:


};
#endif















