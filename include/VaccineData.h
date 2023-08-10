#ifndef VACCINEDATA_H
#define VACCINEDATA_H
#include<bits/stdc++.h>
using namespace std;

class SortAndSearch;
class VaccineData
{
    public:
        string district, centerName;
        int pincode, slot;
        VaccineData(string district, string center, int pin, int slot);
        friend ostream& operator<<(ostream& out, const VaccineData* obj){
            out << "<" << obj -> district << " , " << obj -> centerName << " , " << obj -> pincode << " , " << obj -> slot << ">";
            return out;
        }
        friend class SortAndSearch;
};

#endif // VACCINEDATA_H
