#include "Recipe.h"
#include <iostream>


Node::Node() : name(""), quant(0.0f), qual(""), next(nullptr) {}

Node::Node(string name, float quant, string qual) : name(name), quant(quant), qual(qual), next(nullptr) {}

void Node::printNode()
{
	cout << this->name << " :: " << this->quant << " :: " << this->qual;
}

RecipeLL::RecipeLL() : head(nullptr) {}

RecipeLL::RecipeLL(string name, float quant, string qual)
{
	this->head = new Node(name, quant, qual);
}

RecipeLL::~RecipeLL()
{
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void RecipeLL::insert(string name, float quant, string qual)
{
	Node* newNode = new Node(name, quant, qual);
	Node* iter = this->head;

	if (iter == nullptr)
	{
		this->head = newNode;
	}

	else
	{

		while(iter->next != nullptr)
		{
			iter = iter->next;
		}

		iter->next = newNode;
	}

}

void RecipeLL::remove(string name)
{
	if (this->head != nullptr)
	{
		if (this->head->name == name)
		{
			Node* tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		}

		else
		{
			Node* iter = this->head;
			while (iter->next != nullptr)
			{
				if (iter->next->name == name) break;
				iter = iter->next;
			}
			if (iter->next->name == name)
			{
				Node* tmp = iter->next;
				if (iter->next->next == nullptr)
				{
					iter->next = nullptr;
					delete tmp;
				}
				else
				{
					iter->next = tmp->next;
					delete tmp;
				}
			}
		}
	}
}

void RecipeLL::print()
{
	Node* iter = this->head;
	while (iter != nullptr)
	{
		iter->printNode();
	}
}
