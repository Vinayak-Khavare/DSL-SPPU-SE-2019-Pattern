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

class PinnacleClub{
    public:
    int prn;
    string name;
    PinnacleClub* next;

    // Constructor
    PinnacleClub(){
        int n;
        string s;
        cout<<"Enter prn and name of student : ";
        cin>>n>>s;
        this->prn = n;
        this->name = s;
        this->next = NULL;
    }

    // Destructor
    ~PinnacleClub(){
        int val = this->prn;
        string var = this->name;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"\nStudent with PRN no. "<<val<<" and name "<<var<<" has left the club."<<endl;
    }
};

void add_member(PinnacleClub* &head){
    PinnacleClub* temp = new PinnacleClub();
    if(head==NULL){
        head = temp;
    }
    else{
        head->next = temp;
    }
}

void delete_member(PinnacleClub* &head, int p){
    PinnacleClub* curr = head;
    PinnacleClub* prev = NULL;
    while(curr->prn!=p){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
//    cout<<"\nStudent with PRN no. "<<curr->prn<<" and name "<<curr->name<<" has left the club."<<endl;
    delete curr;
}

void delete_president(PinnacleClub* &head){
    PinnacleClub* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
//    cout<<"The President has left the club."<<endl;
}

void delete_secretory(PinnacleClub* &head){
    PinnacleClub* curr = head;
    PinnacleClub* prev = NULL;
    while(curr->next!=NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
//    cout<<"The secretory has left the club."<<endl;
}

void replace_president(PinnacleClub* &head, int prn_of_member, string name_of_member){
    PinnacleClub* temp = head;
    int temp_prn = head->prn;
    string temp_name = head->name;
    while(temp->prn!=prn_of_member){
        temp = temp->next;
    }
    head->prn = prn_of_member;
    head->name = name_of_member;
    temp->prn = temp_prn;
    temp->name = temp_name;
//    cout<<"The President has changed."<<endl;
}

void replace_secretory(PinnacleClub* &head, int prn_of_member, string name_of_member){
    PinnacleClub* temp = head;
    PinnacleClub* member = head;
    while(member->prn!=prn_of_member){
        member = member->next;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    int temp_prn = temp->prn;
    string temp_name = temp->name;
    temp->prn = member->prn;
    temp->name = member->name;
    member->prn = temp_prn;
    member->name = temp_name;
//    cout<<"The Secretory has changed."<<endl;
}

int total_members(PinnacleClub* &head){
    PinnacleClub* temp = head;
    int cnt = 0;
    do{
        cnt++;
        temp = temp->next;
    }
    while(temp->next!=NULL);

    return cnt;
}

void print(PinnacleClub* &head){
    if(head==NULL){
        cout<<"The club is empty."<<endl;
    }
    PinnacleClub* temp = head;
    int cnt = 0;
    while(temp->next!=NULL){
        if(cnt==0){
        cout<<"President : "<<temp->name<<endl;
        cout<<"Secretory : "<<temp->name<<endl;
        cnt++;
        }
        cout<<"Member "<<cnt<<" : "<<temp->name<<endl;
    }
    cout<<"Secretory : "<<temp->name<<endl;
}

void concatenate(PinnacleClub* &h1, PinnacleClub* &h2){
    PinnacleClub* temp = h1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = h2;
    h2 = h1;
}

int main(){
    PinnacleClub* head = NULL;
    // PinnacleClub* Divisons[6];
    while(true){
        int choice;
        cout<<"\n01. Create the club."<<endl
            <<"02. Add members to the club."<<endl
            <<"03. Delete member of the club."<<endl
            <<"04. Delete president of the club(the next person will be appointed as president)."<<endl
            <<"05. Delete secretory of the club(the previous person will be appointed as secretory)."<<endl
            <<"06. Replace President with an existing member of the club."<<endl
            <<"07. Replace Secretory with an existing member of the club."<<endl
            <<"08. Display number of existing club members."<<endl
            <<"09. Display members of the club."<<endl
            <<"10. Concatenate members of different divisions."<<endl
            <<"11. Exit."<<endl;

        cout<<"\nEnter your choice: ";
        cin>>choice;
        if(choice==1){
            PinnacleClub a;
            head = &a;
        }
        else if(choice==2){
            int n = 0;
            cout<<"No of students you want to add: ";
            cin>>n;
            for(int i=0; i<n; i++){
                add_member(head);
            }
        }
        else if(choice==3){
            int p;
            cout<<"enter prn of the member : ";
            cin>>p;
            delete_member(head, p);
        }
        else if(choice==4){
            delete_president(head);
        }
        else if(choice==5){
            delete_secretory(head);
        }
        else if(choice==6){
            int p;
            string s;
            cout<<"enter the prn and name of the elected president: ";
            cin>>p>>s;
            replace_president(head, p, s);
        }
        else if(choice==7){
            int p;
            string s;
            cout<<"enter the prn and name of the elected secretory: ";
            cin>>p>>s;
            replace_secretory(head, p, s);
        }
        else if(choice==8){
            int result = total_members(head);
            cout<<"There are currently "<<result<<" number of member in the club including President an Secretory."<<endl;
        }
        else if(choice==9){
            cout<<"\n";
            print(head);
            continue;
        }
        else if(choice==10){
            PinnacleClub *h1, *h2;
            int n;
            cout<<"enter the no of members in club from divition A: ";
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                add_member(h1);
            }
            cout<<"enter the no of members in club from divition B: ";
            cin>>n;
            for (int i = 0; i < n; i++)
            {
                add_member(h2);
            }
            concatenate(h1, h2);
            print(h1);
        }
        else if(choice==11){
        	cout<<"Thank You!"<<endl;
            break;
        }
        else{
            cout<<"Entered wrong choice, please enter a valid option."<<endl;
        }
    }
    return 0;
}
