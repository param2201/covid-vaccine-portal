#include "SortAndSearch.h"
#include <VaccineData.h>
#include<bits/stdc++.h>
using namespace std;

void SortAndSearch :: sortByDistrict(VaccineData* arr[],int len){
    sort(arr,arr + len,[](const VaccineData* obj1,const VaccineData* obj2){
        return obj1 -> district < obj2 -> district;
    });
}
void SortAndSearch :: sortByCenterName(VaccineData* arr[],int len){
    sort(arr,arr + len,[](const VaccineData* obj1,const VaccineData* obj2){
        return obj1 -> centerName < obj2 -> centerName;
    });
}
void SortAndSearch :: sortByAvailableSlots(VaccineData* arr[],int len){
    sort(arr,arr + len,[](const VaccineData* obj1,const VaccineData* obj2){
        return obj1 -> slot > obj2 -> slot;
    });
}
vector<VaccineData*> SortAndSearch :: searchByPincode(VaccineData* arr[],int len,int pin){
    vector<VaccineData*> data;
    for(int i = 0;i < len;i++){
        if(arr[i] -> pincode == pin){
            data.push_back(arr[i]);
        }
    }
    return data;
}
