#include <iostream>
#include <stdio.h>


using namespace std;

int main()
{   
        cout << "welcome" <<endl;
        string command = "ls -ltr";
		FILE* pipe = popen(command.c_str(), "r");
		string result = "hello";
		if (!pipe) 
		{
			cout << "Error while executing system command : "<< endl ;
		}
		else
		{
			char buffer[16];
			result="";
			while(!feof(pipe)) 
			{
			    //cout << "pointed is" << *pipe << endl;
				if(fgets(buffer, 16, pipe) != NULL)
					result += buffer;
				cout << "buffer  is " << buffer << endl ;
			}
			pclose(pipe);
			if(result == "")
			{
				result ="Done";
			}
		}
		
		cout << result << endl;
   
   return 0;
}

