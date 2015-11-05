#include "Connector.hh"


Connector::Connector(string cmd_str) :Command(cmd_str)
{
	
}

Connector::~Connector()
{}


void Connector::execute(string cmd_str)
{
	

}

void Connector::convert(queue<string> command_queue, char* args[])
{
	int size = command_queue.size();
	int i = 0;

	while(!command_queue.empty())
	{
		cout <<"Front of queue is: " << command_queue.front() << endl;
		args[i] = (char*)command_queue.front().c_str();
		command_queue.pop();
		i++;
	}
	args[i] = NULL;
}
void Connector::get_success()
{
	return success;
}
void Connector::set_success(bool value)
{
	success = value;
}


























