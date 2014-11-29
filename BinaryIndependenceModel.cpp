#include "BinaryIndependenceModel.hpp"
#include<cmath>
#include <algorithm>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
class BinaryIndependenceModel;
class Data;
bool find(Document *d,const string& match)
{
    int i;
    for(i=0;i<d->getWords().size();i++)
        if(d->getWords()[i].compare(match)==0)
        return true;
    return false;
}
bool operator <(Document d1,Document d2)
{
    if(d1.score>d2.score)
        return true;
    else
        return false;
}
BinaryIndependenceModel::BinaryIndependenceModel()
{
	data = new Data();
}
BinaryIndependenceModel::~BinaryIndependenceModel()
{
	delete data;
}
void BinaryIndependenceModel::run_program(string filename, int ret_docs)
{
    int N,S,s,df;
    //int ret_docs;
    double num,den,score;
//    double d;//Score
    map<string,double> m;
	data->get_data(filename);
	data->get_query();
	data ->get_rel_docs();

    //cout<<"\nEnter number of Documents to be retrieved\n";
    //cin >> ret_docs;
	//N = data->nrel_docs.size()+data->rel_docs.size();//N=num_rel
	//S = data->rel_docs.size();//N=num_not_rel
	N = data->num_tot;
	S = data->num_rel;
	
	for(int w=0;w<data->query.getWords().size();w++)
    {
        s=df=0;
        for(int r=0;r<N;r++)
            if(find(&(data->tot_docs[r]),data->query.getWords()[w]))
                {
                    df++;
                    if(data->tot_docs[r].relevant == true)
                        s++;
                }
		num = (s+0.5)/(S-s+0.5);
		den = (df-s+0.5)/(N-df-S+s+0.5);
//        cout<<"N "<<N<<" df "<<df<<" S "<<S<<" s "<<s;
//        cout<<" "<<num<<" "<<den<<" ";
//        cout<<r<<" ";
		score = log10(num/den);
//        cout<<score<<endl;
		m[data->query.getWords()[w]]=score;
        //cout<<s<<endl;
    }
    for(int r=0;r<data->tot_docs.size();r++)
	{
        score=0;
	    double tempscore = 0.0;
	    for(int w=0;w<data->tot_docs[r].getWords().size();w++)
        {
            score += m[data->tot_docs[r].getWords()[w]];

        }
        data->tot_docs[r].score=score;
        //cout<<score<<" is score of doc "<<r<<endl;
        printf("%5.2lf is score of doc %7d\n",score,r);
	}
  
	sort(data->tot_docs.begin(),data->tot_docs.end());
    cout<<"sorted values are\n";
    double rel_ret = 0;
	for(int r=0;r<ret_docs;r++)
     {   cout<<data->tot_docs[r].index<<endl;
	       
        if(data->tot_docs[r].relevant)
            rel_ret++;
    }

    cout<<"\nThe precision is : "<<rel_ret/ret_docs<<"\nThe recall is: "<<rel_ret/data->num_rel;
    //print docs,ranks in dec order of rank
}