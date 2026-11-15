#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;   

    int child[100][100];  
    int cnt[100] = {0};   

    for (int i = 0; i < n - 1; i++)
    {
        int parent, folder;
        cin >> parent >> folder;

        child[parent][cnt[parent]] = folder;
        cnt[parent]++;
    }
    int leafCount = 0;
   
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)   
            leafCount++;
    }

    cout << "Number of folders with no subfolders: " << leafCount << endl;

    return 0;
}
