/*
   This code does following :
   1. Fork child process
   2. Drops privilege of child process to normal user, if it was running under root privilege
   3. Sets alarm for child process and terminates it if it exceeds given allowed time limit
   4. Limits data and stack resources (memory) to given Bytes
   5. Makes parent process wait for child process to finish/exit
   6. Compiles the c++ file provided in command line. Publish compilation failures if any
   7. Executes the program if compilation is successful.
   8. Report the results.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <sys/wait.h>   /* Wait for Process Termination */
#include <stdlib.h>     /* General Utilities */
#include <stdlib.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/stat.h>

#define UNPRIV_UID  2
#define UNPRIV_GID  2
using namespace std;

static pid_t parent_id, child_id;
void alarm_handler(int){exit(EXIT_FAILURE);}
class CodeChecker{
	public:
		CodeChecker(string filename):
			m_filename(filename),
			m_memory_limit(100000),
			m_execution_time(5){
			}
		bool checkcode();
	private:
		string get_filename() const{return m_filename;}
		int get_memory_limit() const {return m_memory_limit;}
		int get_execution_time() const {return m_execution_time;}

		string m_filename;
		const int m_memory_limit;//in KB
		const int m_execution_time;// in Seconds
};
bool CodeChecker::checkcode()
{
	cout<<"checking code for file "<<get_filename()<<endl;
	ifstream f(get_filename().c_str());
	if(!f.good())
	{
		f.close();
		cout<<"File doesn't exist in path"<<endl;
		return false;
	}
	else
	{
		f.close();
	}
	int result = 0;
	child_id = fork();
	if(child_id == 0)
	{
		//its child process
		//run our program here
		// install an alarm handler for SIGALRM
		if (getuid() == 0) { // we are root
			// setting UID/GID requires root privileges, so if you don't set
			// the GID first, you won't be able to do it at all.
			cout<<"Changing Privilege of child process"<<endl;
			if (setgid(UNPRIV_GID)!=0)
			{
				cout<<"Failed to set nonroot GID"<<endl;
				exit(EXIT_FAILURE); 
			}
			if (setuid(UNPRIV_UID)!=0)
			{
				cout<<"Failed to set nonroot UID"<<endl;
				exit(EXIT_FAILURE); 
			}
		}

		if(getuid() == 0)
		{
			cout<<"could not change privilege"<<endl;
			exit(EXIT_FAILURE); 
		}
		else
		{
			cout<<"changed the child process' privilege"<<endl;
		} 

		signal(SIGALRM, alarm_handler);

		// install an alarm to be fired after TIME_LIMIT
		alarm(get_execution_time());
		struct rlimit limits;
		limits.rlim_cur = get_memory_limit(); // set data segment limit in B
		limits.rlim_max = get_memory_limit(); // make sure the child can't increase it again
		result = setrlimit(RLIMIT_DATA, &limits);
		result = setrlimit(RLIMIT_STACK, &limits);
		if(result != 0){exit(EXIT_FAILURE);}

		cout<<"-- Inside Child Process --"<<endl;
		system("rm binary");
		result = system(string("g++ " + get_filename() + " -o binary 2>&1").c_str());
		if(result == 0)
		{
			result = system(string("./binary 2>&1").c_str());
		}
		alarm(0);
		if(result != 0)
		{
			cout<<"child exiting with failures"<<endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			cout<<"child exiting with success"<<endl;
			exit(EXIT_SUCCESS);
		}
	}
	else if(child_id < 0)
	{
		cout<<"-- Internal Error --"<<endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		//parent
		cout<<"-- Inside Parent Process --"<<endl;
		if(getuid() == 0)
		{
			cout<<"Parent running with root privilege"<<endl;
		}
		else 
		{
			cout<<"Parent NOT running with root privilege"<<endl;
		}
		int status = 0;
		if ((child_id = waitpid(-1, &status, 0)) == -1)
		{
			//wait for child
			cout<<"wait error"<<endl;
		}
		else {                       /* Check status.                */
			if (WIFSIGNALED(status) != 0)
			{
				cout<<"Child process ended because of signal"<<WTERMSIG(status)<<endl;
			}
			else if (status == 0)
			{
				cout<<"Child process ended ; status = "<<WEXITSTATUS(status)<<endl;
				result = true;
			}
			else
			{
				result = false;
				cout<<"Child process did not end normally"<<endl;
			}

		}
		cout<<"Parent process ended"<<endl;
	}
	return result;
}

int main(int argc, char* argv[])
{
	// Check the number of parameters
	if (argc < 2) {
		// Tell the user how to run the program
		std::cerr << "Usage: " << argv[0] << " filename.cpp" << std::endl;
		return 1;
	}
	string filename = argv[1];
	cout<<"----- Starting Program ----- "<<endl;
	CodeChecker codechecker(filename);
	if(codechecker.checkcode())
	{
		cout<<"-- Congratulations!! Your programmed passed all the criteria -- "<<endl;
	}
	else
	{
		cout<<"-- Your Program Failed to meet All the Criteria -- "<<endl;
	}
	return 0;
}
