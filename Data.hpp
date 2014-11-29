#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include"Document.hpp"
using namespace std;
class Document;

class Data
{
public:
	Data()
{
	//rel_docs_index = new vector<int>();
	//tot_docs = new vector<Document>();
}
	Document query;
	int num_not_rel;
    	vector<int> rel_docs_index;
	int num_rel;
	void get_data(string);
 void get_query();

   void get_rel_docs();
	int num_tot;
	vector<Document> tot_docs;
};
