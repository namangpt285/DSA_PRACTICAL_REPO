#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char helper, char dest) {
    if(n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }

    towerOfHanoi(n - 1, src, dest, helper);

    cout << "Move disk " << n << " from " << src << " to " << dest << endl;

    towerOfHanoi(n - 1, helper, src, dest);
}

int main() {
    cout << "--- Tower of Hanoi (3 Disks) ---" << endl;
    int n = 3;
    
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}