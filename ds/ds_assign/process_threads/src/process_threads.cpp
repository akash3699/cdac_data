#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main()
{

	int pid=fork();

	if(pid==0)
	{
		cout<<"Process is running"<<endl;
	}
	else
	{
		cout<<"thread is running"<<endl;
	}


	return 0;
}
