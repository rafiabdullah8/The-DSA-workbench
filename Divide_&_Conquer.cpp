#include <iostream>
using namespace std;

void maxMin(int a[], int l, int r, int &maximum, int &minimum)
{
    // Base case
    if(l == r)
    {
        maximum = a[l];
        minimum = a[l];             
        return;
    }

    // Divide
    int mid = (l + r) / 2;

    int leftMax, leftMin;
    int rightMax, rightMin;

    // Conquer left
    maxMin(a, l, mid, leftMax, leftMin);

    // Conquer right
    maxMin(a, mid + 1, r, rightMax, rightMin);

    // Combine
    maximum = max(leftMax, rightMax);
    minimum = min(leftMin, rightMin);
}

int main()
{
    int a[] = {5, 2, 8, 1, 9};

    int n = 5;


    int maximum, minimum;

    maxMin(a, 0, n - 1, maximum, minimum);

    cout << "Maximum = " << maximum << endl;
    cout << "Minimum = " << minimum << endl;

    return 0;
}













