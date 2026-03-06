#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string DrawShape(int CardNumber)// 1 ~13
{
	if (CardNumber == 11)
	{
		return "J";
	}
	else if (CardNumber == 12)
	{
		return "Q";
	}
	else if (CardNumber == 13)
	{
		return "K";
	}
	else if (CardNumber == 1)
	{
		return "A";
	}
	else
	{
		return to_string(CardNumber);
	}
}


int main()
{
	//동적배열
	// Data Structure
	//정적배열
	//똑같은 카드가 나오면 안됨.
	srand(static_cast<unsigned int>(time(NULL))); // 실행할때마다 다른 난수 생성을 위해서
	int Cards[52] = { 0, };
	string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };
	for (int i = 0; i < 52; i++)
	{
		Cards[i] = i;
	}	
	for (int i = 0; i < 52; i++)
	{
		int FirstIndex = rand() % 52;
		int SecondIndex = rand() % 52;
		int temp = Cards[FirstIndex];
		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = temp;
	}

	// Deal
	int ComputerCard[3] = { 0, };	
	int PlayerCard[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		ComputerCard[i] = Cards[i];
		PlayerCard[i] = Cards[i + 3];
	}

	// Compare
	int ComputerTotal[3] = { 0 };
	int PlayerTotal[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		ComputerTotal[i] += (ComputerCard[i] % 13 + 1 > 10) ? 10 : (ComputerCard[i] % 13 + 1);
		PlayerTotal[i] += (PlayerCard[i] % 13 + 1 > 10) ? 10 : (PlayerCard[i] % 13 + 1);
	}

	int TotalComputerScore = ComputerTotal[0] + ComputerTotal[1] + ComputerTotal[2];
	int TotalPlayerScore = PlayerTotal[0] + PlayerTotal[1] + PlayerTotal[2];

	// Draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else 
	{
		cout << "Player Win" << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Computer Card: " << CardType[ComputerCard[i] / 13] << " " << DrawShape(ComputerCard[i] % 13 + 1) << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Player Card: " << CardType[PlayerCard[i] / 13] << " " << DrawShape(PlayerCard[i] % 13 + 1) << endl;
	}

	// 조건식 ? A(true) : B(false)

	//카드 섞기 Shuffle
	//임의(Random)로 두개 선택해서 교환

	

	//주사위(100면체 주사위)
	//서버에서 실행
	//진짜로 난수(하드웨어)


	return -0;
}





















//int main() //Entry Point
//{
//	srand(static_cast<unsigned int>(time(NULL))); // 실행할때마다 다른 난수 생성을 위해서
//	vector <int>Player;
//	vector <int>Computer;
//	int array[11] = {};
//	int Pnum;
//	int Cnum;
//	int Ptotal = 0;
//	int Ctotal = 0;
//
//
//	for (int i = 0; i < 3; i++)
//	{
//		int temp = 0;
//		Pnum = rand() % 10 + 1;
//		Cnum = rand() % 10 + 1;
//		array[Pnum]++;
//		array[Cnum]++;
//		if (array[Pnum] == 5)
//		{
//			temp = Pnum;
//			array[Pnum]--;
//			while(Pnum != temp)
//			{
//				Pnum = rand() % 10 + 1;
//			}
//		}
//		if (array[Cnum] == 5)
//		{
//			temp = Cnum;
//			array[Cnum]--;
//			while (Cnum != temp)
//			{
//				Cnum = rand() % 10 + 1;
//			}
//		}
//		Player.push_back(Pnum);
//		Computer.push_back(Cnum);
//	}
//
//	for (auto player : Player)
//	{
//		cout << "Player card: " << player << endl;
//		Ptotal += player;
//	}
//	for (auto computer : Computer)
//	{
//		cout << "Computer card: " << computer << endl;
//		Ctotal += computer;
//	}
//
//	if (Ptotal < 22 && Ctotal < 22)
//	{
//		if(Ptotal > Ctotal)
//		{
//			cout << "Player wins!" << endl;
//		}
//		else if (Ptotal < Ctotal)
//		{
//			cout << "Computer wins!" << endl;
//		}
//		else
//		{
//			cout << "Player wins!" << endl;
//		}
//	}
//	else if (Ptotal > 21 && Ctotal > 21)
//	{
//		cout << "Player wins" << endl;
//	}
//	else if (Ptotal > 21 && Ctotal < 22)
//	{
//		cout << "Computer wins!" << endl;
//	}
//	else if (Ptotal < 22 && Ctotal > 21)
//	{
//		cout << "Player wins!" << endl;
//	}
//
//
//	return 0;
//}