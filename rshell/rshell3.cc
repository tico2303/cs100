#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>

using namespace std;

void parse(string userline, char* list[]);
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
		cout << list[i] << endl;
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




