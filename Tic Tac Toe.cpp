#include <iostream>
#include <cstdlib>
using namespace std;

int myarray[3][3] = {0};
bool isXturn = true;

void ViewTable(int winer) {
	int blocknum = 0;
	string xstr = "\033[36mX\033[0m";
	string ostr = "\033[31mO\033[0m";
	
	if (winer == 1)
	    xstr = "\033[32mX\033[0m";
	else if (winer == 2)
	    ostr = "\033[32mO\033[0m"; 
	    
    	cout << "*************\n";
    	for (int y = 0; y < 3; y++) {
        	for (int x = 0; x < 3; x++) {
            	cout << "| ";
            	blocknum++;
            	switch (myarray[x][y]) {
                	case 0: cout << blocknum; break;
                	case 1: cout << xstr; break;
                	case 2: cout << ostr; break;
                	
            	}
            	cout << " ";
            	
        	}	
        	cout << "|\n*************\n";
    	}
}

int CheckWinner() {
	   	//   check Rows
    	for (int y = 0; y < 3; y++)
        	if (myarray[0][y] == myarray[1][y] && myarray[1][y] == myarray[2][y] && myarray[0][y] != 0)
            	return myarray[0][y];

    		//	check Columns
    	for (int x = 0; x < 3; x++)
        	if (myarray[x][0] == myarray[x][1] && myarray[x][1] == myarray[x][2] && myarray[x][0] != 0)
            	return myarray[x][0];

  		//	check Qatars
    	if (myarray[0][0] == myarray[1][1] && myarray[1][1] == myarray[2][2] && myarray[0][0] != 0)
        	return myarray[0][0];
    	if (myarray[2][0] == myarray[1][1] && myarray[1][1] == myarray[0][2] && myarray[1][1] != 0)
        	return myarray[1][1];

    return 0;
}

int main() {
    	while (true) {
    		system("cls");
        	ViewTable(CheckWhoIsWinner());
        	if (CheckWhoIsWinner() != 0)
			break;
        	int pos;
        	
        	isXturn ? cout<<" X turn.\n" : cout<<" O turn.\n";
        	
        	cout << "which block u wana take? (1-9): ";
        	cin >> pos;

        	if (pos < 1 || pos > 9) {
            	cout << "Invalid choice!\n";
            	system("pause");
            	continue;
        	}

        	pos--; // make 0–8
        	int x = pos % 3;
        	int y = pos / 3;

        	if (myarray[x][y] != 0) {
            	cout << "That block is already taken!\n";
            	system("pause");
            	continue;
        	}
		if (isXturn){
		 	myarray[x][y] = 1;
		 	isXturn = !isXturn;
		} else {
		 	myarray[x][y] = 2;
		 	isXturn = !isXturn;
		}
		

        	
    	}

    	return 0;
}