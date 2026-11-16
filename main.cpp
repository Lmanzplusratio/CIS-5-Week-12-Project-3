#include <iostream> // Input/Output Library
#include <cstdlib> // Generating Numbers Toolbox
#include <ctime> // Dates/Time Toolbox

using std::cout;
using std::endl;

// Project 3 — Isaiah Salvatierra
// CIS 5 Week 12 · Fifty students
// Do not type scores or names into this file.

void countGrades(const int scores[], int n, int& a, int& b, int& c, int& d, int& failing) { // This void function doesn't return anything, it just completes an action for us then we call it later in main
  a = 0;                                                                                    // We are passing by reference here. This creates an alias for these so that once these actions are done, it is "saved"
  b = 0;
  c = 0;
  d = 0;
  failing = 0;
  if (n <= 0 || scores == nullptr) return;
  // TODO: for loop. Add 1 to the matching count. 
  for (int i = 0; i < n; i++ )
   if (scores[i] >= 90) 
    ++a;
   else if (scores[i] >= 80)
    ++b;
   else if (scores[i] >= 70)
    ++c;
   else if (scores[i] >= 60)
    ++d;
    else if (scores[i] < 60)
    ++failing;
}

double average(const int scores[], int n) { // Return function that will still complete an action like a void but it is returned when called
  if (n <= 0 || scores == nullptr) return 0.0;
  double sum = 0;
  for (int i = 0; i < n; i++) sum += scores[i]; // This confused me here, I tried doing a for loop using double instead of int, but we didn't need to do that because we only cared about the return of the sum being a double 
  return sum * 1.0/n;
}

void officeHours(const int scores[], int n, int* failingCount) { // Void function that is passing by pointer this time in parameter failingcount
  if (n <= 0 || scores == nullptr) return; // Conditional uses || which means "or" . Both these lines of code are just ensuring that if the failingcount is inconslusive, we exit function for that student of office hours
  // TODO: while loop. If scores[i] is under 60, print:
  for (int i = 0; i < n; i++) // Wasn't able to get a while loop for this loop
   if (scores[i] < 60) 
   { 
    cout << "Student at index " << i << " needs to come to office hours" << endl;
    if (failingCount != nullptr) *failingCount = *failingCount + 1; } // Here, we are saying that if the failigcount actually points somewhere, we are going to add one to that count for when we call it later and how many students
   
  // Student at index i needs to come to office hours.
  // If failingCount is not nullptr, write how many lines you printed through *failingCount. If it is nullptr, do not write through it.
}

int main() { // INT MAIN FUNCITON THAT WILL BE USED TO CALL ALL FUNCTIONS AND RUN THE FUNCTIONS WHENEVER WE WANT TO USE THEM IN THE ORDER
  const int N = 50;
  int scores[N];

  srand(static_cast<unsigned>(time(nullptr))); // Boiler Plate, we don't edit this function
  for (int i = 0; i < N; ++i) {
    scores[i] = rand() % 100;
  }

  for (int i = 0; i < N; ++i) {
    cout << "[" << i << "] " << scores[i] << endl;
  }

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int failing = 0;
  countGrades(scores, N, a, b, c, d, failing); // Calling this function to pass what information is has from its computation

  cout << "A: " << a << endl;
  cout << "B: " << b << endl;
  cout << "C: " << c << endl;
  cout << "D: " << d << endl;
  cout << "Failing: " << failing << endl;
  cout << "Average: " << average(scores, N) << endl; // Calling this function to return and print what was done

  int lines = 0; // Declaring Lines which will be used in the next line for the arguement
  officeHours(scores, N, &lines); // Calling this function we did passing by pointer. The &lines in the arguement here in main when we called is  
  cout << "Office hours: " << lines << endl;

  return 0;
}
