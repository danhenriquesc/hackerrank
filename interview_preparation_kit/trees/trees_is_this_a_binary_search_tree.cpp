/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

#define node Node 
#define null NULL

    void print ( node* root ) {
        if ( root == null ) return;
        cout << "ROOT : " << root->data << endl ;
        cout << "LEFT : " << endl;
        print ( root->left );
        cout << "RIGHT : " << endl;
        print ( root->right );
        return;
    }

    bool func ( node* root , int right_limit , int left_limit ) {
        if ( root == null )     return true ;
        if ( right_limit !=-1 and root->data >= right_limit )    return false ;
        if ( left_limit != -1 and root->data <= left_limit )     return false ;
        
        return func ( root->left , root->data , left_limit ) and func ( root->right , right_limit , root->data );
    }

	bool checkBST(Node* root) {
       // cout << "TREE CONTENTS  :  " << endl; 
       // print ( root );
        return func ( root , -1 , -1 );
	}