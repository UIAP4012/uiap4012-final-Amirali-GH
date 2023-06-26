#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//======================================================================================
//Global variable:

//======================================================================================
//Prototypes:
void spendTime();
void Create_a_file_for_listing_the_products();

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
    string username,password,currency;
    fstream Product_list;
public:
    Mall_cell() {
        Product_list.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\Product_list.csv", ios::in | ios::out | ios::app);
        setCurrency("Dollar");
    }
    ~Mall_cell() {
        Product_list.close();
    }

    void   setCurrency( string );
    string getCurrency();

    void Show_product ();
    void Edit_product ();
    void Add_product  ();
    void Exchange_rate( Mall_cell& );
};
class Product:Mall_cell{
private:
    string name;
    int code;
    float price;
    int number;

public:
    Product();

    //Setter and getter functions:
    void setName(string);
    string getName();
    void setCode(int);
    int getCode();
    void setPrice(float);
    float getPrice();
    void setNumber(int);
    int getNumber();

    //Other functions:
    void   Add_product();
};

//======================================================================================
//Main:
int main() {
    cout << "***********    Hello my friend, Welcome to your Mall    ***********" << endl;
    cout << "\nLets go to set our initial setting and storage...\n";
    Create_a_file_for_listing_the_products();
    spendTime();
    system("cls");

    while( true ){
        menu:
        system("cls");
        cout << "***********    Big Mall    ***********" << endl;
        cout << "\n1)Manager\n2)Customer\n" << "\nWhat is your role? " ;
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
                    system("cls");
                    cout << "***********    Big Mall ( Manager )    ***********" << endl;
                    cout << "\n1)Show product\n2)Edit products\n3)Add_product\n4)Exchange_rate\n5)Exit" << "\nWhat do you want to do? " ;
                    int duty;
                    cin>>duty;
                    system("cls");
                    switch (duty) {
                        case 1:
                            Manager.Show_product ();
                            break;
                        case 2:
                            Manager.Edit_product ();
                            break;
                        case 3:
                            Manager.Add_product  ();
                            break;
                        case 4:
                            Manager.Exchange_rate( Manager );
                            break;
                        case 5:
                            goto menu;
                            break;
                        default:
                            continue;
                    }
                }
            }
        }

        //Entered as Manager:
        else if( key == 2 ){
            int key_customer=1;
            while( key_customer ){
                Mall_shop user1;
                user1.addUser();
            }
        }
        //Wrong answer and it must enter again.
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
void Create_a_file_for_listing_the_products(){
    fstream Product_list;
    Product_list.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\Product_list.csv", ios::in | ios::out | ios::app);
    Product_list << "Name" << ","  << "Code" << ","  << "Price"<< "," << "Currency" << ","  << "Number" << endl;
    Product_list.close();
}

//======================================================================================
//Function of class of Mall_shop:
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

//======================================================================================
//Function of class of Mall_cell:
void Mall_cell::Show_product  (){
    fstream Product_list("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\Product_list.csv", ios::in);
    system("cls");
    string line;
    while (getline(Product_list, line)) {
        stringstream ss(line);
        string temp;
        for (int i = 0; i < 5; i++) {
            getline(ss, temp, ',');
            cout << temp << "           ";
        }
        cout << endl;
    }
    Product_list.close();
    string exit;
    cout << "\nIf you want to quit, type ( Exit ) : ";
    cin >> exit;
    if (exit == "Exit")
        system("cls");
}
void Mall_cell::Edit_product  (){
    Product pro;
    cout << "***********    Big Mall ( Manager _ Add product )    ***********" << endl;
    cout << "\nName of product : "   ;
    string na; cin>>na;
    pro.setName( na );

    cout << "\nCode of product : "   ;
    int co; cin>>co;
    pro.setCode( co );

    cout << "\nPrice of product : "  ;
    float pr; cin>>pr;
    pro.setPrice( pr );

    cout << "\nNumber of product : " ;
    int nu; cin>>nu;
    pro.setNumber( nu );
}
void Mall_cell::Add_product   (){
    Product pro;
    cout << "***********    Big Mall ( Manager _ Add product )    ***********" << endl;
    cout << "\nName of product : "   ;
    string na; cin>>na;
    pro.setName( na );

    cout << "\nCode of product : "   ;
    int co; cin>>co;
    pro.setCode( co );

    cout << "\nPrice of product ("<< getCurrency() <<") : "  ;
    float pr; cin>>pr;
    pro.setPrice( pr );

    cout << "\nNumber of product : " ;
    int nu; cin>>nu;
    pro.setNumber( nu );

    fstream product_file;
    product_file.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\"+na+".txt", ios::in | ios::out | ios::app) ;
    Product_list << na << ","  << co << ","  << pr << ","  << getCurrency() << ","  << nu <<endl   ;
    product_file << na << endl << co << endl << pr << endl << getCurrency() << endl << nu <<endl   ;
    product_file.close();
    Product_list.close();
}
void Mall_cell::Exchange_rate(Mall_cell& Manager) {
    while (true) {
        menuOfExchangeRate:
        system("cls");
        cout << "***********    Big Mall ( Manager _ Exchange_rate )    ***********" << endl;
        cout << "\n1)Rial\n2)Dollar\n3)Euro\n4)Exit" << "\nWhat currency to change?";
        int key;
        cin >> key;
        switch (key) {
            case 1:
                Manager.setCurrency("Rial");
                system("cls");
                cout << "Currency successfully changed!" << endl;
                spendTime();
                break;
            case 2:
                Manager.setCurrency("Dollar");
                system("cls");
                cout << "Currency successfully changed!" << endl;
                spendTime();
                break;
            case 3:
                Manager.setCurrency("Euro");
                system("cls");
                cout << "Currency successfully changed!" << endl;
                spendTime();
                break;
            case 4:
                goto menuOfExchangeRate;
            default:
                continue;
        }
        break;
    }

    // Get lines for modifier:
    fstream Product_list;
    Product_list.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\Product_list.csv", ios::in);
    vector<vector<string>> outputs;
    string temp;
    int i = 0;
    if (Product_list.is_open()) {
        while (std::getline(Product_list, temp)) {
            if (i == 0) {  // Skip header line
                i++;
                continue;
            }
            vector<string> tokens;
            stringstream ss(temp);
            string token;
            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            tokens[3] = Manager.getCurrency(); // Fix the column name
            outputs.push_back(tokens);
            i++;
        }
    }
    Product_list.close();

    // Write again the lines:
    Product_list.open("C:\\Users\\user1\\Desktop\\uiap4012-final-Amirali-GH\\Product_files\\Product_list.csv", ios::out | ios::trunc);
    if (Product_list.is_open()) {
        Product_list << "Code,Name,Price,Currency,Number" << endl; // Fix the column name
        for (int j = 0; j < outputs.size(); ++j) {
            for (int k = 0; k < outputs[j].size(); ++k) {
                Product_list << outputs[j][k];
                if (k != outputs[j].size() - 1) {
                    Product_list << ",";
                }
            }
            Product_list << endl;
        }
    }
    Product_list.close();
}

void   Mall_cell::setCurrency( string cu ){
    this->currency = cu;
}
string Mall_cell::getCurrency(){
    return this->currency;
}

//======================================================================================
//Function of class of Product:
Product::Product(){
    setCode   (0000);
    setName   ("BigMall");
    setNumber (0);
    setPrice  (0);
}

void   Product::setName        ( string na ){
    this->name = na;
}
string Product::getName        (){
    return  this->name;
}
void   Product::setCode        ( int co ){
    this->code = co;
}
int    Product::getCode        (){
    return  this->code;
}
void   Product::setPrice       ( float pr ){
    this->price = pr;
}
float  Product::getPrice       (){
    return  this->price;
}
void   Product::setNumber      ( int nu ){
    this->number = nu;
}
int    Product::getNumber      (){
    return  this->number;
}
