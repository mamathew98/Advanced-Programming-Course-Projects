/*
Mohammad Naseri 9602813
Biliard Ball Move Simlator
As 2
Purpose : to simulate moves of a single ball in a biliard table that can hit the edges of tabel and
        to find coordinates of ball at the end of moving .
Algorithm : dividing dx(distace that ball goes) by table sizes to determine how many table sizes ball passes
*/

#include <iostream>
using namespace std;


//checks if x is even or not
bool isEven(int x){
	if (x % 2 == 0){ return true; }
	return false;
}

class Table{
public:
	int width;
	int length;
	Table(int x, int y){
		length = x;
		width = y;
	}
};

class Ball {
public:
	int X;
	int Y;
	Ball(int x, int y){
		X = x;
		Y = y;
	}
	//Purpose of this function is to get the ball's position after hit
	void Move(int Vx, int Vy, int dt, Table table){
		int dx = Vx*dt;
		int dy = Vy*dt;
		//if (x + distance) divided by table size is even then the new ball's position is [(x+dx)%size] if its odd [size - (X + dx) % size]
		if (isEven((X + dx) / table.length)){
			X = (X + dx) % table.length;
		}
		else{
			X = table.length - (X + dx) % table.length;
		}


		if (isEven((Y + dy) / table.width)){
			Y = (Y + dy) % table.width;
		}
		else{
			Y = table.width - (Y + dy) % table.width;
		}
	}

	void GetBallPos(){
		cout << "(" << X << "," << Y << ")" << "\n";
	}
};
int main(){
Table table(7,5);
Ball ball(2,3);
ball.GetBallPos();
ball.Move(1,2,1,table);
ball.GetBallPos();
}
