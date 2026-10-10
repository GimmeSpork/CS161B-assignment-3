/******************************************************************************
# Author:           Lucy P
# Lab:              Assignment 8
# Date:             May 31, 2021
# Description:      calculates your numeric and letter grade from given 
#                   assignment scores, midterm exam score, and final exam score.
# Input:            numAssigns as int, numScore as double, 
# Output:           decimalGrade as double, letterGrade as char, prompt as string.
# Sources:          zybooks, assignment 7 and 8 resources.
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "myutil.cpp"
using namespace std;

int main(){
  const int MAX_VALS = 20;
  double scores[MAX_VALS];
  char grade[MAX_VALS];
  int count;
  int i;

welcome();
readScores(scores, count);
calcGrade(scores, grade, count);
printList(scores, grade, count);
sort(scores, grade, count);
printList(scores, grade, count);
median(scores, count);

cout << "\nThank you for using my Parallel Arrays program!!" << endl;

return 0;

}