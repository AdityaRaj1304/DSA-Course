#include<bits/stdc++.h>
using namespace std;

void itenerayTickets(unordered_map<string,string>tickets){
    unordered_set<string>to;

    for(auto t: tickets){
        to.insert(t.second);
    }

    //Starting Point
    string start ="";

    for(auto t: tickets){
        if(to.find(t.first)==to.end()){ // Not Found
            start = t.first; // Starting Point
        }
    }

    //Print Path
    cout << "Path: " << start << " -> ";
    while(tickets.count(start)){
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "Destination.";
}

int main(){
    unordered_map<string,string>tickets;
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";
    itenerayTickets(tickets);
    return 0;
}