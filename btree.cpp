#include <iostream>
#include <string>
#include <sstream>
#include"btree.h"
#include"applicate.h"

using namespace std;
int main()
{
	int data_type = 1;
	Applicate<int>* application = new Applicate<int>();
	while(application->run(data_type))
	{
		delete application;
		cout << "1 - integer / 2 - float" << endl;
		cout << "Choose data type->";
		cin >> data_type;
	}
	return 0;
}


