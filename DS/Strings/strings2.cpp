// in this we will look more built in methods in strings 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() 

{
        // ---------- push_back function ---------------
// this will push the single character at the end of the string 
string kittu = "kitt";
kittu.push_back('u');
cout<< kittu <<endl; 

// ---pop_back ---------------
// this will remove the last character of the string 
string gopi = "gopi";
gopi.pop_back();
cout<< gopi <<endl; 

// ------------swap method--------
// this will swap the two strings 
string sai = "saisri angajala";
string yamuna = "yamuna angajala";
cout<< "strings before swaping are : " << sai << "   " << yamuna <<endl;
sai.swap(yamuna);
cout<< "strings after swaping are : " << sai << "   " <<yamuna <<endl;  

// ----------coppy fpunction---------------/
// this is used to copy the string in the char array 
// let us copy the string into the character array
string naga = "nagaraju";
char prani[10];
naga.copy(prani,naga.length());
// coppy function takes two arguments ,one is the charater array in which we want to copy, and the no of characters that we want to copy 
// now the naga is copied into the prani 
cout<< prani  <<endl;

// now let us copy the 3 characters into the other character array 
// note that the null character is not copied into the array, so we should explictly add the null character at end 
char shiva[20];
naga.copy(shiva,3);
shiva[3] = '\n';
cout<< shiva <<endl;

// -----------find function ---------------
// find function finds whether given string or character is present in the parent string or not 
// it returns the starting index of the string or location of the character
cout << naga.find("raju") << endl;
cout<< naga.find('a') <<endl;

// we can search for the string or character in the reverse order also for this rfind is used it finds from the righr hand side 
cout << naga.rfind('a') << endl;
// from left hand side a is found at the 1st position and from the right hand side it is found at the 5th position 

     

    //  ------first occurence of the charcater in string---------------
cout <<"the first occurence of the a is : "<< naga.find_first_of('a') << endl;
// find_first_of function gives the first occurence of the character , first occurence of a is at 1

cout<< "the last occurence of the a is : " << naga.find_last_of('a') <<endl;
// find_last_of will give the last occurence of the character 

// --------substr function----------
// this function is used to grab the some part of the string that is the substring 
// it takes the either 2 or 1 positional arguments, 1st argument is the starting point from where we want the substring
// if we provide the only starting index then it will return the whole string after the starting index 
// let us look into it 
string srinu = "srinuangajala";
// suppose if we want to grab angajala from the srinu,let us use the substr to do that 
cout<< "getting the substring angajala from srinu : " <<  srinu.substr(5) <<endl;

// let us specify the starting index and the ending index of the substring 
cout<< "getting the srinu from the srinu string : " << srinu.substr(0,5) <<endl;


// ----------compare function --------------
// compare function does the same work of strcmp in char array 
string radha = "anuradha";
string Radha = "Anuradha";
string radhaA = "angajalaanuradha";
string radha2 = "anuradha";
cout<< radha.compare(radha2) <<endl;
cout<< radha.compare(radhaA) <<endl;
cout<< radhaA.compare(radha) <<endl;
cout<< radha.compare(Radha) <<endl;      

// ----------------operators on the string -------------
// 1.[]
// 2.+
// 3.= these operators can be used in string 
string saisri = "saisri angajala";
// [] it is used to acess the character from the string 
cout<< saisri[3] <<endl; 
cout<< saisri[8] <<endl;

// + is used for string contatenation 
string saisri2 = saisri + "iit ropar ";
cout<< saisri2 <<endl;
// contatenation will return the another object of the string class 

// = is used for copying one string into another string 
string saisri3;
saisri3 = saisri2;
cout<< saisri3 <<endl;

// ---------at function -----------
// at function is similar to the [],at function takes the index and returns the character at that index 
cout<< saisri.at(3) <<endl;

// --------front function------------
// front built in method returns the first character of the string 
cout<< saisri.front() <<endl;

// -----------back method-------------
// end method will return the last character of the string 
cout<< saisri.back() <<endl;

// --------------NOTE--------------
// strings are mutable in the c++ 
  return 0; 
} 