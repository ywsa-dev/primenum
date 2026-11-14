#include <iostream>
#include <string>
#include <vector>
using namespace std;
void mprime(int n,vector<bool>& prime){
    for(int i=0; i<n; i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i*i<n; i++){
        if(prime[i]){
            for(int j=i*i; j<n; j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(int argc,char* argv[]){
    if(argc!=4){
        cout << "primenum.exe (number) yes/no/notlog yes/no" << endl;
        cout << "first yes/no/notlog -> if yes, it will be print prime number. if no, it will be not print prime number.\nif notlog, it will be print only prime number." << endl;
        cout << "last yes/no -> if yes, it will be print count. else, it will be not print count." << endl;
        return 0;
    }
    vector<bool> prime(stoi(argv[1]));
    mprime(stoi(argv[1]),prime);
    int cnt=0;
    if(argc==4){
        for(int i=0; i<stoi(argv[1]); i++){
            if(prime[i]){
                cnt++;
                if(string(argv[2])=="yes"&&string(argv[2])!="no"){
                    cout << "find prime number: " << i << '\n';
                }
                if(string(argv[2])=="notlog"&&string(argv[2])!="no"){
                    cout << i << '\n';
                }
            }
        }
    }
    else {
        return 1;
    }
    if(string(argv[3])=="yes"&&string(argv[3])!="no"){
        cout << "count : " << cnt << '\n';
    }
    return 0;
}