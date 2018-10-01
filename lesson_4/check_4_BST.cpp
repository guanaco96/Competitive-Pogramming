/* This algorithm read input quite in an odd manner  (this is
 * due to the unclear formatting specs given in the g4g website).
 * After that it recursively checks if, for any given node, its key
 * lies between the maximum of his left subtree and the minimum of
 * its right subtree.
 * 
 * ACHTUNG: Due to g4g submitter issues I was unable to test this code
 * on large input, then it may be wrong. 
 */
#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	node *left;
	node *right;
	node(int k){
		key=k; 
		left=right=NULL;
	}
};

map<int,node*> inserted;
map<int,int> father;

void insert_node(int key){
	if(inserted.find(key)==inserted.end()){
		node *pt= new node(key);
		inserted.insert(make_pair(key, pt));
	}
};

void insert_arc(int dad, int son, char c){
	insert_node(dad);
	insert_node(son);
	if(c=='L') inserted[dad]->left=inserted[son];
	else inserted[dad]->right=inserted[son];
	father.insert(make_pair(son,dad));
};

tuple<bool,int,int> isBST(node *nd){
	if(nd->left==NULL && nd->right==NULL) return tuple<bool,int,int>(true,nd->key,nd->key);
	tuple<bool,int,int> l, r;
	l=isBST(nd->left);
	r=isBST(nd->right);
	int min= get<1>(l);
	int max= get<2>(r);
	bool x= get<0>(l) && get<0>(r);
	x=x && get<2>(l)<nd->key && get<1>(r)>nd->key;
	return tuple<bool,int,int>(x,min,max);
};	

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n;
		cin>>n;
		while(inserted.size()<(unsigned) n+1){
			int dad, son;
			char c;
			cin>>dad>>son>>c;
			insert_arc(dad,son,c);
		}
		node *root=inserted.begin()->second;
		while(1){
			try {root=inserted[father.at(root->key)];}
			catch(const exception& e) {break;}
		}
		cout<<endl;
		cout<<get<0>(isBST(root));	
	}
	
return 0;
}
