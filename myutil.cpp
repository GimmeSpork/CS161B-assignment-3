#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//display function prototypes
void welcome();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grade[], int count);
void printList(double scores[], char grade[], int count);
void sort(double scores[], char grade[], int count);

double median(double scores[], int count);
int main();

//constant int declaration
const int MAX_VAL = 20;
//start of bulk code
//welcome function
void welcome(){
    cout << "Welcome to my Parallel Arrays program!" << endl;
    cout << "Please enter the list of scores (-1 to end input)" << endl;
    cout << "Valid scores are between 0 and 4 inclusive." << endl;
    cout << endl;
}

//readScores function to read scores
void readScores(double scores[], int &count){

    count = 0;

    readDouble("Score: ", scores[count]);
    while(scores[count] != -1){
        if(scores[count] <= 4 && scores[count] >= 0){
            readDouble("Score: ", scores[count]);
            ++count;
        }else{
            cout << "Invalid score! Please try again!" << endl;
            readDouble("Score: ", scores[count]);
            ++count;
        }
    }
}

//read double function
//called every time a double needs to be read
void readDouble(string prompt, double &num){

    cout << prompt;
    cin >> num;
    while(!cin){
        cout << "Invalid score! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Score: ";
        cin >> num;
    }
    cin.ignore(10, '\n');
}

//calc grade function, gives grade array chars to store
void calcGrade(double scores[], char grade[], int count){
    int i;

    for (i = 0; i < count; ++i){
        if (scores[i] > 3.3 && scores[i] <= 4.0){
            grade[i] = 'A';
        }
        else if (scores[i] > 2.7 && scores[i] <= 3.3){
            grade[i] = 'B';
        }
        else if (scores[i] > 1.9 && scores[i] <= 2.7){
            grade[i] = 'C';
        }
        else if (scores[i] > 1.1 && scores[i] <= 1.9){
            grade[i] = 'D';
        }
        else if (scores[i] > 0.0 && scores[i] <= 1.1){
            grade[i] = 'F';
        }
    }
}

//print list function for printing list
//called both times we print list
void printList(double scores[], char grade[], int count){
    int i;

    cout << "The list of scores and their grades are:" << endl;
    for(i = 0; i < count; ++i){
        cout << scores[i] << " " << grade[i] << endl;
    }
}

//sort function, sorts the grades into smallest to largest
void sort(double scores[], char grade[], int count){
    int i;
    int j;
    int minVal;

    for (i = 0; i < count -1; ++i){
        minVal = i;
        for (j = i + 1; j < count; ++j){
            if (scores[j] < scores[minVal]){
                minVal = j;
            }
        }
        if (minVal != i){
            scores[minVal] = scores[i];
            grade[minVal] = grade[i];
        }
    }
}

//median function
//this function will calculate the median score and return it
double median(double scores[], int count){
    double middle;

    //set decimal places to 0.00

    for (int i = 0; i < count; ++i){
        if((count % 2) != 0){
            middle = scores[i-(count - 1 / 2)];
            return middle;
        }else{
            middle = scores[i - count / 2];
            return middle;
        }
    }
}



