#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include<string>
using namespace std;
int board[25];
int checking[25];
bool printred[25];
int iterate=0;
string print;
void createboard(int board[]) {
    std::vector<int> numbers;
    for (int i = 1; i <= 25; i++) {
        numbers.push_back(i);
    }
    std::random_device rd;             
    std::mt19937 g(rd());            
    std::shuffle(numbers.begin(), numbers.end(), g);
    for(int i=0;i<25;i++){
        board[i]=numbers[i];
    }
}
void printboard(int board[25],int checking[25],bool printred[25]){
    for(int i=0;i<iterate;i++){
        printred[i]=true;
    }
    for(int i=0;i<25;i++){
        if((i+1)%5==0 && printred[i]){
            
            cout<<"|"<<board[i]<<"|"<<endl<<endl;
            continue;
        }else if(printred[i]){
            cout<<"|"<<board[i]<<"| ";
            continue;
        }else if((i+1)%5==0){cout<<board[i]<<endl<<endl;
        continue;}
        cout<<board[i]<<"\t";
    }
    iterate++;
}
int main() {
    createboard(board);
    createboard(checking);
    int i=0;
    while(i<25){
        printboard(board,checking,printred);
        i++;
        cin.ignore();
    }
    
    return 0;

}
