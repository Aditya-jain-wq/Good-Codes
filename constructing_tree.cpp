// reading and constructing tree from stream of numbers.
// can be used to store tree in a file and construct back tree when needed

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void inoder(node* root)
{
	if(root==NULL)
		return;
	inoder(root->left);
	cout<<root->data;
	inoder(root->right);
}


int main()
{   
  	queue <node*> q;
  	node* root=new node;
  	cin>>root->data;
  	root->left=root->right=NULL;  
  	q.push(root);
  	while(!q.empty())
  	{
  		node* tmp=q.front();
  		q.pop();
  		int datatmp;
  		cout<<"data? for left of "<<tmp->data<<" ";
  		cin>>datatmp;
  		if (datatmp!=-1) // assigned -1 as null, can also assign INT_MIN as NULL if -1 can be value for some node
  		{
  			tmp->left=new node;
  			tmp->left->data=datatmp;
  			tmp->left->left=tmp->left->right=NULL;
  			q.push(tmp->left);
  		}

  		cout<<"data? for right of "<<tmp->data<<" ";
  		cin>>datatmp;
  		if (datatmp!=-1)
  		{
  			tmp->right=new node;
  			tmp->right->data=datatmp;
  			tmp->right->left=tmp->right->right=NULL;
  			q.push(tmp->right);
  		}

  	}
    inoder(root);
    return 0;
}
