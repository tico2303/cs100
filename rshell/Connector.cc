#include "Connector.hh"


Connector::Connector()
{
	success = false;
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



























