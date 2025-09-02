#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0;
    int x = 0;
    do
    {
        cin >> n >> m;
    } while ((n < 0) || (m < 0));
    while (m != 0)
    {
        if (m % 2 != 0)
            x = x + n;
        n = n + n;
        m = m / 2;
    }
    cout << "El resultado es " << x << endl;
    return 0;
}