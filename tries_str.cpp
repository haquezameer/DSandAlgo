#include <bits/stdc++.h>

using namespace std;

#define cas 'a'
#define alp 26
#define mx 50

struct trienode
{
	struct trienode* parent;
	struct trienode* children[26];
	int occurence;
};

void addWord(struct trienode* root,char* word)
{
	struct trienode* node = root;
	while(*word != '\0')
	{
		if(node->children[*word - cas ] == '\0')
		{
			node->children[*word - cas] = (struct trienode*)calloc(1,sizeof(trienode));
			node->children[*word - cas]->parent=node;
		}
		node=node->children[*word - cas];
		word++;
	}

	node->occurence++;
}

bool searchword(struct trienode* root,char* word)
{
	struct trienode* temp=root;
	if(*word == '\0')
	{
		return false;
	}

	while(*word != '\0')
	{
		if(temp->children[*word - cas] == NULL)
		{	
			return false;
		}
		temp=temp->children[*word - cas];
		++word;
	}

	if(*word == '\0' && temp->occurence > 0)
	{
		return true;
	}
	else
		return false;
}


int main()
{
	trienode* root=(struct trienode*)calloc(1,sizeof(trienode));
	int n;
	cin>>n;
	char word[mx];;
	for(int i=0;i<n;i++)
	{
		cin>>word;
		addWord(root,word);
	}
	bool id;
	for(int i=0;i<n;i++){
	cout<<"Enter word"<<endl;
	cin>>word;
	id=searchword(root,word);
	if(id==true)
	cout<<"Found";
else cout<<"Not found";
	}
	return 0;

}