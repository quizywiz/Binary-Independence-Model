#include "BinaryIndependenceModel.hpp"
class BinaryIndependenceModel;

BinaryIndependenceModel::BinaryIndependenceModel()
{
	data = new Data();
}
void BinaryIndependenceModel::run_program()
{
	data->get_input_data();
	find N;
	find S
	foreach word in data->getQuery
		find s
		find dft;
		assign each word a score
	foreach document
		calcrank
	sort(documents, ranks)
	print docs,ranks in dec order of rank



}
BinaryIndependenceModel::~BinaryIndependenceModel()
{
	delete data;
}