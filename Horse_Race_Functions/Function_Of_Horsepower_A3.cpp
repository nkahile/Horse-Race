#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

const int HORSE_NUM = 5;
void run_game ( int horses , int length);
void printLine(int horseNum, int horsePosition, int len);
bool flip();

int main()
{
    int seed;
    cout<<"Please enter a random seed: ";
    cin >> seed;
    srand(seed);
    run_game(5,15);
    return 0;
}

void run_game ( int horses , int length){
    int postion[horses];
    int winner = -1
    bool keepGoing = true;
    for(int i=0;i<horses;i++){
        postion[i]=0;
    }
    while(keepGoing){
        for (int i=0; i<horses ; i++){
            if(keepGoing){
                //check if i should increase
                bool increase = flip();
                if(increase){
                    postion[i]=postion[i]+1;
                }
            }
            printLine(i,postion[i],length);
            if(postion[i]==(length-1)){
                winner=i;
                keepGoing = false;
            }
        }

        cout<< "\n\n";
    }
    cout << "Horse " << winner << " wins!" << endl;



}

void printLine(int horseNum, int horsePosition, int len){
    for(int i=0;i<len;i++){
        if(i == horsePosition){
            cout << horseNum;
        }else{
            cout<<".";
        }
    }
    cout<<endl;
}

bool flip(){
    int flip_coin = rand()%2;
    return flip_coin==1 ;
}
