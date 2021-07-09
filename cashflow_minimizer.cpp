#include<bits/stdc++.h>
using namespace std;

int get_max_creditor(vector<int> & cash){
    int debit = INT_MIN;
    int person = 0;

    for(int i=0; i<cash.size(); i++){
        if(cash[i]>debit){
            debit = cash[i];
            person = i;
        }
    }

    return person;
}

int get_max_debitor(vector<int> & cash){
    int credit = INT_MAX;
    int person = 0;

    for(int i=0; i<cash.size(); i++){
        if(cash[i]<credit){
            credit = cash[i];
            person = i;
        }
    }

    return person;
}

vector<pair<int,int>> minimize_cashflow (unordered_map<int, vector<pair<int, int>>>  & graph, int total_persons){
    vector<int> net_cash (total_persons, 0);

    for(auto v : graph){
        for(auto nbr : v.second){    
            net_cash[v.first] -= nbr.second;
            net_cash[nbr.first] += nbr.second;
        }
    }

    cout<<"\nNet CashFlow for each person (Negative:Debitor | Positive:Creditor)\n";
    cout<<"----------------------------\n\n";

    for(int i=0; i<total_persons; i++){
        cout<<net_cash[i]<<" ";
    }

    int debitor = get_max_debitor(net_cash);
    int creditor = get_max_creditor(net_cash);

    vector<pair<int,int>> minimized_transactions;

    while(net_cash[debitor]!=0 and net_cash[creditor]!=0){
        int amt =  min (abs(net_cash[debitor]), abs(net_cash[creditor]));

        net_cash[debitor] += amt;      // ----> max_debitor paid that amount to max_creditor
        net_cash[creditor] -= amt;     // ----> max_creditor received this amount from max_debitor   

        minimized_transactions.push_back({debitor, creditor});

        debitor = get_max_debitor(net_cash);
        creditor = get_max_creditor(net_cash);
    }

    return minimized_transactions;
}

void show_minimized_transactions(vector<pair<int,int>> & transactions){
    cout<<"\n\n\nMinimized Transactions\n";
    cout<<"----------------------\n\n";

    for(auto p : transactions){
        cout<<p.first<<" --> "<<p.second<<endl;
    }
    cout<<endl<<endl;
}


void addEdge(unordered_map<int, vector<pair<int, int>>> & graph, int u, int v, int amount){
    graph[u].push_back({v, amount});
}

int main(){
    unordered_map<int, vector<pair<int, int>>> graph;
    int n = 3;

    addEdge(graph, 0, 1, 1000);
    addEdge(graph, 1, 2, 5000);
    addEdge(graph, 0, 2, 2000);

    auto minimized_transaction = minimize_cashflow (graph, n);
    show_minimized_transactions(minimized_transaction);

    return 0;
}