#include<bits/stdc++.h>
#include<windows.h>
#include<VaccineData.h>
#include<SortAndSearch.h>
#include<Registration.h>
using namespace std;
extern int ID;
VaccineData* arr[15];
vector<Registration> application;
static bool isLoaded = false;

int main();
void loadData();
void printSortedDataByDistrict();
void printSortedDataByCenter();
void printSortedDataBySlot();
void printPincodeData();
void printAvailableSlots();
void printRegistration();
void printWithdraw();
void printReceipt();
string* selectConfiguration(int pin,int y);

int main()
{
    if(!isLoaded){
        loadData();
        isLoaded = true;
    }
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(15,y);
    cout << "Select Choice:" << endl;
    y += 2;
    gotoxy(15,y);
    cout << "1. Available Slots\n";
    y += 2;
    gotoxy(15,y);
    cout << "2. Register\n";
    y += 2;
    gotoxy(15,y);
    cout << "3. View Registration Application\n";
    y += 2;
    gotoxy(15,y);
    cout << "4. Withdraw Registration Application\n";
    y += 2;
    gotoxy(15,y);
    cout << "5. Exit\n";
    y += 2;
    gotoxy(15,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
        {
            printAvailableSlots();
            break;
        }
        case 2:
        {
            printRegistration();
            break;
        }
        case 3:
        {
            printReceipt();
            break;
        }
        case 4:
        {
            printWithdraw();
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        default:
            y += 2;
            gotoxy(15,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            main();
    }
    return 0;
}
void loadData(){
    arr[0] = new VaccineData("Ahmedabad","Nutan",380061,35);
    arr[1] = new VaccineData("Ahmedabad","M.B.Patel",380061,20);
    arr[2] = new VaccineData("Ahmedabad","Gyanda Girls",380061,25);
    arr[3] = new VaccineData("Ahmedabad","MS School",382330,40);
    arr[4] = new VaccineData("Ahmedabad","Ranip UHC",382480,55);
    arr[5] = new VaccineData("Baroda","Panigate",390017,28);
    arr[6] = new VaccineData("Baroda","Premanand Hall",390017,79);
    arr[7] = new VaccineData("Baroda","Bapod",390017,64);
    arr[8] = new VaccineData("Baroda","Goraj PHC",391761,60);
    arr[9] = new VaccineData("Rajkot","Aniyara",360020,48);
    arr[10] = new VaccineData("Rajkot","Bhayavadar CHC",360450,38);
    arr[11] = new VaccineData("Rajkot","Haribapa collage",360450,60);
    arr[12] = new VaccineData("Gandhinagar","CHC sadra",382320,58);
    arr[13] = new VaccineData("Gandhinagar","PHC ajol",382810,76);
    arr[14] = new VaccineData("Gandhinagar","PHC bilodara",382810,67);
}
void printSortedDataByDistrict(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(40,y);
    cout << "District       CenterName       Pincode        AvailabelSlots" << endl;
    y += 2;
    SortAndSearch :: sortByDistrict(arr,15);
    for(int i = 0;i < 15;i++){
        gotoxy(40,y);
        y += 2;
        cout << arr[i]->district;
        for(int j = 0;j < 15 - arr[i]->district.length();j++){
            cout << " ";
        }
        cout << arr[i]->centerName;
        for(int j = 0;j < 17 - arr[i]->centerName.length();j++){
            cout << " ";
        }
        cout << arr[i]->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << arr[i]->slot;
    }
    y += 2;
    gotoxy(40,y);
    cout << "Select Choice: ";
    y += 2;
    gotoxy(40,y);
    cout << "1. Sort By District Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "2. Sort By Center Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "3. Sort By Available Slots\n";
    y += 2;
    gotoxy(40,y);
    cout << "4. Search By Pincode\n";
    y += 2;
    gotoxy(40,y);
    cout << "5. Back To Home Page\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            printSortedDataByDistrict();
            break;
        case 2:
            printSortedDataByCenter();
            break;
        case 3:
            printSortedDataBySlot();
            break;
        case 4:
            printPincodeData();
            break;
        case 5:
            main();
            break;
        default:
            y += 2;
            gotoxy(40,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            printAvailableSlots();
    }
}
void printSortedDataByCenter(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(40,y);
    cout << "District       CenterName       Pincode        AvailabelSlots" << endl;
    y += 2;
    SortAndSearch :: sortByCenterName(arr,15);
    for(int i = 0;i < 15;i++){
        gotoxy(40,y);
        y += 2;
        cout << arr[i]->district;
        for(int j = 0;j < 15 - arr[i]->district.length();j++){
            cout << " ";
        }
        cout << arr[i]->centerName;
        for(int j = 0;j < 17 - arr[i]->centerName.length();j++){
            cout << " ";
        }
        cout << arr[i]->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << arr[i]->slot;
    }
    y += 2;
    gotoxy(40,y);
    cout << "Select Choice: ";
    y += 2;
    gotoxy(40,y);
    cout << "1. Sort By District Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "2. Sort By Center Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "3. Sort By Available Slots\n";
    y += 2;
    gotoxy(40,y);
    cout << "4. Search By Pincode\n";
    y += 2;
    gotoxy(40,y);
    cout << "5. Back To Home Page\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            printSortedDataByDistrict();
            break;
        case 2:
            printSortedDataByCenter();
            break;
        case 3:
            printSortedDataBySlot();
            break;
        case 4:
            printPincodeData();
            break;
        case 5:
            main();
            break;
        default:
            y += 2;
            gotoxy(40,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            printAvailableSlots();
    }
}
void printSortedDataBySlot(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(40,y);
    cout << "District       CenterName       Pincode        AvailabelSlots" << endl;
    y += 2;
    SortAndSearch :: sortByAvailableSlots(arr,15);
    for(int i = 0;i < 15;i++){
        gotoxy(40,y);
        y += 2;
        cout << arr[i]->district;
        for(int j = 0;j < 15 - arr[i]->district.length();j++){
            cout << " ";
        }
        cout << arr[i]->centerName;
        for(int j = 0;j < 17 - arr[i]->centerName.length();j++){
            cout << " ";
        }
        cout << arr[i]->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << arr[i]->slot;
    }
    y += 2;
    gotoxy(40,y);
    cout << "Select Choice: ";
    y += 2;
    gotoxy(40,y);
    cout << "1. Sort By District Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "2. Sort By Center Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "3. Sort By Available Slots\n";
    y += 2;
    gotoxy(40,y);
    cout << "4. Search By Pincode\n";
    y += 2;
    gotoxy(40,y);
    cout << "5. Back To Home Page\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            printSortedDataByDistrict();
            break;
        case 2:
            printSortedDataByCenter();
            break;
        case 3:
            printSortedDataBySlot();
            break;
        case 4:
            printPincodeData();
            break;
        case 5:
            main();
            break;
        default:
            y += 2;
            gotoxy(40,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            printAvailableSlots();
    }
}
void printPincodeData(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Pincode: ";
    int pin;
    cin >> pin;
    vector<VaccineData*> pinData = SortAndSearch :: searchByPincode(arr,15,pin);
    if(pinData.empty()){
        y += 2;
        gotoxy(40,y);
        cout << "Pincode is not available in Database";
        Sleep(1000);
        printAvailableSlots();
    }
    y += 2;
    gotoxy(40,y);
    cout << "District       CenterName       Pincode        AvailabelSlots" << endl;
    y += 2;
    for(auto v : pinData){
        gotoxy(40,y);
        y += 2;
        cout << v->district;
        for(int j = 0;j < 15 - v->district.length();j++){
            cout << " ";
        }
        cout << v->centerName;
        for(int j = 0;j < 17 - v->centerName.length();j++){
            cout << " ";
        }
        cout << v->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << v->slot;
    }
    y += 2;
    gotoxy(40,y);
    cout << "Select Choice: ";
    y += 2;
    gotoxy(40,y);
    cout << "1. Search By Pincode\n";
    y += 2;
    gotoxy(40,y);
    cout << "2. Back To Home Page\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            printPincodeData();
            break;
        case 2:
            main();
            break;
        default:
            y += 2;
            gotoxy(40,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            printAvailableSlots();
    }
}
void printAvailableSlots(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    cout << "\n";
    y += 2;
    gotoxy(40,y);
    cout << "District       CenterName       Pincode        AvailabelSlots" << endl;
    y += 2;
    for(int i = 0;i < 15;i++){
        gotoxy(40,y);
        y += 2;
        cout << arr[i]->district;
        for(int j = 0;j < 15 - arr[i]->district.length();j++){
            cout << " ";
        }
        cout << arr[i]->centerName;
        for(int j = 0;j < 17 - arr[i]->centerName.length();j++){
            cout << " ";
        }
        cout << arr[i]->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << arr[i]->slot;
    }
    y += 2;
    gotoxy(40,y);
    cout << "Select Choice: ";
    y += 2;
    gotoxy(40,y);
    cout << "1. Sort By District Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "2. Sort By Center Name\n";
    y += 2;
    gotoxy(40,y);
    cout << "3. Sort By Available Slots\n";
    y += 2;
    gotoxy(40,y);
    cout << "4. Search By Pincode\n";
    y += 2;
    gotoxy(40,y);
    cout << "5. Back To Home Page\n";
    y += 2;
    gotoxy(40,y);
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            printSortedDataByDistrict();
            break;
        case 2:
            printSortedDataByCenter();
            break;
        case 3:
            printSortedDataBySlot();
            break;
        case 4:
            printPincodeData();
            break;
        case 5:
            main();
            break;
        default:
            y += 2;
            gotoxy(40,y);
            cout << "Invalid Choice" << endl;
            Sleep(1000);
            printAvailableSlots();
    }
}
void printReceipt(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    y += 2;
    gotoxy(15,y);
    cout << "Enter Application ID: ";
    int id;
    cin >> id;
    fflush(stdin);
    int i;
    for(i = 0;i < application.size();i++){
        if(application.at(i).id == id){
            y = application.at(i).printApplication();
            break;
        }
    }
    if(i == application.size()){
        y += 2;
        gotoxy(15,y);
        cout << "Invalid ID";
        y += 2;
        gotoxy(15,y);
        cout << "Select Choice: ";
        y += 2;
        gotoxy(15,y);
        cout << "1. Enter ID again";
        y += 2;
        gotoxy(15,y);
        cout << "2. Back to Home page";
        y += 2;
        gotoxy(15,y);
        cout << "Enter Choice: ";
        int ch;
        cin >> ch;
        if(ch == 1){
            printReceipt();
        }
        else if(ch == 2){
            main();
        }
        else{
            y += 2;
            gotoxy(15,y);
            cout << "Invalid Choice";
            Sleep(1000);
            main();
        }
    }
    y += 2;
    gotoxy(40,y);
    cout << "Press Enter to go back to Home Page ";
    getchar();
    main();
}
void printRegistration(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    y += 2;
    gotoxy(15,y);
    cout << "Enter Name: ";
    fflush(stdin);
    string name;
    getline(cin,name);
    y += 2;
    gotoxy(15,y);
    cout << "Enter Age: ";
    int age;
    cin >> age;
    y += 2;
    gotoxy(15,y);
    int pin;
    cout << "Enter Pincode: ";
    cin >> pin;
    if(SortAndSearch :: searchByPincode(arr,15,pin).empty()){
        y += 2;
        gotoxy(15,y);
        cout << "Pincode is not available in database. Please Visit available slots";
        Sleep(3000);
        main();
    }
    string* data = selectConfiguration(pin,y);
    Registration app(name,age,data[0],data[1]);
    application.push_back(app);
    y = app.printApplication();
    fflush(stdin);
    y += 2;
    gotoxy(40,y);
    cout << "Press Enter to go back to Home Page ";
    getchar();
    main();
}
void printWithdraw(){
    int y = 1;
    system("cls");
    gotoxy(60,y);
    cout << "Covid 19 Vaccine Registration Portal" << endl;
    y++;
    for(int i = 0;i < 158;i++){
        cout << "-";
    }
    y += 2;
    gotoxy(15,y);
    cout << "Enter Application ID: ";
    int id;
    cin >> id;
    fflush(stdin);
    int i, len = application.size();
    for(i = 0;i < len;i++){
        if(application.at(i).id == id){
            for(int j = 0;j < 15;j++){
                if(arr[j]->centerName.compare(application.at(i).center) == 0){
                    arr[j]->slot++;
                    break;
                }
            }
            application.erase(application.begin() + i);
            break;
        }
    }
    if(i == len){
        y += 2;
        gotoxy(15,y);
        cout << "Invalid ID";
        y += 2;
        gotoxy(15,y);
        cout << "Select Choice: ";
        y += 2;
        gotoxy(15,y);
        cout << "1. Enter ID again";
        y += 2;
        gotoxy(15,y);
        cout << "2. Back to Home page";
        y += 2;
        gotoxy(15,y);
        cout << "Enter Choice: ";
        int ch;
        cin >> ch;
        if(ch == 1){
            printWithdraw();
        }
        else if(ch == 2){
            main();
        }
        else{
            y += 2;
            gotoxy(15,y);
            cout << "Invalid Choice";
            Sleep(1000);
            main();
        }
    }
    y += 2;
    gotoxy(15,y);
    cout << "Application Withdrawl of id " << id << " successful";
    y += 2;
    gotoxy(15,y);
    cout << "Press Enter to go back to Home Page ";
    getchar();
    main();
}
string* selectConfiguration(int pin,int y){
    vector<VaccineData*> data = SortAndSearch :: searchByPincode(arr,15,pin);
    y += 2;
    gotoxy(15,y);
    cout << "No     District       CenterName       Pincode        AvailabelSlots" << endl;
    int i = 1;
    for(auto v : data){
        y += 2;
        gotoxy(15,y);
        cout << i << "      ";
        cout << v->district;
        for(int j = 0;j < 15 - v->district.length();j++){
            cout << " ";
        }
        cout << v->centerName;
        for(int j = 0;j < 17 - v->centerName.length();j++){
            cout << " ";
        }
        cout << v->pincode;
        for(int j = 0;j < 10;j++){
            cout << " ";
        }
        cout << v->slot;
        i++;
    }
    y += 2;
    gotoxy(15,y);
    cout << "Select No: ";
    int no;
    cin >> no;
    if(!(no >= 1 && no < i)){
         y += 2;
        gotoxy(15,y);
        cout << "Invalid No";
        Sleep(1000);
        main();
    }
    string *ans = new string[2];
    ans[0] = data.at(no-1)->district;
    ans[1] = data.at(no-1)->centerName;
    for(int i = 0;i < 15;i++){
        if(ans[1].compare(arr[i]->centerName) == 0){
            arr[i]->slot--;
            break;
        }
    }
    return ans;
}
