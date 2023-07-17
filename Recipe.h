#pragma once
#include <string>
using namespace std;

class Node {
	
public:
	Node();
	Node(string name, float quant, string qual);
	void printNode();

private:
	string name;
	float quant;
	string qual;
	Node* next;


};


class RecipeLL {

public:
	Node* head;
	RecipeLL();
	RecipeLL(string name, float quant, string qual);
	~RecipeLL();
	void insert(string name, float quant, string qual);
	void remove(string name);
	void print();

};