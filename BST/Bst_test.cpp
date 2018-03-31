#include "Bst.h"
#include<iostream>

using namespace std;

int main()
{
	treefamily::Bst<int> bst;
	bst.Clear();
	bst.Insert(6);
	bst.Insert(5);
	bst.Insert(8);
	bst.Postlist();
	cout << endl;
	bst.Prelist();
	auto i= bst.Find(6);
	if (i)
		cout << i->data_<<endl;
	 i = bst.Find(3);
	if (i)
		cout << "it's wrong!" << endl;
	bst.Delete(6);
	bst.Postlist();
	cout << endl;
	bst.Prelist();
	bst.Clear();
	bst.Postlist();
	cout << endl;
	bst.Prelist();
	system("pause");
	return 0;
}