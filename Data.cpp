#include "Data.hpp"
#include <iostream>
class Data;
Data::Data()
{
	rel_docs = new vector<Documents>();
	nrel_docs = new vector<Documents>();
}
Data::get_input_data()
{
	char rel;
	std::cin>>rel;
	std::cin>>numrel;
	for(int i =0 ;i<numrel; ++i)
	{
		Document d;
		std::cin>>d.words;
	}
	inputquery
}
Data::~Data()
{
	delete documents;
}