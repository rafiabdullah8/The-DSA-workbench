#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
double profit;
double weight;
};

bool comp(Item a,Item b){
    return(a.profit/a.weight > b.profit/b.weight);
}

int main(){
    int n;
    cout<<"Enter the no.of items: ";
    double cap;
    cin>>n;
    vector<Item> items(n);
for(int i=0;i<n;i++){
    cin>>items[i].profit>>items[i].weight;
}
cin>>cap;

sort(items.begin(),items.end(), comp);
double totalProfit=0;

for(int i=0;i<n;i++){
    if(items[i].weight <= cap){
totalProfit+=items[i].profit;
cap-=items[i].weight;
}else{
    double fraction=cap/items[i].weight;

    totalProfit=+items[i].profit*fraction;
    break;
}
}

cout<<"MaxProfit: "<<totalProfit ;
 return 0;
}
