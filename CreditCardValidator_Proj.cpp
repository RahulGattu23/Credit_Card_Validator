/******
This program is on a credit card validator using Luhn's algorithm
***
Name: 	 Rahul Gattu Nandakumar
College: National Institute of Technology, Warangal
Year: 	 B.Tech III Year
******/


#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;


//String check function
bool isNumberString(string st) {
	
	for (int i=0; i<st.length(); i++) {
		if (st[i] < '0' || st[i] > '9')
			return false;
	}
	return true;
}



//Validate function
bool isValid (string ss) {
	/*
	Starting from the back
	*/
	int len = ss.length();
	if (len < 16 || len > 16) return false;
	int sum=0;
	
	for (int i= len-1; i >= 0; i--) {
		
		int my_int = ss[i] - 48;
		
		//if even
		if (i % 2 == 0) {
			my_int *= 2;
			if (my_int > 9)
				my_int = (my_int / 10) + (my_int % 10);
			
			sum += my_int;
		}
		
		//if odd
		else {
			sum += my_int;
		}
	}
	
	if (sum % 10 == 0) return true;
	return false;
}


int main() {
	
	string ccnumber;
	
	cout << "You can enter 'exit' anytime to quit. " << endl;
	
	while (true) {
		
		cout << "Please enter your Credit card number to validate: " << endl;
		cin >> ccnumber;
		
		if (ccnumber == "exit") 
			break;	
		
		//we check if every digit entered is an 'integer'. If not, return false and ask to reenter.
		else if (!isNumberString(ccnumber)){
			cout << "Incorrect card number entered. Please try again. " << endl;
			break;
		}
		
		
		//Validation
		isValid(ccnumber) ? cout << "Credit Card is VALID! " << endl : cout << "Credit Card INVALID! " << endl;
	
		continue;	
	}
	
	return 0;	
}
