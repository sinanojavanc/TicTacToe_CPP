#include <iostream>
#include <cstdlib>
using namespace std;

int myarray[3][3] = {0};
bool turn = true; //true for X . false for O

void ViewTable(int winer) {
 	int blocknum = 1;
 	string xstr = "\033[36mX\033[0m";
 	string ostr = "\033[31mO\033[0m";
	
 	if (winer == 1)
	    	xstr = "\033[32mX\033[0m";
 	else if (winer == 2)
	    	ostr = "\033[32mO\033[0m"; 
	    
    	cout << "*******************************\n";

    	for (int y = 0; y < 3; y++) {
         	for (int j = 0; j < 3; j++) {
            	for (int x = 0; x < 3; x++) {
                	cout << "|    ";
                	if (j == 1) {
                     	switch (myarray[x][y]) {
                        	case 0: cout << blocknum; break;
                       	case 1: cout << xstr; break;
                        	case 2: cout << ostr; break;
                   		}
                    	blocknum++;
                   		cout << "    ";
                	} else {
                   		cout << "     ";
               	}
            	}
            	cout << "|\n";
        	}
        	cout << "*******************************\n";
    	}
    	if (winer != 0)
    		cout << "\033[32m" << (winer==1 ? "X" : "O") << "\033[0m Win the game\n";
}

bool ResetBoard() {
 	cout << "u wana play again? [ Y / N ] ";
 	char reset;
 	cin >> reset;
 	if (reset == 'n' || reset == 'N'){
	 	exit(0);
  	}
    	for (int y = 0; y < 3; y++)
        	for (int x = 0; x < 3; x++)
            	myarray[x][y] = 0;
}

bool CheckDraw(){
 	for(int x=0 ; x<3 ; x++)
 		for(int y=0 ; y<3 ; y++)
		 	if(myarray[x][y]==0)
		 	 	return 0;
	return 1;
}

int CheckWinner() {
	   	//   check Rows
    	for (int y = 0; y < 3; y++)
        	if (myarray[0][y] == myarray[1][y] &&
		    myarray[1][y] == myarray[2][y] &&
		    myarray[0][y] != 0)
            	return myarray[0][y];

    		//	check Columns
    	for (int x = 0; x < 3; x++)
        	if (myarray[x][0] == myarray[x][1] &&
		    myarray[x][1] == myarray[x][2] &&
		    myarray[x][0] != 0)
            	return myarray[x][0];

  		//	check Qatars
    	if (myarray[0][0] == myarray[1][1] &&
	    myarray[1][1] == myarray[2][2] &&
	    myarray[0][0] != 0)
        	return myarray[0][0];
    	if (myarray[2][0] == myarray[1][1] &&
	    myarray[1][1] == myarray[0][2] &&
	    myarray[1][1] != 0)
        	return myarray[1][1];

    return 0;
}

int main() {
    	while (true) {
    		system("cls");
    		
    		int winner = CheckWinner();
        	ViewTable(winner);
        	if (winner != 0)
		 	if (ResetBoard())
			  	continue;
		
		if(CheckDraw()){
		 	cout << "Game is Drawn\n";
		 	system("pause");
		 	if (ResetBoard())
			 	continue;
		}
			
        	
        	cout << (turn ? " X turn.\n" : " O turn.\n");
        	
        	int pos;
        	cout << "which block u wana take? (1-9): ";
        	cin >> pos;
        	if (pos < 1 || pos > 9) {
            	cout << "Invalid choice!\n";
            	system("pause");
            	continue;
        	}

        	pos--; // make it 0–8
        	int x = pos % 3;
        	int y = pos / 3;

        	if (myarray[x][y] != 0) {
            	cout << "That block is already taken!\n";
            	system("pause");
            	continue;
        	}
        	
        	myarray[x][y] = turn ? 1 : 2;
        	turn = !turn;
    	}
    	return 0;
}