#ifndef Semicolon_hh
#define Semicolon_hh

#include "Connector.hh"

class Semicolon : public Connector
{

public:
	Semicolon(string cmd_str);
	void virtual execute(string cmd_str);
	~Semicolon();

private:
	char *list[];


};
#endif

















