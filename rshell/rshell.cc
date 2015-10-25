#include <iostream>
#include <cstring>    // char *strtok(char *str, const char *delimeter )
#include <string>

#include <sys/types.h> // pid_t waitpid( pid_t pid, int *status, int options)
#include <unistd.h>    // int execvp(const char *file, char *const argv[] );
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> //pid_t wait( int* status )


//-------------------------------------------------------------------------------------------------------
// int execvp(const char *file, char *const argv[] );
//
// execvp() first argument should be the filename associated with the file being executed
//          second argument is an array of pointers that are aguments passed to the program being executed
// only returns a -1 if theres an error
// 
// there are different exec's
// with L: comma separted arguments
// with V: Vector (ex. an array of strings)
// with P: Include normal search path for executable (autmatically searches for appropriate locations ex. usr/bin)
//----------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------
// pid_t fork(void)
//
// fork() creates a child process (duplicate) of the current process
// fork() returns -1 for error
//                0 for child 
//   greater than 0 for parent 
//--------------------------------------------------------------------

// int waitpid(

using namespace std;


//gets commands from the user and places them into a list

void extract_cmd(string first, char *list[])
{
	
    //convert from string to char* so that strtok() can take it
    // in as a parameter
    char *c = new char[first.length() +1];
    strcpy(c, first.c_str() );

    //call strtok() to parse the string
    // strtok(char*, delimter)


    // the first arg will be the executable
    char *exec;
    exec = strtok(c, " ;");
  	cout <<"exec: " << exec <<endl;

    // the second arg will be the argument list
    char *arg_list;
    arg_list = strtok(NULL," ;");

    if(arg_list[0] == '-')
    {
   		cout << "tack option" << endl;
    }

	cout << "arg_list: " << arg_list <<endl;

    // the third arg will be the connection command
    //char *con_cmd;
    //con_cmd = strtok(NULL, " || &&");
    //cout << "con_cmd: " << con_cmd <<endl;
 

    // packing the commands so that they can be passed to execvp() 
    // arguments need to be in a NULL terminated char*
    list[0] = exec;
    list[1] = arg_list; 
    //list[2] = con_cmd;
    list[2] = NULL;


}

void execute(char *list[])
{
	cout << "execute(): pid=" << getpid() << endl;

    pid_t pid = fork();

	int status;

    if(pid <0)
    {
		perror("fork failed"); 
		exit(0);
    }
    else if(pid == 0)
    {
    	
		cout << "execute(): execvp(" << list[0] << ") " <<endl;
    	execvp(list[0], list);
    	
    }
    	cout << "execute(): parent wait() " <<endl;
		//waits for parent process to finish
    	wait(NULL);
    	cout << "exiting parent" <<endl;
}


int main()
{
    //print process id
    cout << "getpid():";
    cout << getpid() <<endl;

//through this in a while(1) loop with an exit condition
	

	while(1)
	{
    string cmd; 
    char *li[100];
    	//prompt
    	cout <<"$ ";
    	
    	//get user input
    	
    	getline(cin, cmd);
    	cout<<endl;
    	
    	//get commands for user string stores it in char* li
    	cout << "main: extract_cmd() " <<endl;
    	extract_cmd(cmd,li);
		
		// check if exiting
    	if( strcmp(li[0], "exit") ==0 )
    	{
    		cout <<" exiting" <<endl;
    		exit(0);
    	}

		//creates fork and executes command
		cout << "main: execute() " << endl;
    	execute(li);

    	cout << "back from fork in main exiting" <<endl;
	}
	
    return 0;

}
