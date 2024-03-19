#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Objective: Establish an Array/or Chart that displays the runner's name, the days, the amount of miles they ran per day, the amount of miles they ran altogether, and the average miles per runner
// Objective: Parallel Coding ---> Keywords like int and string

const int num_RUNNERS = 5;
// Runners: Johnson, Samantha, Ravi, Sheila, and Ankit
const int num_DAYS = 7;
// Days: Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, and Sunday

// Establish the main variables for the Array/Chart
string runners[num_RUNNERS];
int DAILYruns[num_RUNNERS][num_DAYS];
int TOTALmiles[num_RUNNERS];
double AVGmiles[num_RUNNERS];

// Establish a function to read the provided file, Runners.txt
void READrunnersFILE(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    // Read each Runner; Expected: Johnson, Samantha, Ravi, Sheila, and Ankit
    for (int i = 0; i < num_RUNNERS; ++i) {
        file >> runners[i];
        // Read the amount of miles per day (or DAILYruns); Example: Johnson Day 1 (5), Day 2 (11), Day 3(12)...
        for (int j = 0; j < num_DAYS; ++j) {
            file >> DAILYruns[i][j];
        }
    }
    file.close();
}

// Establish a function to find the total/average miles per runner
void calTOTALandAVG() {
    // Read each Runner
    for (int i = 0; i < num_RUNNERS; ++i) {
        int total = 0;
        // Based on the amount of miles per day (or DAILYruns), calculate the total
        for (int j = 0; j < num_DAYS; ++j) {
            total += DAILYruns[i][j];
        }
        TOTALmiles[i] = total; // Store the total miles for each runner
        AVGmiles[i] = static_cast<double>(total) / num_DAYS; // Calculate the average
    }
}

// Display the Outputs
void OUTPUTresults() {
    // Print the column: Runner
    cout << setw(15) << "Runner";
    // Print the column: Day # (1 - 7)
    for (int i = 0; i < num_DAYS; ++i) {
        cout << setw(10) << "Day " << i + 1;
    }
    // Print the column: Total Miles and Average Mile
    cout << setw(15) << "Total Miles" << setw(20) << "Average Miles" << endl;

    for (int i = 0; i < num_RUNNERS; ++i) {
        // For the column: Runner, it will list the 5 provided runners
        cout << setw(15) << runners[i];
        for (int j = 0; j < num_DAYS; ++j) {
            // For column: Day # (1 - 7), it will list the amount of miles that each runner ran on that day
            cout << setw(10) << DAILYruns[i][j];
        }
        // For column: Total/Average Miles, it will list the total/average for each runner
        cout << setw(15) << TOTALmiles[i] << setw(20) << fixed << setprecision(2) << AVGmiles[i] << endl;
    }
}

int main() {
    string filename = "Runners.txt";
    READrunnersFILE(filename);
    calTOTALandAVG();
    OUTPUTresults();
    return 0;
}

// Expectation: The Terminal will display the array/chart of the runner, day, and miles (includes total and average)