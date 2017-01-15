#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

struct node
{
	int count;
	node *child[26];
	node()
	{
		for(int a=0;a<26;a++) child[a] = NULL;
		count=0;
	}
};

void insert(node *root, string s)
{
	for(char ch : s)
	{
		if(root->child[ch-'a'] == NULL)
			root->child[ch-'a'] = new node();
		root = root->child[ch-'a'];
	}
	root->count++;
}

int find(node *root, string s)
{
	for(char ch : s)
	{
		if(root->child[ch-'a'] == NULL) return 0;
		root = root->child[ch-'a'];
	}
	return root->count;
}

void printall(node *root, string s)
{
	if(root == NULL) return;
	if(root->count > 0)
		cout << s << " " << root->count << " ";
	for(int a=0;a<26;a++)
		if(root->child[a])
			printall(root->child[a],s+(char)(a+'a'));
}

int main()
{
	node *root = new node;
	while(1)
	{
		string s;
		getline(cin,s);
		if(s.length() == 0) break;
		insert(root,s);
		//cout << find(root,s) << endl;
	}
	printall(root,"");
}

