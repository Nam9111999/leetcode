#include <iostream>
#include <vector>

using namespace std;

void print(int n) {
    vector<int> myVector(n, 0);
    int i = n -1;
    while(i >= 0) {
        i = n-1;
        for (int i = 0; i < n; ++i) {
            cout << myVector[i] << " ";
        }
        cout<<endl;

        while(myVector[i]==1&&i>=0){
            myVector[i] = 0;
            i--;
        }
        if (i < 0) break;
        myVector[i] = 1;
    }
    return;
}

int main()
{
   print(2);
}
