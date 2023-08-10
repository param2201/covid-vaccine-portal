#ifndef SORTANDSEARCH_H
#define SORTANDSEARCH_H
#include<bits/stdc++.h>
#include<VaccineData.h>
using namespace std;

class SortAndSearch
{
    public:
        static void sortByDistrict(VaccineData* arr[],int len);
        static void sortByCenterName(VaccineData* arr[],int len);
        static void sortByAvailableSlots(VaccineData* arr[],int len);
        static vector<VaccineData*> searchByPincode(VaccineData* arr[], int len, int pin);
};

#endif // SORTANDSEARCH_H
