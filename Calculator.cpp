#include <iostream>
#include <string>
#include <limits>
using namespace std;

void userInput();
void addition();
void subtraction();
void multiplication();
void division();
void historyDisplay();
void pointerDisplay();

struct userCalcu{
	float firstNum, secondNum, answer;
	char operation;
	string userString;
};
char history, address;
int counter;

userCalcu userArray[11];
int main (){

char exit;

do{
	system("cls");
	cout << "----- Calculator ----";
	cout <<"\n\n Enter your problem: \n";
	userInput();
		
	switch (userArray[0].operation){
		case '+':
			addition();
			cout << "= " << userArray[0].answer;
			break;
		case '-':
			subtraction();
			cout << "= " << userArray[0].answer;
			break;
		case '*':
			multiplication();
			cout << "= " << userArray[0].answer;
			break;
		case '/':
			if (userArray[0].secondNum == 0 ){
			cout << "= Undefined";
			}
			else {
			division();
			cout << "= " << userArray[0].answer;
			}
			break;
		default: 
			cout << "Invalid operator.";
}
    
	for (int i = 10; i > 0; i--){
		userArray[i].firstNum = userArray[i-1].firstNum;
		userArray[i].operation = userArray[i-1].operation;
		userArray[i].secondNum = userArray[i-1].secondNum;
		userArray[i].answer = userArray[i-1].answer;
	}
	
	counter += 1;
	if(counter > 9){
		counter = 9;
	}

	cout << "\n\nShow History? [Y/N]: ";
	cin >> history;
	if (history == 'Y' || history == 'y'){
		historyDisplay();
	
	cout << "\n\nShow Memory Address? [Y/N]\n\n";
    cin >> address;
        if (address == 'Y' || address == 'y'){
            pointerDisplay();
        }
	}
	cout << "\n\nExit? [Y/N]: ";
	cin >> exit;
	if (exit == 'Y' || exit == 'y')
	{
	return 0;
	}
}
while(exit != 'Y' && exit != 'y');
}

void userInput(){
	while (!(cin >> userArray[0].firstNum >> userArray[0].operation >> userArray[0].secondNum)){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
        cout << "Invalid input. Please try again. \n\n";
    };
}

void addition(){
	userArray[0].answer = userArray[0].firstNum + userArray[0].secondNum;	
}

void subtraction(){
	userArray[0].answer = userArray[0].firstNum - userArray[0].secondNum;	
}

void multiplication(){
	userArray[0].answer = userArray[0].firstNum * userArray[0].secondNum;	
}

void division(){
	userArray[0].answer = userArray[0].firstNum / userArray[0].secondNum;	
}

void historyDisplay(){
	cout << "\n";
	for (int i = 1; i < counter+1; i++){
		userArray[i].userString = to_string(userArray[i].firstNum) + " " + (userArray[i].operation) + " " + to_string(userArray[i].secondNum) + " = " + to_string(userArray[i].answer);
		cout << "\n" << userArray[i].userString;
	}
}

void pointerDisplay(){
    string *ptr;
	ptr = &userArray[0].userString;
	for (int i = 1; i < counter+1; i++){
		cout << "\n" << userArray[i].userString << " : " << ptr + 1;
    }
    
}