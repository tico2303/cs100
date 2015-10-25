#ifndef Connector_hh
#define Connector_hh

// base class for the And, Or, ; , and : classes

class Connector
{

public:
	Connector();
	~Connector();
	void virtual execute(string cmd_str);

	bool is_connector(char*);

private:


};
#endif















