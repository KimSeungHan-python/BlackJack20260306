#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL))); // 실행할때마다 다른 난수 생성을 위해서
	vector <int>Player;
	vector <int>Computer;
	int array[11] = {};
	int Pnum;
	int Cnum;
	int Ptotal = 0;
	int Ctotal = 0;


	for (int i = 0; i < 3; i++)
	{
		int temp = 0;
		Pnum = rand() % 10 + 1;
		Cnum = rand() % 10 + 1;
		array[Pnum]++;
		array[Cnum]++;
		if (array[Pnum] == 5)
		{
			temp = Pnum;
			array[Pnum]--;
			while(Pnum != temp)
			{
				Pnum = rand() % 10 + 1;
			}
		}
		if (array[Cnum] == 5)
		{
			temp = Cnum;
			array[Cnum]--;
			while (Cnum != temp)
			{
				Cnum = rand() % 10 + 1;
			}
		}
		Player.push_back(Pnum);
		Computer.push_back(Cnum);
	}

	for (auto player : Player)
	{
		cout << "Player card: " << player << endl;
		Ptotal += player;
	}
	for (auto computer : Computer)
	{
		cout << "Computer card: " << computer << endl;
		Ctotal += computer;
	}

	if (Ptotal < 22 && Ctotal < 22)
	{
		if(Ptotal > Ctotal)
		{
			cout << "Player wins!" << endl;
		}
		else if (Ptotal < Ctotal)
		{
			cout << "Computer wins!" << endl;
		}
		else
		{
			cout << "Player wins!" << endl;
		}
	}
	else if (Ptotal > 21 && Ctotal > 21)
	{
		cout << "Player wins" << endl;
	}
	else if (Ptotal > 21 && Ctotal < 22)
	{
		cout << "Computer wins!" << endl;
	}
	else if (Ptotal < 22 && Ctotal > 21)
	{
		cout << "Player wins!" << endl;
	}


	return 0;
}