#include <iostream>
#include <vector>
#include <algorithm> // for std::shuffle
#include <random>
#include<string>
using namespace std;// for std::mt19937 and std::random_device
int board[25];
int checking[25];
int iterate=0;
string print;
void createboard(int board[]) {
    // Step 1: Initialize the array with values 1 to 25
    std::vector<int> numbers;
    for (int i = 1; i <= 25; ++i) {
        numbers.push_back(i);
    }
    std::random_device rd;             
    std::mt19937 g(rd());            
    std::shuffle(numbers.begin(), numbers.end(), g);
    for(int i=0;i<25;i++){
        board[i]=numbers[i];
    }
}
void printboard(int board[25],int checking[25]){
    for(int i=1;i<26;i++){
        print=to_string(board[i-1]);
        if(i%5==0){
            system("Color 0A");
            cout<<print<<endl<<endl;
            continue;
        }
        cout<<board[i-1]<<"\t";
    }
    iterate++;
}
int main() {
    // Write C++ code here
    createboard(board);
    createboard(checking);
    printboard(board,checking);
    
    return 0;
}