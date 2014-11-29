#include "Data.hpp"
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class Document;
class Data;
void Data::get_data(string filename)
{
    int relv, word_count;
	string word;
	
    ifstream fin(filename.c_str());
    fin >> num_tot;
    tot_docs.resize(num_tot);
    for(relv=0;relv<num_tot;relv++)
    {

        //tot_docs[relv].relavent=true
        fin >> word_count;
        tot_docs[relv].index = relv;
        //tot_docs[relv].getWords().resize(word_count);
        for(int j=0; j<word_count; j++)
        {
            fin >> word;
	       tot_docs[relv].add(word);
	    //	cout<<word<<j<<" ";
        }
    //    cout<<endl;
    }
    //cout<<"done reading docs "<<num_tot<<endl;
    //fin >> num_not_rel;

    fin.close();
}
void Data::get_query()
{
    string word;
    int query_words;
    	cin >> query_words;
    //query.getWords().resize(query_words);
    for(int i=0; i< query_words; i++)
    {
        cin >> word;
        query.add(word);
    }
}
void Data::get_rel_docs()
{
    cin>>num_rel;
    rel_docs_index.resize(num_rel);
    for(int i=0; i<num_rel; i++)
    {
        cin >>rel_docs_index[i];
        tot_docs[rel_docs_index[i]].relevant = true;
    }
    //num_not_rel = num_total - num_rel;
}