#include "BinaryIndependenceModel.hpp"
#include<cstdlib>
#include<iostream>
using namespace std;
int main(int argv, char *argc[])
{
	BinaryIndependenceModel b;
	if(argv<2)return 0;
	int ret_docs = atoi(argc[2]);
	cout<<ret_docs<<endl;
	b.run_program(argc[1],ret_docs);
	return 0;
}
