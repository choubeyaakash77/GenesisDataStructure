#include <bits/stdc++.h>
#include "genesis.h"
using namespace std;

int main(){
	
	Node* genesis = createGenesisNode(0);
	encryptPassword(genesis, 5);
	
	
	
	
	
	
	{
		//	int c=0;
		//	do{
		//		cout<<"\n------------------------------------------------------------------------\n"
		//			<<"1 : Create Genesis Node\n"
		//	    	<<"2 : Create Set of Child Node\n"
		//	    	<<"3 : Create Child Node of a Node\n"
		//	    	<<"4 : Encrypt/Decrypt Data\n"
		//	    	<<"5 : Verify Owner\n"
		//	    	<<"6 : Edit a Node\n"
		//	    	<<"7 : Transfer Ownership\n"
		//	    	<<"8 : Longest Chain (Genesis Node)\n"
		//	    	<<"9 : Longest Chain (Any Node)\n"
		//	    	<<"0 : Exit"
		//	    	<<"\n------------------------------------------------------------------------\n";
		//	    cout<<"Enter your choice : ";
		//	    cin>>c;
		//	    switch(c){
		//	    	case 1: int n;
//							cout<<"\n Enter node number : ";
//							cin>>n;
//							Node* genesis = createGenesisNode(n);
		//					break;
//			    	case 2: int n, m;
//							cout<<"\n Enter node number : ";
//							cin>>n;
//							cout<<"\n Enter current node number : ";
//							cin>>m;

//							addChildNode(n, genesis, m);
//		break;
		//	    	case 3:
		//	    	case 4:
		//			case 5:
		//	    	case 6:
		//	    	case 7:
		//	    	case 8:
		//	    	case 9:
		//	    	default: cout<<"Under Construction\n";
		//	    	case 0: break;
		//		}
		//	}while(c!=0);
	}
	return 0;
}
