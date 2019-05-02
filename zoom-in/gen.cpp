#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    cout << rnd.next(1, 10) << endl; /* Random number in the range [1,10]. */
    cout << rnd.next("[a-zA-Z0-9]{1,1000}") << endl;  /* Random word of length [1,1000]. */
}
