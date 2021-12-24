#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D, Oc, Of, Od, Cs, Cb, Cm, Cd;
    cin >> D;
    cin >> Oc >> Of >> Od;
    cin >> Cs >> Cb >> Cm >> Cd;

    int firstFare = Oc + ((D - Of) * Od);
    int scndFare = Cb + ((D / Cs) * Cm) + (D * Cd);
    if(firstFare <= scndFare)
        cout << "Online Taxi";
    else
        cout << "Classic Taxi";
    return 0;
}