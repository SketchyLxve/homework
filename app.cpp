#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> evenDigits(vector<int> evens, int n)
{
    int copy = int(n);

    if (copy <= 0)
        return evens;
    int rem = n % 10;
    if (rem % 2 == 0)
        evens.push_back(copy % 10);

    copy /= 10;
    return evenDigits(evens, copy);
}

int sumEvens(int number)
{
    int res = 0;
    vector<int> _;
    vector<int> evens = evenDigits(_, number);
    for (auto e : evens)
    {
        res += e;
    }

    return res;
}

int main(int argv, char *argc[])
{
    if (argv > 11)
    {
        cout << "Denied to supply over 10 numbers in a single argument." << endl;
        return 0;
    }

    for (int i = 1; i < argv; ++i)
    {
        int test;
        if (!(atoi(argc[i]) >> test))
        {
            cout << "All arguments must be an integer." << endl;
            return 0;
        }
    }

    vector<int> all_evens;
    for (int i = 1; i < argv; ++i)
    {
        int sum = sumEvens(atoi(argc[i]));
        all_evens.push_back(sum);
        cout << sum << endl;
    }

    cout << "Largest number in sequence: " << *max_element(all_evens.begin(), all_evens.end()) << endl;

    return 0;
}