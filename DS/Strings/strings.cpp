// strings are included in the string header file
// first we should include the string headerfile in our programm
#include <iostream>
#include <string>    // including the string header file
#include <algorithm> //including the algorthim for the sort function,reverse function

// string is the cpp class it has some built in methods like the class has,evey variable of type string is the object of the class string, string is not the data type 
// string is dynamically typed it can increase its size /
// string has internal array which is dynamalically typed which can increase its size based on the situation,we need not to worry about the size 

// ------Difference between the character arrays and strings -----------
//   character arrays                                                                      strings

//   character arrays are static,that mean we should know                      No need to know the size in advance
                                                            //   the size of the string before declaring it ..

//  concatenation and appending are      difficult                                                                                                                  

//  Does not contain the null character                                                  Contains the null character
using namespace std;

int main()

{
  //   --------------------------Declaring the string ------------------

  //----------------- declaration 1 ---------------

  string sai;
  // syntax is string keyword and strinh name
  cout << "Enter the string   1 :   ";
  cin >> sai;          //taking input from the standard input
  cout << sai << endl; //printing input on standard output

  // --------------declaration 2 -------------

  // suppose if the string contains only the single character then we can use this syntax for declaring it
  string yamuna(5, 'y');
  // we should pass two arguments to the string name, 1st one is the length of the string and 2nd is the repeating character
  cout << yamuna << endl;

  //  ---------declaration 3 -----------

  string angajala = "saisri";
  cout << angajala << endl;

  // These are the 3 ways of declaring the strings

  // see that in the above declarations,always we taken a single word, if we want to take the sentence as a string then we should use getline function

  // -------taking whole sentence as input ----------------
  // getline function takes two arguments,cin and the string name
  // string anuradha;
  // cout << "Enter the sentence " << endl;
  // getline(cin, anuradha);
  // cout << anuradha;

  // ------string concatenation---------------

  // string concatenation can be done in two ways, 1.by addition 2.by append function
  string new_string;
  new_string = angajala + yamuna;

  cout << "new_string after concatenating the angajala and yamuna is : " << new_string << endl;
 


//  some methods of the string class 

  // ------Apppending----------------
  // appending the yamuna string to angajala

  cout << "sai and yamuna strings before appending are : " << sai << " " << yamuna << endl;
  sai.append(yamuna);
  cout << " sai string after appending with the yamuna is : " << sai << endl;

  //   --------string characters can also be acceseed like the array elements --------

  //   ------clear function ------

  // clear function is used to make the any string emmpty
  //  lets make the angajala string empty
  cout << "angajala string before clearing : " << angajala << endl;
  angajala.clear();
  cout << "angajala string after clearing : " << angajala << endl;

  //    --------------Comparing the strings ---------

  //  we use compare function to compare the two strings
  //   let us compare the strings sai and yamuna

  cout << sai.compare(yamuna) << endl; //this mean we are comparing the sai with the yamuna
  //   compare will return some integer based on the lexographic order of the strings
  // if the returned integer is zero , then the two strings are equal
  // if integer is positive that mean the argument string comes first in lexographic order
  // if integer is negative that mean the argument string comes after the comparing string

  // let us declare two strings which are equal
  string s1 = "saisri";
  string s2 = "saisri";
  cout << s1.compare(s2) << endl;

  //    -------------checking whether the string is empty or not -------------
  //  empty function is used to check whether the string is empty or not
  // as we know that the angajala string is empty,let us check it using the  empty function

  cout << angajala.empty() << endl;
  //  empty function will return true that mean 1 if the string is empty otherwise return false that mean 0

  // ------------eraing some part of the string----------------

  // erase function is used to deltete the specified part of the string
  // erase function takes two arguments, one is the index where the deletion part starts and other upto how many characters should be deleted starting from the deleting character
  string srinivas = "krishna";
  //  let us erase the sh part in the krishna
  srinivas.erase(3, 2); //here 3 is the index of the s and we should delete upto the h,so no of characteres to delete is 2,so so arguments are 3,2
  cout << srinivas << endl;

  // ---------------checking the sub string ------------------

  // "find" function is used to find whether the string is part of the given string or not
  string krishna = "krishnamurthy";
  cout << krishna.find("murthy") << endl;
  // if given argument string is part of the string, then find function will return the starting index of the string
  // counting starts from the zero , here murthy starts from 7, so find function will return 7 in this case
  // if the argument string is not the part of the parent string, then find function will return string::pos(it is the static member with the value that is equal to the highest vallue of size_t data structure)
  cout << krishna.find("reddy") << endl;

  // ----------------inserting a string into parent string ----------------
  // insert function is used to insert the argument string, in specified space
  // it takes two arguments, one is the position at which we want to insert, other is the string
  // let us insert the "angajala" in the zero position of string krishna

  krishna.insert(0, "angajala");
  cout << "krishna string after inserting the angajala is :  " << krishna << endl;

  // -------------another version of the string function ---------------

  // we can specify the number of characters from the second string that can be inserted into the first string
  // let us do that
  string sitarama = "sitarama";
  // let us insert the first 4 characters of the string angajala at the starting of the string sitarama
  sitarama.insert(0, "angajala", 4);
  cout << "sitarama string after inserting first 4 characters of angajala into it is : " << sitarama << endl;
 

  // -----------replace method-------------

  // now we will replace some part of the string with the other string , replace function is used to do that 
  string prasanna = "saiprassna";
  // now we replace the prassna in the string with the sri 
  // replace function take the 3 arguments 
  // 1.starting character of the sub string that we want to replace
  // 2.no of characters that we want to replace
  // 3.string that we want to keep in the original string 
   prasanna.replace(3,prasanna.length(),"sri");
   cout<< "the prasanna string after replacing prasanna with the sri is : " <<prasanna <<endl;



  // -------------finding the length of the string--------- 

  // length of the string can be found using the length or size function
  // let us find the length of the string krishna

  cout << "length of the string krishna is  :  " << krishna.length() << endl;
  cout << "length of the string angajala is :  " << angajala.size() << endl; //here angajala is empty string,so it length would be 0

  // ----------getting the some part of the string --------------
  // it is similar to the slicing of the string in python
  // substr is used to get slice of the string
  // substr takes two arguments, one is the index from which we want to slice, and another is the upto how many characters from the starting index we want
  // let us extract the murthy from the krishna string

  string slice = krishna.substr(15, krishna.length());
  cout << "the value of slice is : " << slice << endl;

  // ------------conveting the numerical string to numeric --------

  // for this we use the stoi(string to integer) function
  string numerical_string = "1223";
  cout << "numerical string after converting into int is  :  " << stoi(numerical_string) << endl;

  // --------converting the numerical to string ---------

  // to sting method is used to convert the numerical to the string
  int num = 23243;
  // lets add the saisri to the num after converting it into  string

  cout << "adding the saisri to num after converting into string :  " << to_string(num) + "saisri" << endl;

  // -------SORTING A STRING ----------
  // sort function is used to sort the given string
  // sort function is defined in the algorthim header file,so we must include it in the code in order to use the sorrt function
  string unsorted = "dalsadfjlasfjlsadflas";
  // let sort the unsorted string using the sort function

  // sort function takes two arguments,one is the begin of the string and other is the end of the string
  sort(unsorted.begin(), unsorted.end()); //sort function returns nothing,so do not include it in the cout function
  cout << "unsorted string after sorting is  :  " << unsorted << endl;

  // ---------------reverse function-----------
  // there is built in reverse function in the algorthim header file in c++
  // reverse function takes two arguments, one is the  begining of the iteration and other is the ending of the iteration

  // reverse function does not return any value, it reverses in place
  // lets reverse a string
  string original_str = "saisri";
  reverse(original_str.begin(), original_str.end());
  cout << "original string after reversing is  : " << original_str << endl;

  // --------------conversion of int to string-- --------------
  //  there is a built in function called to_string which converts the int to string
  // lets convert the int to string
  int num1 = 232;
  sai = to_string(num1);
  // now lets check it by adding the another string to it
  cout << "sai" + sai << endl;

  // -----------------getting the multiple words input ----------------
  // built in getline function is used to get the multiple words of input

  string multi_word_string;
  (cin, multi_word_string); 
  cout << multi_word_string << endl;
  return 0;

} 