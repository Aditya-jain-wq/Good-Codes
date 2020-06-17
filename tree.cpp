#include <bits/stdc++.h>
using namespace std;

#define loop(i,s,n) for(int i=s;i<n;i++)

struct node
{
	int data;
	node* left;
	node* right;
};

void disinoder(node* root)
{
	if(root==NULL)return;
	disinoder(root->left);
	cout<<root->data;
	disinoder(root->right);
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
  		if (datatmp!=-1)
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

    
    disinoder(root);
    
    
    
    
    
    return 0;
}