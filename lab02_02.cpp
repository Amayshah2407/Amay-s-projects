// Student Name: Amay Shah 
// Student Number: 20780897
// SYDE 121 02 Assignment 02
// File name: Lab03_02
// I hereby declare that this code, submitted for credit for this course. 
// SYDE 121 is a product of my own efforts. This code solution has not been plagariazed from other sources. 
// Project: Connection of distance fallen and gravitation. 
// Purpose: Determine how much an object would fall under the force of gravity for every second till 20 seconds and then find out time it takes for an object to fall to the 
// ground from a particular distance, in this case 15000 m. 
// Due date: 3rd October, 2018, Wednesday. 

#include <iostream>
#include <iomanip>
using namespace std;

double GRAVITATIONAL_CONSTANT = 9.80665;
// defining the value of the gravitation constant initally which will be used later. 
int main() {
    double total_dist, previous_dist = 0;
    cout << fixed << "Time, Distance during one time interval, Total distance (in m)" << endl;
    
    for (int t = 0; t <= 20; t++) {
        total_dist = (0.5 * GRAVITATIONAL_CONSTANT * t * t); // calculating the total distance through the formula provided, using the constant already defined. 
        cout << setprecision(3) << t << ", " << total_dist - previous_dist << ", " << total_dist << endl; // total distance - previous distance gives distance in that period of time.
        previous_dist = total_dist;
    }
    
    cout << "\n===========================================\n" << endl;
    
    double t = 0, dist_to_ground = 15000;
    
    while (dist_to_ground >= 0) // creating a loop to keep finding distance from ground for every second interval.
        {
        total_dist = (0.5 * GRAVITATIONAL_CONSTANT * t * t);
        dist_to_ground = 15000 - total_dist; // calculating the distance from ground at each time period. 
        
        if (dist_to_ground < 0)
            break;
        else {
            cout << "For time = " << setprecision(1) << t << ", distance to ground is = " << setprecision(3) << dist_to_ground << "." << endl;
            
            if (dist_to_ground > 500) // check the time for each 0.1 of a second when value of distance is less than 500 m. 
                t += 1;
            else
                t += 0.1;
        }
    }
    
    cout << "Time for the ball to reach ground ≃ " << setprecision(1) << t - 0.1 << " seconds." << endl;
    
    return 0;
}
