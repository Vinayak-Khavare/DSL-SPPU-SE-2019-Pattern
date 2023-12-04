//sumedh sir
//written by vinayak


//A palindrome is a string of character that�s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. 
//For example, �Poor Dan is in a droop� is a palindrome, as can be seen by examining the characters �poor danisina droop� and observing that 
//they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with 
//them the original-in a palindrome, the sequence will be identical. Write C++ program with functions
//a) To print original string followed by reversed string using stack 
//b) To check whether given string is palindrome or not


#include<iostream>
#include<string>
#define n 100
using namespace std;

class stack{
	
	char str[n];
	int top;
	
	public:
		stack(){
			top=-1;
		}
		
	void push(char c){
//		if(str[top]=='\0'){
//			cout<<"stack full."<<endl;
//		}
		top++;
		str[top]=c;
		str[top+1]='\0';
	}
	
	void pop(){
		if(top==-1){
			cout<<"stack empty."<<endl;
		}
		top--;
	}
	
	void reverse(){
		char tmp[n];
		for(int i=0, j=top; j>=0; i++, j--){
			tmp[i]=str[j];
		}
		cout<<"reverse is: ";
		for(int k=0; k<=top; k++){
			cout<<tmp[k];
		}
		cout<<endl;
	}
	
	void print(){
		for(int i=0; i<=top; i++){
			cout<<str[i];
		}
		cout<<endl;
	}
	
	void convert(char s1[]){
		int j,k,len=0;
		for(int i=0; s1[i]!='\0'; i++){
			len++;
		}

		for(j=0, k=0; j<len; j++){
			if( ( (int)s1[j] >= 97 && (int)s1[j] <=122 ) || ( (int)s1[j] >= 65 && (int)s1[j] <=90 )){
				if( (int)s1[j] <=90 ){
					s1[k] = (char)( (int)s1[j] + 32 );
				}else{
					s1[k] = s1[j];				
				}
				k++;			
			}
		}
		s1[k]='\0';
		cout<<endl<<"Converted string : "<<s1<<"\n";
	}
	
	void palindrome(){	
		char s1[n];
		int i,j;
		bool flag=true;		

		for(i=top,j=0; i>=0; i--,j++){
			s1[j]=str[i];
		}
		s1[j]='\0';
		
		for(i=0; s1[i]!='\0'; i++){
			if(s1[i]==str[i]){
				continue;
			}
			else{
				flag = false;
				break;
			}
		}
		if(flag==true)
			cout<<"\n\nString is palindrome"<<endl;
		else
			cout<<"\n\nString is not palindrome"<<endl;
	}
};

int main(){
	stack stack;

	char s1[n];
//	string s1;
	int i=0;
	
	cout<<"\nEnter string to be reversed and check is it palindrome or not : \n\n";
	
	cin.getline(s1, 100);
	stack.convert(s1);
	
	while(s1[i] != '\0')
	{
		stack.push(s1[i]);
		i++;
	}
	stack.palindrome();
	stack.reverse();
}
