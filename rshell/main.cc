#include <iostream>
//#include "Command.hh"
#include <queue>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <string.h>
#include <vector>



using namespace std;

queue<string > parse(string userline);
void check_delimt(queue<string> );
void empty_que(queue<string> );

int main()
{
	string userline;
	queue<string> usrln_q;
	queue<string> test;
	queue<string > cmd_q;	
	queue<Command*> execut_q;

	getline(cin, userline);
	usrln_q = parse( userline);	
	test = usrln_q;
	string temp;

	while( !usrln_q.empty() )
	{
		temp = usrln_q.front();
		cmd_q.push(temp);

		if(temp == "&&" )
		{
			Command* And = new And(cmd_q);
			execut_q.push(And);
			empty_que(cmd_q);
		}
		else if(temp = "||")
		{
			Command* Or = new Or(cmd_q);
			execut_q.push(Or);
			empty_que(cmd_q);

		}
		else if(temp == ";")
		{
			Command* Sem  = new SemiColon(cmd_q);
			execut_q.push(Sem);		
			empty_que(cmd_q);
		}
	
		
	}

	cout << endl;
	cout << endl;
	cout << "the queue is: " <<endl;

	while(! test.empty())
	{
		
		cout << test.front() << endl;
		test.pop();

	}


	return 0;
}

queue<string > parse(string userline)
{
	queue<string> cmd_q;
		
	char* j = strktok( (char*).userline.c_str(), " ");
	
	cmd_q.push(j);

	while(j)
	{
		cmd_q.push(strtok(NULL, " ") );
		j = cmd_q.back();
	}

	cmd_q.push(NULL);
	return cmd_q;
}
void empty_que(queue<string> q)
{
	while(!q.empty())
	{
		q.pop();	
	}

}






