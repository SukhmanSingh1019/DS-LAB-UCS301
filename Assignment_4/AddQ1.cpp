#include <iostream>
#include <queue>
using namespace std;
void generateBinary(int n){
    queue<string> q;
    q.push("1");
    while(n--){
        string s=q.front();
        q.pop();
        cout<<s;
        if(n>0) cout<<", ";
        q.push(s+"0");
        q.push(s+"1");
    }
}
int main(){
    generateBinary(4);
}

