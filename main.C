#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
    char option;
    string firstName;
    string lastName;
    ifstream file("names.txt");
    string   line;
    BST *B=new BST();
    while(getline(file, line))
    {
        stringstream   linestream(line);
        linestream>>firstName>>lastName;

        B->insert(firstName,lastName);
    }
    while(1){
        cout<<"Select an option"<<endl;
        cout<<"1. Search a survivor with last name"<<endl;
        cout<<"2. Register a new survivor "<<endl;
        cout<<"3. Remove an already registered survivor "<<endl;
        cout<<"4. Count of survivors registered"<<endl;
        cout<<"5. print out of all the registered survivors in alphabetical order by family name"<<endl;
        cout<<"0. exit"<<endl;
        cin>>option;
        switch(option)
        {
            case '1' :
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                if(B->search(lastName)==NULL){
                    cout<<"Sorry no survivor with this name"<<endl;
                }
                break;
            case '2' :
                cout<<"Enter survivor's first name"<<endl;
                cin>>firstName;
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                B->insert(firstName,lastName);
                cout<<"Survivor added successfully"<<endl;
                break;
            case '3' :
                cout<<"Enter survivor's first name"<<endl;
                cin>>firstName;
                cout<<"Enter survivor's last name"<<endl;
                cin>>lastName;
                B->remove(firstName,lastName);
                break;
            case '4' :
                cout<<"Total "<<B->nodes<<" survivors are here."<<endl;
                break;
            case '5':
                B->sort(B->root);
                break;
            case '0':
                exit(1);

            default : cout<<"Invalid selection"<<endl;
        }
    }
    return 0;
}
