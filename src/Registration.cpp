#include "Registration.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y){
    COORD obj;
    obj.X = x;
    obj.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),obj);
}
string tomorrowDate(int day,int mon,int year){
    int day_arr[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
	{
		day_arr[1] = 29;
	}
    else{
        day_arr[1] = 28;
    }

    if(day + 1 > day_arr[mon - 1]){
        day = 1;
        if(mon + 1 > 12){
            mon = 1;
            year++;
        }
        else{
            mon++;
        }
    }
    else{
        day++;
    }

    string tdate = "";
    if(day < 10){
        tdate = tdate + "0" + to_string(day);
    }
    else{
        tdate = tdate + to_string(day);
    }
    tdate += "-";
    if(mon < 10){
        tdate = tdate + "0" + to_string(mon);
    }
    else{
        tdate = tdate + to_string(mon);
    }
    tdate += "-";
    tdate += to_string(year);
    return tdate;
}

Registration::Registration(string name, int age,string district,string centerName)
{
    this -> name = name;
            this -> age = age;
            this -> id = ID;
            dist = district;
            center = centerName;
            auto now = time(0);
            auto *time = localtime(&now);
            int year = (time -> tm_year) + 1900;
            int month = (time -> tm_mon) + 1;
            int day = time -> tm_mday;
            date = "";
            if(day < 10){
                date = date + "0" + to_string(day);
            }
            else{
                date = date + to_string(day);
            }
            date += "-";
            if(month < 10){
                date = date + "0" + to_string(month);
            }
            else{
                date = date + to_string(month);
            }
            date += "-";
            date += to_string(year);
            vdate = tomorrowDate(day,month,year);
            ID++;
}
int Registration :: printApplication(){
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
        for(int i = 0;i < 80;i++){
            cout << "-";
        }
        y += 1;
        gotoxy(40,y);
        cout << "|";
        gotoxy(70,y);
        cout << "Vaccine Application";
        gotoxy(120,y);
        cout << "|";
        y += 2;
        gotoxy(40,y);
        cout << "| Name: " << name;
        gotoxy(90,y);
        cout << "Registration Date: " << date << " |";
        y += 2;
        gotoxy(40,y);
        cout << "| Age: " << age;
        gotoxy(120,y);
        cout << "|";
        y += 2;
        gotoxy(40,y);
        cout << "| Vaccination center: " << center << " , " << dist;
        gotoxy(120,y);
        cout << "|";
        y += 2;
        gotoxy(40,y);
        cout << "| Vaccination Date: " << vdate;
        gotoxy(120,y);
        cout << "|";
        y += 2;
        gotoxy(40,y);
        cout << "| Application ID: " << id;
        gotoxy(120,y);
        cout << "|";
        y += 1;
        gotoxy(40,y);
        for(int i = 0;i < 80;i++){
            cout << "-";
        }
        return y;
}
