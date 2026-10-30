/*Problem: 
A company has N employees, where one employee is the head of the company. Each employee may manage multiple employees.

You are given the employee IDs and N-1 manager-employee relationships. Your task is to construct the company hierarchy and print all employees level by level, starting from the head employee.

Employees at the same level should be printed in the order they appear in the input relationships.*/


#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;

  int emp[100];

    for (int i = 0; i < n; i++)
        cin >> emp[i];

    int child[100][100];
    int cnt[100] = {0};

    for (int i = 0; i < n - 1; i++){
        int manager, employee;
        cin >> manager >> employee;

        child[manager][cnt[manager]] = employee;
        cnt[manager]++;
    }

    int root = emp[0];

    queue<int> q;
    q.push(root);

    int level = 1;

    while (!q.empty()){
        int sz = q.size();
     cout << "Level " << level << ": ";

        for (int i = 0; i < sz; i++){
            int cur = q.front();
            q.pop();

            cout << cur;

            if(i <sz-1)
                cout << " ";

            for(int j = 0; j < cnt[cur]; j++){
                q.push(child[cur][j]);
            }
        }

        cout << endl;
        level++;
    }

    return 0;
}




