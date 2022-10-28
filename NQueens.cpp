#include "stdafx.h"
#include <iostream>

using namespace std;

int board[20][20];

int ClearBoard(int board[20][20]){
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			board[i][j] = 0;
		}
	}
}

bool CheckCell(int board[20][20], int row, int col, int size){
	for (int i = 0; i < size; i++){
		if (board[i][col] == 1){return false;}
	}
	for (int j = 0; j < size; j++){
		if (board[row][j] == 1){ return false; }
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if ((row - i) == (col - j)){
				if (board[i][j] == 1){ return false; }
			}
		}
	}
	return true;
}


bool putQueen(int board[20][20], int col, int size){
	if (col >= size){
		return true; printout(board, size);
	}
	int i = 0;
	for (i; i < size; i++){
		if (CheckCell(board, i, col, size)){
			board[i][col] = 1;
			if (CheckCell(board, i, col + 1, size) == true){ return true; }
			board[i][col] = 0;
		}
	}
	return false;
}

void printout(int board[20][20], int size){
	for (int y = 0; y < size; y++){
		for (int x = 0; x < size; x++){
			cout << board[x][y] << "  ";
		}
		cout << "\n";
	}
}

int main(){
	int board_size;
	cin >> board_size;
	ClearBoard(board);
	putQueen(board, 0, board_size);


}