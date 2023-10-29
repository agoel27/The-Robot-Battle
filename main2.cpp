// One special thing about a tournament is that, other than the champion, other participants will not get the exact rank. 
// Instead, they will only be viewed as "top k", for k = 1, 2, 4, 8, 16, ... 

// Assume there are 𝑛 participants in total, where 𝑛 is a power of 2. The strength of each participant, the 𝑖-th robot, is noted as 𝑥𝑖, which is an integer in range [1,10^9]. 
// Assume your own robot is always shown up in this list as the first one (i.e., 𝑥1 is the strength of your robot ). 
// All 𝑥𝑖 values are distinct so there wouldn't be a tie.

// You decide to hack the system before the competition, so that you could rearrange the schedule, and decide opponents for all competitions. 
// What the best rank your robot can achieve, i.e., find the smallest value of 𝑘, such that your robot could rank top 𝑘
//  in the tournament, where 𝑘 is also a power of 2.

// Input
// The first line of the input is an integer 𝑛
// , which is the number of robots in the competition. 𝑛
//  is guaranteed to be a power of 2.

// The second line of the input contains 𝑛
//  integers. The 𝑖-th integer 𝑥𝑖 is the strength of the 𝑖-th robot in the competition. Your robot is always the first one in the list, so its strength is 𝑥1.

// Output
// The output contains a single integer, 𝑘, which means "top 𝑘" is the best rank that Monte can achieve, if they carefully rearrange the tournament schedule. 
// 𝑘 must be a power of 2.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int vSize = 0;
    cin >> vSize;
    if(vSize==1) {
        cout << 1;
    }

    int power = 0;
    cin >> power;

    vector<int> v(vSize);
    v[0] = power;
    for(int i=1; i < vSize; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int numRoboLessPower = 0;
    for(int i=0; i < vSize; i++) {
        if(power > v[i]) {
            numRoboLessPower++;
        }
        else{
            break;
        }
    }

    int numRoundsWon = 0;
    while(numRoboLessPower-1 != 0) {
        numRoboLessPower = (numRoboLessPower-1)/2;
        numRoundsWon++;
    }
    numRoundsWon++;

    cout << vSize/pow(2, numRoundsWon);
}