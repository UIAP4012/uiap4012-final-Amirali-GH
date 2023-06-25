#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//======================================================================================
//Global variable:

//======================================================================================
//Prototypes:
void spendTime();

//======================================================================================
//Classes:
class Mall_shop {
private:
    fstream users_file;
    vector<vector<string>> users;

public:
    Mall_shop() {
        users_file.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\users_file.txt", ios::in | ios::out | ios::app);
        readUsers();
    }
    ~Mall_shop() {
        users_file.close();
    }

    void readUsers();
    bool isUsernameExist(string username);
    bool isPasswordValid(string password);
    void addUser();
};
class Mall_cell {
private:
    string username,password;
    fstream Products;
public:
    Mall_cell() {
        Products.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Products.txt", ios::in | ios::out | ios::app);
    }
    ~Mall_cell() {
        Products.close();
    }
    void Show_product ();
    void Edit_product ();
    void Add_product  ();
    void Exchange_rate();

};

//======================================================================================
//Main:
int main() {
    cout << "***********    Hello my friend, Welcome to your Mall    ***********" << endl;
    cout << "\nLets go to set our initial setting and storage...\n";
    spendTime();
    system("cls");


    while( true ){
        cout << "***********    Big Mall    ***********" << endl;
        cout << "\n1)Manager\n2)Customer\n" << "\nWhat is your role?" ;
        int key;
        cin>>key;

        if( key == 1 ){
            int key_manager=1;
            while( key_manager ){

                //Make sure it wants to be a manager:
                system("cls");
                string key_continue;
                cout << "Do you want continue as manager? (yes or no) " ;
                cin>>key_continue;
                if( key_continue == "yes" ) {system("cls");}
                else if( key_continue == "no"  ) {system("cls"); break;}
                else { continue; }

                //Take its username and password to enter:
                cout << "***********    Big Mall ( Manager )    ***********" << endl;
                string username , password;
                cout << "\nUsername = " ;
                cin>>username;
                cout << "\nPassword = " ;
                cin>>password;

                //IS its password and username correct:
                if( username != "BigMall" || password != "Admin123"){
                    system("cls");
                    cout << "Username or Password is wrong!\nTry again... " ;
                    spendTime();spendTime();
                    continue;
                }

                //Entered as Manager:
                while( true ){
                    Mall_cell Manager;

                }
            }
        }

        else if( key == 2 ){
            int key_customer=1;
            while( key_customer ){
                Mall_shop user1;
                user1.addUser();

            }
        }

        else{
            system("cls");
            cout << "Choose 1 (Manager) or 2 (Customer)" << endl;
            spendTime();spendTime();
            system("cls");
        }
    }
    return 0;
}

//======================================================================================
//Function:
void spendTime() {
    for (int i = 0; i < 1000000000; i++){}
}

//======================================================================================
//Function of class:
void Mall_shop::readUsers() {
    string username, password;
    while (users_file >> username >> password) {
        users.push_back({username, password});
    }
}
bool Mall_shop::isUsernameExist(string username) {
    for (vector<string> user : users) {
        if (user[0] == username) {
            return true;
        }
    }
    return false;
}
bool Mall_shop::isPasswordValid(string password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return false;
    }
    int capitalCount = 0;
    int digitCount = 0;
    for (char c : password) {
        if (isupper(c)) {
            capitalCount++;
        }
        if (isdigit(c)) {
            digitCount++;
        }
    }
    if (capitalCount == 0) {
        cout << "Password must contain at least one capital letter." << endl;
        return false;
    }
    if (digitCount == 0) {
        cout << "Password must contain at least one digit." << endl;
        return false;
    }
    return true;
}
void Mall_shop::addUser() {
    system("cls");
    string username, password;
    cout << "***********    Create your account    ***********" << endl;
    while (true) {
        cout << "Enter your username: ";
        cin >> username;
        if (isUsernameExist(username)) {
            system("cls");
            cout << "Username already exists. Please choose another one." << endl;
        }
        else {
            break;
        }
    }
    while (true) {
        cout << "\nEnter your password: ";
        cin >> password;
        if (isPasswordValid(password)) {
            break;
        }
    }

    users_file.close();
    users_file.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\users_file.txt", ios::in | ios::out | ios::app);
    users_file << username << " " << password << endl;
    users.push_back({username, password});
    users_file.close();
    ofstream user_contect("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\User_content\\"+username+".txt" , ios::out | ios::app);

    cout << "Account created successfully!" << endl;
}



