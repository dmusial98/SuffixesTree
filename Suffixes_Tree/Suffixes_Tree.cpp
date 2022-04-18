#include <iostream>

using namespace std;

struct tree_node
{
	string text = string();
	int start_index = -1, end_index = -1;
	tree_node* left_child = nullptr, * right_brother = nullptr, * suffix_link = nullptr;

	tree_node();
	tree_node(string text);
	tree_node(string text, int s_index, int e_index);


	bool does_exist_child_with_that_letter(char letter);
	void create_child(char letter);
	void append_letter_at_the_end_recursion(char letter);
	void append_letter_at_the_end(char letter);
};

tree_node* create_suffix_tree_ukkonen(string input_text)
{
	tree_node* root_node = new tree_node();

	for (int i = 0; i < input_text.length(); i++)
	{
		//append letter at the end of every node

		if (!root_node->does_exist_child_with_that_letter(input_text[i]))
		{
			//create new child
			root_node->create_child(input_text[i]);
		}
	}

	return root_node;
}

tree_node::tree_node() {}

tree_node::tree_node(string txt) : text(txt) {}

tree_node::tree_node(string text, int s_index, int e_index)
{
	this->text = text;
	this->start_index = s_index;
	this->end_index = e_index;
}

bool tree_node::does_exist_child_with_that_letter(char letter)
{
	tree_node* ptr = this->left_child;
	while (ptr != nullptr)
	{
		if (ptr->text.front() == letter)
			return true;

		ptr = ptr->right_brother;
	}
	 
	return false;
}

void tree_node::create_child(char letter)
{
	if (!this->left_child)
		this->left_child = new tree_node();
	else
	{
		tree_node* ptr = this->left_child;
		while (ptr->right_brother != nullptr)
		{
			ptr = ptr->right_brother;
		}

		ptr->right_brother = new tree_node(string(1, letter));
	}
}

void tree_node::append_letter_at_the_end(char letter)
{

}

void tree_node::append_letter_at_the_end_recursion(char letter)
{
	if (!this->left_child)
		this->text += letter;

	if (this->left_child)
		this->left_child->append_letter_at_the_end_recursion(letter);

	if (this->right_brother)
		this->right_brother->append_letter_at_the_end_recursion(letter);
}

int main()
{
	std::cout << "Hello World!\n";
}
