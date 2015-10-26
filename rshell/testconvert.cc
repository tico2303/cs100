#include <iostream>
#include <string>
#include <queue>
#include "Connector.hh"

using namespace std;

int main()
{
	queue<string> x;

	string y = "ls";
	string z = "-la";

	char* args[2];

	x.push(y);
	x.push(z);

	Connector c;
	c.convert(x,args);

	cout << args[0] << endl;
	cout << args[1] << endl;

	return 0;
}
