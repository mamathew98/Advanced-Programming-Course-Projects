#include <iostream>
using namespace std;

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
	void Move(int Vx, int Vy, int dt, Table table){
		int dx = Vx*dt;
		int dy = Vy*dt;
		if (X + dx <= 0 || X + dx >= table.length){
			if (isEven((X + dx) / 2)){
				X = (X + dx) % table.length;
			}
			else{
				X = table.length - (X + dx) % table.length;
			}
		}
		if (Y + dy <= 0 || Y + dy >= table.width){
			if (isEven((Y + dy) / 2)){
				Y = (Y + dy) % table.width;
			}
			else{
				Y = table.width - (Y + dy) % table.width;
			}
		}
	}
	void GetBallPos(){
		cout << "(" << X << "," << Y << ")" << "\n";
	}
};

int main(){
	Table table1(7, 5);
	Ball ball_1(2, 3);
	ball_1.GetBallPos();
	ball_1.Move(2, 3, 4, table1);
	ball_1.GetBallPos();
}
