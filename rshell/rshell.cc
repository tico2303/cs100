#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <queue>

using namespace std;

queue<char* > parse(string userline, char* list[]);
int arg_num(string userline);

int main()
{
	while(1)
	{
		cout <<"parent pid: " << getpid() <<endl;
		pid_t pid = fork();

		if (pid < 0)
			exit(1);
		if(pid == 0)
		{
			cout << "child id: " << getpid() <<endl;

			string userline;
			int size = arg_num(userline);
			char* args[size];

			cout << "$" ;
			getline(cin,userline);
			parse(userline,args);
			execvp(args[0],args);
			exit(0);
		}

		wait(NULL);
		cout << " ending parent" <<endl;
	}
}

queue<char*> parse(string userline, char* list[])
{
	int size = arg_num(userline);
	int i = 0;
	char *c = new char[userline.length()+1];
	char* j;
	queue<char* > cmd_q;

	strcpy(c, userline.c_str());
	cmd_q.push(strtok(c, " "));

	j = cmd_q.back();

	while(j)
	{
		i++;
		cmd_q.push(strtok(NULL, " ") );
		j = cmd_q.back();

	}

	cmd_q.push(NULL);
	return cmd_q;
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




