#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Elevator
{
    public:

    vector<int> FloorHistory = {0};
    
    struct Node {
       int floor;
       struct Node *next;
    };
    
    struct Floor* start = NULL;
    void add(int new_floor) {
       struct Floor* new_floor = (struct Floor*) malloc(sizeof(struct Floor));
       next_floor->floor = new_floor;
       next_floor->next = start;
       start = new_node;
    }
    
    
    void InputFloor(int currentF, vector<int>FloorHistory){
        vector<int> newDestinations = {};
        cout << "\nEnter destination floor: \n" << endl;
        int *goToFloor = new int;
        cin >> *goToFloor;
        add(*goToFloor);
        int nextFloor = -1;
        while(nextFloor != 0){
            cout << "\nEnter next destination floor or enter '0' to start elevator \n" << endl;
            cin >> nextFloor;
            add(nextFloor);
        }
        ChangeFloors(currentF, FloorHistory, newDestinations);
    }

    void ChangeFloors(int current, vector<int> FloorHistory, vector<int> newDestinations){
        for(int e = 0; e < newDestinations.size() - 1; e++){
            int floorDiff = newDestinations[e] - current;
            int s = 1;
                if(floorDiff < 0){
                    s = -1;
                }
            
            for(int f = FloorHistory.back(); f != newDestinations[e] && f <= 100 && f >= 0; f = f + s){
                if(f == 101){
                    newDestinations[e] = 100;
                    f = 100;
                    puts("You have reached the top floor.");
                }
                if(f <= 1){
                    f = 1;
                    puts("You are on the ground floor.");
                }
                FloorHistory.insert(FloorHistory.end(), f + s);
                cout << "\nYou are on floor: " << FloorHistory.back() << endl;
            }
            current = newDestinations[e];
        }
        InputFloor(current, FloorHistory);
    }
};


int main()
{
    Elevator E;
    E.InputFloor(E.FloorHistory.back(), E.FloorHistory);
    return 0;
}
