// (a + b) % M = ((a % M) + (b % M)) % M
// (a * b) % M = ((a % M) * (b % M)) % M
// (a - b) % M = ((a % M) - (b % M) + M) % M
// (a / b) % M = ((a % M) * (b(inverse)) % M) % M

// M = (10 ^ 9) + 7;
// M is a prime number
#include <iostream>
using namespace std;
int main()
{
    int M = 1e9 + 7;
    return 0;
}