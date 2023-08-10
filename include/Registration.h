#ifndef REGISTRATION_H
#define REGISTRATION_H
#include<bits/stdc++.h>
using namespace std;
static int ID = 2021000;
void gotoxy(int x,int y);
class Registration
{
    string name;
    int age;
    string date, vdate;
    string dist;
    public:
        int id;
        string center;
        Registration(string name, int age,string district,string centerName);
        int printApplication();
};

#endif // REGISTRATION_H
