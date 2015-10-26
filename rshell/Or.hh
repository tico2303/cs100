#ifndef Or_hh
#define Or_hh

#include "Connector.hh"
#include <queue>

//inherets bool success from Connector

class Or: public Connector
{

public:
	Or();

	void execute(queue<char* > cmd_q); //calls c
	bool get_success();
	void set_success();

	~Or();
private:
	bool check_prev_cmd();//check if previous command pass/failed sets success var to true or false


};
#endif
