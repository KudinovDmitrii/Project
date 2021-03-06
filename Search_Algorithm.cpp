#include <iostream>
#include<queue>
#include<cmath>
#include <string>
using namespace std;
queue <int> qx;
queue <int> qy;
queue <int> Qx;
queue <int> Qy;

void Q_Swap() {
	for (;!Qx.empty() && !Qy.empty();) {
		qx.push(Qx.front());
		qy.push(Qy.front());
		Qx.pop();
		Qy.pop();
	}
}

int distance(int Fx, int Fy, int x, int y) {
	return abs(Fx - x) + abs(Fy - y);
}

void poisk_shirina(int **A, int sizeX, int sizeY, int Fx, int Fy, int x, int y) {

	char **Came_From;
	Came_From = new char*[sizeX];
	for (int i = 0; i < sizeX; i++)
		Came_From[i] = new char[sizeY];

	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			Came_From[i][j] = '0';
	int t, z;
	t = x;
	z = y;
	int D = distance(Fx, Fy, x, y);
	for (;x != Fx || y != Fy;) {

		if (x + 1 < sizeX ) 
		  if(A[x + 1][y] == 0) {
			if (distance(Fx, Fy, x + 1, y) <= D) {
				qx.push(x + 1);
				qy.push(y);
				A[x + 1][y] = 2;
				Came_From[x + 1][y] = '^';
			}
			else {
				Qx.push(x + 1);
				Qy.push(y);
				A[x + 1][y] = 2;
				Came_From[x + 1][y] = '^';
			}
		  }

		if (y + 1 < sizeY )
		  if(A[x][y + 1] == 0) {
			if (distance(Fx, Fy, x, y + 1) <= D) {
				qx.push(x);
				qy.push(y + 1);
				A[x][y + 1] = 2;
				Came_From[x][y + 1] = '<';
			}
			else {
				Qx.push(x);
				Qy.push(y + 1);
				A[x][y + 1] = 2;
				Came_From[x][y + 1] = '<';
			}
		  }

		if (x - 1 >= 0 )
		  if(A[x - 1][y] == 0) {
			if (distance(Fx, Fy, x - 1, y) <= D) {
				qx.push(x - 1);
				qy.push(y);
				A[x - 1][y] = 2;
				Came_From[x - 1][y] = 'v';
			}
			else {
				Qx.push(x - 1);
				Qy.push(y);
				A[x - 1][y] = 2;
				Came_From[x - 1][y] = 'v';
			}
		  }

		if (y - 1 >= 0) 
		  if(A[x][y - 1] == 0){
			if (distance(Fx, Fy, x, y - 1) <= D) {
				qx.push(x);
				qy.push(y - 1);
				A[x][y - 1] = 2;
				Came_From[x][y - 1] = '>';
			}
			else {
				Qx.push(x);
				Qy.push(y - 1);
				A[x][y - 1] = 2;
				Came_From[x][y - 1] = '<';
			}
		  }
		if (!qx.empty() && !qy.empty()) {
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
		}
		A[x][y] = 3; // рассмотренный
		if (qx.empty() && qy.empty()) {
			Q_Swap();
			D += 2;
		}
	}



	cout << "   ";
	for (int j = 0; j < sizeY; j++) {
		cout << " " << j << " ";
	}
	cout << " Y ";

	for (int i = 0; i < sizeX; i++) {
		cout << endl;
		cout << i << "  ";
		for (int j = 0; j < sizeY; j++)
			if (i == Fx && j == Fy)
				cout << "{" << Came_From[i][j] << "}";
			else if (i == t && j == z)
				cout << "{" << "S" << "}";
			else
				cout << " " << Came_From[i][j] << " ";
	}

}

int main()
{
	int **A;
	int sizeX, sizeY;
	cout << "Type sizes" << endl;
	cin >> sizeX >> sizeY;
	A = new int*[sizeX];
	for (int i = 0; i < sizeX; i++)
		A[i] = new int[sizeY];

	// Внешний интерфейс и ввод карты
	cout << "  ";
	for (int j = 0; j < sizeY; j++) {
		cout << j << " ";
	}
	cout << "Y " << endl;
	for (int i = 0; i < sizeX; i++) {
		cout << i << " ";
		for (int j = 0; j < sizeY; j++)
			cin >> A[i][j];
	}
	cout << "X " << endl << endl;


	int Fx, Fy, x, y;
	cout << "Type Fx Fy x y " << endl;
	cin >> Fx >> Fy >> x >> y;
	poisk_shirina(A, sizeX, sizeY, Fx, Fy, x, y);



	return 0;
}
