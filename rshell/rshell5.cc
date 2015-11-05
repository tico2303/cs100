#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <queue>

using namespace std;

void parse(string userline, char* list[]);
int arg_num(string userline);
queue<string> semiparse(string userline);
int smallest(int a,int b,int c);
void printq(queue<string> q);
queue<string> parse_userline(string line);

int main()
{
	string userline;
	string command;
	queue<string> q;
	bool success = true;

	while(1)
	{
		cout << "$" ;
		getline(cin, userline);

		pid_t pid = fork();
		if (pid < 0)
			exit(1);
		else if(pid == 0)
		{
			q = parse_userline(userline);

			if(q.front() == "quit")
				exit(0);
			while(!q.empty())
			{
				//cout << "Starting Queue WHile. " << endl;
				cout << endl;
				command = q.front();
				q.pop();
				if(command == "&&")
					command = q.front();
				else if(command == "||")
				{
					command = q.front();
					if(success)
						break;
				}
				else if(command == ";")
					command = q.front();
				//cout << "Above Fork process PID: " << getpid() << endl;
				//cout << getpid() << endl;

				int size = arg_num(userline);
				char* args[size];
				
				//parses on space
				parse(command,args);
				if(execvp(args[0],args) == -1)
				{
					cerr << "Invalid Command." << endl;
					success = false;
				}
			}
		}
		else
		{
			//cout << "I am the Parent Process waiting for child to end. Parent pid: " << getpid() << endl;
			sleep(2);
			wait(NULL);
			cout << "Ending Parent Process:" << getpid() << endl;
			cout << endl;
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
		//cout << "Line is currently : " << endl;
		//cout << line << endl;
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
			cout << s << endl;
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

	//printq(q);

	return q;
}

int smallest(int a,int b,int c)
{
	if((a == 0) and (b == 0) and (c == 0))
		return -1;
	else if((a < b) and (a < c) and (a > 0))
		return a;
	else if((b < a) and (b < c) and (b > 0))
		return b;
	else if(c > 0)
		return c;
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




