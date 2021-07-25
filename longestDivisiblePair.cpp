//Given a list of number, this program will find the longest and "pair-wise divisible" sub-set of the list, such that all of the items in the subset can be taken as pairs where the larger value of the pair is perfectly divisible by the smaller.

//Time complexity of O(n!) due to the recursive calls on all possible sublists of the input

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> //for the sort() keywork with vectors on linux (comment out for mac os)

using namespace std;


vector<int> largest_divisible_pairs(vector<int> input) {
  
  int s = input.size();
  vector<int> answer;
  
  sort(input.begin(),input.end());
  
  if(s==0 || input.at(0) == 0) { //checks to see if the list is empty or if it contains a negative value
    return answer; //returns empty vector
  }
  
  int tracker = 0;
  
  
  vector<int>completeList(s); // creates a vector with the size of the input vector

  //iterates from left to right and checks all the previous values on the left side of the current value, which is input.at(i), to see if it's divisible by the current value.
  for(int i = 0; i<s; i++) {
    
    for(int j = 0; j<i; j++) {
      if((input.at(i) % input.at(j) == 0) && (completeList.at(j)+ 1 > completeList.at(i))) {
	completeList.at(i) = completeList.at(j) + 1; //moves to the next value in the list
	if(completeList.at(i)>tracker) {
	  tracker = completeList.at(i); //updates to ensure that tracker is the max.
	}
      }
    }
  }

  
  int prev = 0; //arbitrary value for initialization
  
  for(int i = s-1; i>=0; i--) { //iterates backwards from right to left
    
    if(completeList.at(i) == tracker && (prev % input.at(i) == 0 || prev == 0))
      { 
	//pushes the current value into the answer vector if its divisible by the number ahead of it and if it's position correlates to the tracker value in the completeList.
	answer.push_back(input.at(i));
	tracker = tracker - 1;
	prev = input.at(i);
      }
    }
   
  return answer;       
}
  

string vec_to_string(vector<int> v){

  sort(v.begin(),v.end()); //sorts input vector;
  string inputString = "["; //Declaration and initialization of string to the first number in the vector passed through the parameter

  for(int i = 0; i<v.size(); i++)
    {
      if(i == v.size()-1) {
	inputString = inputString + to_string(v.at(i));
      }
      else {
	inputString = inputString + to_string(v.at(i)) +  " "; //iterates through the vector and appends the value to the new string
      }
    }
  inputString += ']';
  
  return inputString;
}

int main() {

  //https://stackoverflow.com/questions/2236197/what-is-the-easiest-way-to-initialize-a-stdvector-with-hardcoded-elements
  static const int arr[] = {28,22,7,2,8,14,24,56,24};
  vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]) ); //answer: 7, 14, 28, 56

  static const int arr2[] = {1, 16, 7, 8, 4};
  vector<int> test2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) ); //answer: 1, 4, 8, 16

  static const int arr3[] = {18, 1, 3, 6, 13, 17, 50, 42, 11, 19, 8, 43, 10, 48, 15, 35, 22, 41, 7, 30, 27, 28, 25, 4, 32, 44, 36};
  vector<int> test3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]) ); //answer: 36, 6, 3, 1, 18

  vector<int> test4;
  
  //Dynamic Programming
  cout<<"Input: "<<vec_to_string(test)<<endl;
  cout<<"Answer: "<<vec_to_string(largest_divisible_pairs(test))<<endl;


  cout<<"Input: "<<vec_to_string(test2)<<endl;
  cout<<"Answer: "<<vec_to_string(largest_divisible_pairs(test2))<<endl;


  cout<<"Input: "<<vec_to_string(test3)<<endl;
  cout<<"Answer: "<<vec_to_string(largest_divisible_pairs(test3))<<endl;


  cout<<"Input: "<<vec_to_string(test4)<<endl;
  cout<<"Answer: "<<vec_to_string(largest_divisible_pairs(test4))<<endl;
  
}
