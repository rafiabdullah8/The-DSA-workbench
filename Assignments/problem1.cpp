#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;                 

    int emp[100];
    for (int i = 0; i < n; i++)
        cin >> emp[i];      

    int child[100][100];      
    int cnt[100] = {0};       

    
    for (int i = 0; i < n - 1; i++)
    {
        int manager, employee;
        cin >> manager >> employee;

        child[manager][cnt[manager]] = employee;
        cnt[manager]++;
    }

    
    int root = emp[0];

    queue<int> q;
    q.push(root);

    int level = 1;

    while (!q.empty())
    {
    int sz = q.size();
    cout << "Level " << level << ": ";

    for (int i = 0; i < sz; i++)
        {
        int cur = q.front();
        q.pop();
    cout << cur;
            if (i < sz - 1)
            cout << " ";

        for (int j = 0; j < cnt[cur]; j++)
        {
        q.push(child[cur][j]);
        }
        }
        cout << endl;
        level++;
    }

    return 0;
}
