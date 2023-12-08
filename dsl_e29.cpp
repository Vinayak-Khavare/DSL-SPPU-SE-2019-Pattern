//sumedh sir
//witten by vinayak

//Queues are frequently used in computer programming, and a typical example is the creation of a job queue by 
//an operating system. If the operating system does not use priorities, then the jobs are processed in the 
//order they enter the system. Write C++ program for simulating job queue. Write functions to add job and 
//delete job from queue.


#include<iostream>
#define n 10
using namespace std;

class queue{
	int front, rear;
	int arr[n];
	public:
		queue(){
			front = -1;
			rear = -1;
		}
		void enqueue(int a){//from rear end
			if(front==-1){
				front++;
				arr[front]=a;
				rear++;
			}
			else{
				rear++;
				arr[rear]=a;
			}
		}
		
		void deque(){//from front end
			if(front==-1){
				cout<<"Queue is empty."<<endl;
			}
			else if(front>=0 && front==rear){
				front = -1;
				rear = -1;
			}
			else{
				front++;
			}
		}
		
		void print(){
			if(front==-1){
				cout<<"Queue is empty."<<endl;
			}
			else{
				int temp = front;
				while(temp!=rear){
					cout<<" "<<arr[temp];
					temp++;
				}
				cout<<" "<<arr[temp]<<endl;
			}
		}
		
		void priority(int a){
			if(front==-1){
				front++;
				arr[front]=a;
				rear++;
			}
			else{
				rear++;
				for(int i=rear; i>front; i--){
					arr[i]=arr[i-1];
				}
				arr[front]=a;
			}
		}
};

struct job{
	int jobId;
	int prior;
};

int main(){
	queue obj;
	job obj_j;
	int ch;
	while(true){
		cout<<"----MENU----";
		cout<<"\n1. Add a job."
			<<"\n2. Delete job."
			<<"\n3. Print available jobs in Queue."
			<<"\n4. Exit."<<endl;
		cout<<"\nEnter choice: ";
		cin>>ch;
		
		if(ch==1){
			int t;
			cout<<"No. of jobs you are entering(max=5): ";
			cin>>t;
			for(int i=0; i<t; i++){
				x:cout<<"Enter job id and its priority(0/1): ";
				cin>>obj_j.jobId>>obj_j.prior;
				if(obj_j.prior==0){
					obj.enqueue(obj_j.jobId);
				}
				else if(obj_j.prior==1){
					obj.priority(obj_j.jobId);
				}
				else{
					cout<<"Wrong input"<<endl;
					goto x;
				}
			}
		}
		else if(ch==2){
			obj.deque();
		}
		else if(ch==3){
			cout<<"Job IDs of queued jobs:";
			obj.print();
		}
		else if(ch==4){
			cout<<"Thank you!"<<endl;
			break;
		}
		else{
			cout<<"Invalid choice, try again."<<endl;
		}
	}
	return 0;
}
