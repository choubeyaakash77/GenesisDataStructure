#ifndef GENESIS_H
#define GENESIS_H

#include<bits/stdc++.h>
using namespace std;


// Define Nodes

class Data {
	public:
    int ownerId;
    float value;
    string owner_name;
};

class Node {
	public:
    time_t timestamp;
    string time_in_date;   									// Holds timestamp in string
    Data* data;
    int nodeNumber;
    string nodeId;
    Node* referenceNodeid;

    std::vector<Node *> childReferenceNodeid;               // Vector of Children

    Node* genesisReferenceNodeid;
    map<string, int> HashValue;			       // Hash of value of the set.

    bool isEncrypted;
    string password;

	int available;			//value that can be assigned to siblings
	
	Node(){
		this->data = new Data;
	}

};





// TASK 1
// Creating the ROOT Node (genesis node)
// TO DO -
// 1. Hash Values
// 2. to_string error
Node* createGenesisNode(int node_number){

	Node* n = new Node;
	n->timestamp = time(0);    // Get current timestamp
	
	n->nodeNumber = node_number;
	//n->nodeId = to_string(node_number);
	cout<<"\nEnter DATA";
	cout<<"\n OwnerId = ";
	cin>>(n->data->ownerId);
	cout<<"\n Value = ";
	cin>>n->data->value;
	cout<<"\n Owner Name = ";
	cin>>n->data->owner_name;
	
	n->referenceNodeid = NULL;
	n->genesisReferenceNodeid = n;   // genesis node is created update address.
	// n->HashValue = {n->timestamp,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}
	
	n->available = n->data->value;
	
	cout<<"Root node created"<<endl;
	
	return n;                  // return address of genesis node for future purposes.
}





// TASK 2 and 3
// Create set of child nodes for a given node, which we are finding using,
// node_number to query genesis node child nodes.
void addChildNode(int node_number,Node *genesis, int current_node_number){

    Node *l = (genesis->childReferenceNodeid[node_number]);
    int no=0;
    
    int i=1;
    while(i){
		Node *p = new Node;
		no++;
        p->nodeNumber = current_node_number;
        //p->nodeId = to_string(nodeNumber);
        cout<<"Enter DATA -";
        cout<<"\n OwnerId = ";
        cin>>p->data->ownerId;
        cout<<"\n Value = ";
        cin>>p->data->value;
        cout<<"\n Owner Name = ";
        cin>>p->data->owner_name;
        p->referenceNodeid = l ;      //This node's parent address will be &l
        p->genesisReferenceNodeid = genesis;   //copying genesis node address we received.
        // n->HashValue = {n->time_now,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}
		l->available = l->data->value;
		p->available = p->data->value;
        cout<<"Add more (1/0)";
        cin>>i;
    }
    cout<<"Added successfully \n";
}




// TASK 4-1 Encrypting the data using a key.
string encrypt(string s, int key){
	string en = s;
	for(int i=0; i<s.length(); i++)
		en[i] = s[i]+key;
	return en;
}
void encryptPassword(Node *n, int key){

	string pwd;
    cout<<"Enter owner password : ";
    cin>>pwd;
    
    n->password = encrypt(pwd, key);
    
    // cout<<"\nInput = "<<pwd;
	cout<<"\nEncrypted Password = "<<n->password;
	cout<<"\nPassword encrypted and stored.";
	n->isEncrypted = true;
}

// TASK 4-2 Decrypting the data using a key.
string decryot(string s, int key){
	string dec = s;
	for(int i=0; i<s.length(); i++)
		dec[i] = s[i] - key;
	return dec;
}

// TASK 5
bool verifyOwner(Node *given_node, string pwd, int key){
	// string en = encrypt(pwd, key);
	string dec = decrypt(given_node->password, key);
	if(dec == pwd)
		return true;
	else
		return false;
}






#endif // GENESIS.H
