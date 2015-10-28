#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

void parse(string userline, char* list[]);
int arg_num(string userline);
queue<string> semiparse(string userline);
int smallest(int a,int b,int c);
void printq(queue<string> q);
queue<string> parse_userline(string line);
bool logic(queue<string>& q, bool previous);

int main()
{
	string userline;
	string command;
	queue<string> q;

	while(1)
	{
		bool previous = true;
		cout << "$" ;

		//q = semiparse(userline);
		getline(cin, userline);
		q = parse_userline(userline);

		if(q.front() == "quit")
			exit(0);
		while(!q.empty())
		{
			if(logic(q,previous))
			{
			//	cout << "queue after is: " << endl;
			//	printq(q);
				command = q.front();
				q.pop();
			//	cout << "The current command running is: " << command << endl;
			//	cout << endl;

				pid_t pid = fork();

				if (pid < 0)
					exit(1);
				else if(pid == 0)
				{
					//cout << "Child Process: ";
					//cout << getpid() << endl;
					int size = arg_num(userline);
					char* args[size];
					
					//parses on space
					parse(command,args);
					if(execvp(args[0],args) == -1)
					{
						cerr << "Invalid Command." << endl;
						exit(-7);
					}
				}
				else
				{
					int wait_return = 0;
					int status = 0;
					int childret = 0;
					cout << endl;
					//cout << "I am the Parent Process waiting for child to end. Parent pid: " << getpid() << endl;

					//Use to see if previous command success or fail. Returns a certain number if it fails.
					wait_return = wait(&status);
				//	cout << "The wait function returned: " << wait_return << endl;
					childret = WEXITSTATUS(status);
			//		cout << "The child function returned: " << childret << endl;

					if(childret != 0)
						previous = false;

				//	cout << "Ending Parent Process:" << getpid() << endl;
				//	cout << endl;
				}
			}
			else
				q.pop();
		}
	}
}

queue<string> parse_userline(string line)
{
	queue<string> q;
	string s;

	int x = 0;
	while(line.length() > 0)
	{
	//	cout << "Line is currently : " << endl;
	//	cout << line << endl;
		int semi = 0;
		int orr = 0;
		int andd = 0;
		int pos = 0;

		semi = line.find_first_of(";",0);
		orr = line.find_first_of("||",0);
		andd = line.find_first_of("&&",0);

		/*
		
		cout << "---------------------" << x << " SEARCH RESULTS -------------------- " << endl;
		x++;
		cout << endl;

		cout << "semi: " << semi << endl;
		cout << "orr:" << orr << endl;
		cout << "andd: " << andd << endl;

		cout << endl;
		cout << endl;
		

		*/
		pos = smallest(semi,orr,andd);

		
		/*
		cout << "pos: " << pos << endl;

		cout << endl;
		cout << endl;
		
		*/

		if(pos == -1)
		{
			//cout << "No Connector found. " << endl;
			q.push(line);
			line = "";
		}
		else if(pos == semi)
		{
			//cout << "Found semi at " << pos << endl;
			s = strtok((char*)line.c_str(), ";");
			q.push(s);
			q.push(";");
			line.erase(0, pos+1);
		}
		else if(pos == orr)
		{
			//cout << "Found or at " << pos << endl;
			s = strtok((char*)line.c_str(), "||");
			q.push(s);
			q.push("||");
			line.erase(0, pos+2);
		}
		else	
		{
			//cout << "Found and at " << pos << endl;
			s = strtok((char*)line.c_str(), "&&");
			q.push(s);
			q.push("&&");
			line.erase(0, pos+2);
		}
	}

//	printq(q);

	return q;
}

bool logic(queue<string>& q, bool previous)
{
	string command;
	command = q.front();
	//cout << "Inside logic command is: " << command << endl;
	//cout << "Inside logic previous is: " << previous << endl;
	//cout << "queue before is: " << endl;
	printq(q);

	if(command == "&&")
	{
		q.pop();
		if(previous == true)
			return true; 
		else
			return false;
	}

	else if(command == "||")
	{
		q.pop();
		if(previous == true) 
		 	return false;
		else
		 	return true;
	}
	else if(command == ";")
	{
		q.pop();
		return true;
	}
	else
		return true;
}

int smallest(int a,int b,int c)
{
	list<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.remove(-1);

	//cout << "List is: " << endl;
	//for(list<int>::iterator i = v.begin(); i != v.end(); i++)
	//		cout << *i;
	
	if(v.empty())
		return -1;
	else
		v.sort();

	return v.front();
}

void parse(string userline, char* list[])
{

	int size = arg_num(userline);
	int i = 0;
	char *c = new char[userline.length()+1];
	char* j;

	strcpy(c, userline.c_str());
	list[i] = strtok(c, " ");
	j = list[i];
	
	while(j)
	{
		i++;
		list[i] = strtok(NULL, " ");
		j = list[i];
	}

	list[i+1] = NULL;
}

int arg_num(string userline)
{
	char *c = new char[userline.length()+1];
	char *j;

	strcpy(c, userline.c_str());
	j = strtok(c, " ");

	int i = 0;
	while(j)
	{
		j = strtok(NULL, " ");
		i++;
	}

	return i;
}

queue<string> semiparse(string userline)
{
	queue<string> sl;
	char* commands;
	char* cp;
	
	getline(cin, userline);
	cp = strtok((char*)userline.c_str(), ";");
	
	while(cp)
	{
		sl.push(cp);
		cp = strtok(NULL, ";");
	}

	return sl;
}

void printq(queue<string> q)
{
	string x;
	queue<string> temp = q;

	cout << "Printing Queue: " << endl;
	while(!temp.empty())
	{
		x = temp.front();
		cout << x << endl;
		temp.pop();
	}
}


