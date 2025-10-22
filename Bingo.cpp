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
bool checkforbingo(bool printred[25]){
    //vertical
    for(int i=0;i<5;i++){
        if(printred[4+i]&&printred[9+i]&&printred[14+i]&&printred[19+i]&&printred[0+i])return true;
    }
    //horizontal
    for(int i=0;i<5;i++){
        if(printred[5*i]&&printred[5*(i+1)]&&printred[5*(i+2)]&&printred[5*(i+3)]&&printred[5*(i+4)])return true;
    }
    //diagonally
    bool a[5];
    for(int i=0;i<5;i++){
        if(printred[i+(6*i)])a[i]=true;
    }
    
}
void printboard(int board[25],int checking[25],bool printred[25]){
    int random;
    
        random =rand()%25;
        while(printred[random]){
            random =rand()%25;
        }
        printred[random]=true;
    
    for(int i=0;i<25;i++){
        if((i+1)%5==0 && printred[i]){
            
            cout<<"|"<<board[i]<<"|"<<endl<<endl;
            continue;
        }else if(printred[i]){
            cout<<"|"<<board[i]<<"|";
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
