#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
const int Max_length =20;
class Employee{
	private : int eno;
	char name[Max_length];
	double sal;
	public : Employee(){
		eno =0;
		name[0] ='\0';
		sal=0;
     }
     Employee(int no,char*nm,double s) :eno(no),sal(s){
     	strcpy(name,nm,Max_length-1);
     	name[Max_length-1]='\0';
     	
	 }
     void accept(){
     	cout<<"\n\nEnter Employee Number, Name, and Salary: ";
     	cin>>eno>>name>>sal;
	 }	
     void display(){
     	cout<<" "<<eno<<" "<<name<<" "<<sal;
	 }	
	 void addrecord(){
	 	ofstream fout("emp1.txt",ios::app |ios :: binary);
	 	if(!fout){
	 		cout<<"file cannot be open"<<endl;
	 		return;
		 }
		 accept();
		 fout.write(reinterpret_cast<const char*>(this),sizeof(Employee));
		 fout.close();
	 }
	void displayRecord(){
		ifstream fin("emp1.txt",ios::binary);
		if(!fin){
		cout<<"file cannot be open"<<endl;
	 		return;	
		}
	Employee e;
	while(fin.read(reinterpret_cast<const char*>(this),sizeof(Employee)){
		if(fin.gcount()==sizeof(Employee)){
			e.display();
		}
		else{
			cout<<"unable to open file ";
			break;
	    	}
     	} fin.close();
	}
	
	bool search(int eno){
		ifstream fin("emp1.txt",ios::binary);
	 	if(!fin){
	 		cout<<"unable to open file ";
	 		return false;
	 		
		 }
		 bool found =false;
		 while(fin.read(reinterpret_cast<const char*>(this),sizeof(Employee))){
		 	if(e.eno==eno){
		 		e.display();
				 found true;
			 }
		 }
		 fin.close();
		 return found;
	}
	bool modify(int eno){
		fstream file("emp1.txt",ios::binary | ios::in | ios::out);
		if(!file){
			cout<<"unable to open file ";
			return false;
		}
		bool found =false;
		while(file.read(reinterpret_cast<const_char*>(this),sizeof(Employee))){
			if(e.eno==eno){
				long pos=file.tellg()-sizeof(Employee);
				file.seekp(pos);
				e.accept();
				file.write(reinterpret_cast<const char*>(&e),sizeof(Employee))
			found =true;
			break;
			}
		}
			file.close();
				return found;
	}
	int countrecord(){
		ifstream fin("emp1.txt",ios::binary);
		if(!file){
			cout<<" cannot open file ";
			return 0;
		}
		file.seekg(0,ios::end);
		int count =file.tellg()/sizeof(Employee);
		file.close();
		return count;
	}
	
};


int main(){
	int eno,ch;
	Employee e1;
	do{
		cout<<"\n\n 1.add records";
		cout<<"\n\n 2. display records";
		cout<<"\n\n 3.search records";
		cout<<"\n\n 4.count records";
		cout<<"\n\n 5.Modify records";
		cout<<"\n\n 6.Delete records";
		cout<<"\n\n 7.exit";
		cin>>ch;
		switch(ch){
			case 1 :
				e1.addrecords();
				break ;
			case 2:
				e1.displayRecord();
			    break ;
		    case 3 :
		    	cout << "\nEnter Employee Number To Search: ";
                cin >> eno;
                if(!e1.search(eno)){
                	cout << "\nRecord Not Found." << endl;
				}
			   break;
			 case 4:
			 	cout<<"number of records : "<<e1.countRecord()<<endl;
			    break;  	
			case 5:
				cout << "\nEnter Employee Number To Modify: ";
                cin >> eno;
                if (!e1.modify(eno))
                    cout << "\nRecord Not Found." << endl;
                break;
		
			
			
		}
		
	
		
	}while(ch!=0);
	
	
	return 0;
}

