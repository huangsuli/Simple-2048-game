#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib> 
#include <time.h>
using namespace std;


void move (char m, vector< vector<int> > &board) {
   int position = -1;
   switch(m) {
        case 'w':
            for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 4; j ++) {
                    if(board[j][i] != 0) {
                        if(position != -1 && board[j][i] == board[position][i]) {
                            board[position][i] *= 2;
                            board[j][i] = 0;
                            position = -1;
                        }
                        else {
                            position = j;
                        }
                    }
                } 
                position = -1; 
            }
            for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 4; j++) {
                    if(board[j][i] == 0) {
                        if(position == -1) position = j;
                    }
                    else if(position != -1) {
                        board[position][i] = board[j][i];
                        board[j][i] = 0;
                        position = j;
                    }
                }
                position = -1;
            }
            break;
        case 'a':
            for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 4; j ++) {
                    if(board[i][j] != 0) {
                       
                        if(position != -1 && board[i][j] == board[i][position]) {
                            board[i][position] *= 2;
                            board[i][j] = 0;
                            position = -1;
                        }
                        else {
                            position = j;
                        }
                    }
                } 
                position = -1; 
            }
            for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 4; j++) {
                    if(board[i][j] == 0) {
                        if(position == -1) position = j;
                    }
                    else if(position != -1) {
                        board[i][position] = board[i][j];
                        board[i][j] = 0;
                        position = j;
                    }
                }
                position = -1;
            }
            break;
        case 's':
             for(int i = 0; i < 4; i ++) {
                for(int j = 3; j >= 0; j --) {
                    if(board[j][i] != 0) {
                        if(position != -1 && board[j][i] == board[position][i]) {
                            board[position][i] *= 2;
                            board[j][i] = 0;
                            position = -1;
                        }
                        else {
                            position = j;
                        }
                    }
                } 
                position = -1; 
            }
            for(int i = 0; i < 4; i ++) {
                for(int j = 3; j >= 0; j --) {
                    if(board[j][i] == 0) {
                        if(position == -1) position = j;
                    }
                    else if(position != -1) {
                        board[position][i] = board[j][i];
                        board[j][i] = 0;
                        position = j;
                    }
                }
                position = -1;
            }
            break;
        case 'd':
           for(int i = 0; i < 4; i ++) {
                for(int j = 3; j >= 0; j --) {
                    if(board[i][j] != 0) {
                        if(position != -1  && board[i][j] == board[i][position]) {
                            board[i][position] *= 2;
                            board[i][j] = 0;
                            position = -1;
                        }
                        else {
                            position = j;
                        }
                    }
                } 
                position = -1; 
            }
            for(int i = 0; i < 4; i ++) {
                for(int j = 3; j >= 0; j --) {
                    if(board[i][j] == 0) {
                        if(position == -1) position = j;
                    }
                    else if(position != -1) {
                        board[i][position] = board[i][j];
                        board[i][j] = 0;
                        position = j;
                    }
                }
                position = -1;
            }
            break;
   }
}

void spawnNumber(vector< vector<int> > &board) {
    srand (time(NULL));
    int ver_position = rand() % 4;
    int hor_position = rand() % 4;
    int insert_number = ((rand() % 2) == 0) ? 2 : 4;
    if(board[ver_position][hor_position] != 0) {
        while(board[ver_position][hor_position] != 0) {
            ver_position = rand() % 4;
            hor_position = rand() % 4;
        }

    }
    board[ver_position][hor_position] = insert_number;
}

void show(vector< vector<int> > board) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] < 10) cout << board[i][j] << "    ";
            else if(board[i][j] < 100) cout << board[i][j] << "   ";
            else if(board[i][j] < 1000) cout << board[i][j] << "  ";
            else cout << board[i][j] << ' ';
        }
        cout << "\n\n";
    }
}

int checkFull(vector< vector<int> > board) {
    int num;
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j] == 0) num ++;
        }
    }
    if(num == 0) return 1;
    else if(num <= 8) return 2;
    else return 3;
}


bool isSame(vector< vector<int> > board1,vector< vector<int> > board2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board1[i][j] != board2[i][j]) return false;
        }
    }
    return true;
}

bool checkLost(vector< vector<int> > board) {
    vector< vector<int> > copy = board;
    move('w', copy);
    if(!isSame(copy,board)) return false;
    
    copy = board;
    move('a', copy);
    if(!isSame(copy,board)) return false;

    copy = board;
    move('s', copy);
    if(!isSame(copy,board)) return false;

    copy = board;
    move('d', copy);
    if(!isSame(copy,board)) return false;

    return true;
}


int main() {
    string line;
    vector<int> temp(4,0);
    vector< vector<int> > board(4,temp);
    string welcom_text = "Welcom to 2048 game, use \'w\', \'a\', \'s\', \'d\' to move the game board.";
    cout << welcom_text << endl; 
    spawnNumber(board);
    spawnNumber(board);
    show(board);
    
    /*board[0][0] = 8;
    board[1][0] = 4;
    board[2][0] = 4;
    board[3][0] = 2;
    move('w',board);
    show(board);*/

    while(getline(cin,line)) {
        if(line[0] != 'w' && line[0] != 'a' && line[0] != 's' && line[0] != 'd') {
            cout << "Please input \'w\', \'a\', \'s\', \'d\' to move the game board" << "\n\n";
            continue;
        }
        move(line[0], board);
        if(checkFull(board) != 1) spawnNumber(board);
        if(checkFull(board) == 3) spawnNumber(board);
        show(board);
        if(checkLost(board)) {
            cout << "You Lose!" << endl;
            break;
        }
    }
}