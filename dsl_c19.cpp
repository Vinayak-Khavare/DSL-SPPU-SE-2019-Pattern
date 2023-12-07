// sumedh sir
// written by vinayak

// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department 
// can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club 
// and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store 
// student PRN and Name. Write functions to: a) Add and delete the members as well as president or even secretary. b) Compute total number 
// of members of club c) Display members d) Two linked lists exists for two divisions. Concatenate two lists.

#include<iostream>
#include<string>
using namespace std;

struct node{
	int prn;
	string name;
	node* next;
};

class div{
	public:
		node* head;
		node* tail;
		div(){
			head = NULL;
			tail = NULL;
		}
		
		void add(int p, string nm){
			node* temp = new node;
			if(head==NULL){
				temp->prn=p;
				temp->name=nm;
				temp->next=NULL;
				head=temp;
				tail=temp;
			}
			else{
				node* curr = head;
				temp->prn=p;
				temp->name=nm;
				temp->next=NULL;
				while(curr->next!=tail){
					curr=curr->next;
				}
				curr->next = temp;
				temp->next = tail;
				tail->next = NULL;
			}
		}
		
		void display(){
			if(head==NULL){
				cout<<"No list"<<endl;
			}
			else{
				node* temp = head;
				while(temp!=NULL){
					cout<<"PRN: "<<temp->prn<<" Name: "<<temp->name<<endl;
					temp=temp->next;
				}
			}
		}
		
		void del(int p){
			char ch;
			if(head->prn==p){
				cout<<"Are you trying to remove President?(Y/N)";
				cin>>ch;
				if(ch=='Y' || ch=='y'){
					del_pres();
				}
			}
			else if(tail->prn==p){
				cout<<"Are you trying to remove Secretory?(Y/N)";
				cin>>ch;
				if(ch=='Y' || ch=='y'){
					del_secr();
				}
			}
			else{
				node* prev = NULL;
				node* curr = head;
				while(curr->prn!=p){
					prev = curr;
					curr = curr->next;
				}
				prev->next=curr->next;
				curr->next=NULL;
				cout<<"deleted prn, "<<curr->prn<<" and name, "<<curr->name<<endl;
				delete curr;
			}
		}
		
		void length(){
			node* temp = head;
			int cnt=0;
			while(temp!=NULL){
				cnt++;
				temp = temp->next;
			}
			cout<<"total strength is, "<<cnt<<endl;
		}
		
		void del_pres(){
			cout<<"The next person in the club will be the president."<<endl;
			node* temp = head;
			head = head->next;
			temp->next = NULL;
			cout<<"Deleting president..."<<endl;
			cout<<head->name<<" is now the President."<<endl;
			delete temp;
		}
		
		void del_secr(){
			node* temp1 = head;
			node* temp2 = tail;
			while(temp1->next!=tail){
				temp1=temp1->next;
			}
			temp1->next=NULL;
			tail = temp1;
			cout<<"Deleting secretory..."<<endl;
			cout<<temp1->name<<" is now the Secretory."<<endl;
			delete temp2;
		}
		
		int search(int p){
			node* temp = head;
			while(temp!=tail){
				if(temp->prn==p){
					return 1;
				}
				else{
					temp=temp->next;
				}
			}
			if(tail->prn==p){
				return 1;
			}
			else{
				return 0;
			}
		}
		
		void add_pres(int p, string nm){
			if(head==NULL){
				add(p, nm);
			}
			else{
				node* temp = new node;
				temp->next = head;
				temp->prn = p;
				temp->name = nm;
				head = temp;
			}
		}
		
		void add_secr(int p, string nm){
			if(head==NULL){
				add(p, nm);
			}
			else{
				node* temp = new node;
				temp->prn = p;
				temp->name = nm;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			}
		}
		
		void concat(div &obj){
			if(obj.head==NULL){
				cout<<"No members in other div."<<endl;
			}
			else{
				node* temp = tail;
				this->tail = obj.tail;
				temp->next = obj.head;
				obj.head = this->head;
				this->display();
			}
		}
};

int main(){
//	node* head = NULL;
//	node* tail = NULL;

	div A, B;
	div* d;
	int ch;
	char c;
	
	x: cout<<"enter your division(A/B): ";
	cin>>c;
	
	if(c=='A'){
		d = &A;
	}
	else if(c=='B'){
		d = &B;
	}
	else{
		cout<<"wrong input."<<endl;
		goto x;
	}
	cout<<"\nCurrent divion is, "<<c<<endl;
	while(true){
		cout<<"\n****---Menu---****"
			<<"\n01. Create Club."
			<<"\n02. Add president."
			<<"\n03. Add secretory."
			<<"\n04. Add members."
			<<"\n05. Delete president."
			<<"\n06. Delete secretory."
			<<"\n07. Delete members."
			<<"\n08. total member of the club."
			<<"\n09. display members of the club."
			<<"\n10. concatenate the clubs."
			<<"\n11. choose your div."
			<<"\n12. exit."<<endl;
		cout<<"****---****---****"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>ch;
		
		if(ch==1){
			int p;
			string nm;
			cout<<"Enter prn and name of the president: ";
			cin>>p>>nm;
			d->add(p, nm);	
		}
		
		else if(ch==2){
			int p;
			string nm;
			cout<<"Enter prn and name of the president: ";
			cin>>p>>nm;
			int result = d->search(p);
			if(result==1){
				cout<<"Already exists!"<<endl;
			}
			else{
				d->add_pres(p, nm);
			}
		}
		
		else if(ch==3){
			int p;
			string nm;
			cout<<"Enter prn and name of the secretory: ";
			cin>>p>>nm;
			int result = d->search(p);
			if(result==1){
				cout<<"Already exists!"<<endl;
			}
			else{
				d->add_secr(p, nm);
			}	
		}
		
		else if(ch==4){
			int p;
			string nm;
			cout<<"Enter prn and name of the member: ";
			cin>>p>>nm;
			int result = d->search(p);
			if(result==1){
				cout<<"Already exists!"<<endl;
			}
			else{
				d->add(p, nm);
			}
		}
		
		else if(ch==5){
			d->del_pres();
		}
		
		else if(ch==6){
			d->del_secr();
		}
		
		else if(ch==7){
			int p;
			cout<<"enter the prn of the member you want to remove: ";
			cin>>p;
			d->del(p);
		}
		
		else if(ch==8){
			d->length();
		}
		
		else if(ch==9){
			d->display();
		}
		
		else if(ch==10){
			char ch;
			cout<<"Want to check members of both div befor concatenation?(Y/N) ";
			cin>>ch;
			if(ch=='Y' || ch=='y'){
				cout<<" \n Div A"<<endl;
				A.display();
				cout<<" \n Div B"<<endl;
				B.display();
			}
			cout<<"Concatenated the lists."<<endl;
			A.concat(B);
		}
		
		else if(ch==11){
			goto x;
		}
		
		else if(ch==12){
			cout<<"Thank you."<<endl;
			break;
		}
		
		else{
			cout<<"Wrong input."<<endl;
		}
	}
	
	return 0;
}
