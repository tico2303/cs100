#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string line("ls -la && ps");

	if(line.find("&&"))
	{
		string connector = "&&";
		string linecopy = line;
		char* cmd1;
		char* cmd2;
		char* p = (char*)linecopy.c_str();

		p = strtok(p, "&");
		cmd1 = p;
		
		p = strtok(NULL, "&");	
		cmd2 = p;

		/*
		while(p)
		{
			p = strtok(NULL, "&");	
			cmd2 = p;
		}
		*/
			
		
		cout << cmd1 << endl;
		cout << cmd2 << endl;

	}


	return 0;
}

