
#include <iostream>

class Person {

	int ScorePlayer{};
	std::string NamePlayer{};

public:

	Person() {};

	int GetIntScorePlayer() 
	{
		return ScorePlayer;
	}

	void GetScorePlayer() 
	{
		std::cout << ScorePlayer;
	}

	void SetScorePlayer(int ScorePlayer) 
	{
		this->ScorePlayer = ScorePlayer;
	}

	void GetNamePlayer() 
	{
		std::cout << NamePlayer;
	}

	void SetNamePlayer(std::string NamePlayer) 
	{
		this->NamePlayer = NamePlayer;
	}

};

int main()
{
	int NumberPlayer{};
	int CinScore{};
	Person Temp{};
	std::string CinName;

	std::cout << "Enter number player: ";
	std::cin >> NumberPlayer;

	std::cout << '\n';

	Person* ListPlayer = new Person[NumberPlayer];

	for (int i = 0; i < NumberPlayer; i++) 
	{
		std::cout << "Enter name player: ";
		std::cin >> CinName;
		ListPlayer[i].SetNamePlayer(CinName);

		std::cout << "Enter score " << CinName << ": ";
		std::cin >> CinScore;
		ListPlayer[i].SetScorePlayer(CinScore);

		std::cout << '\n';
	}

	//sort
	for (int i = 0; i < NumberPlayer - 1; i++) 
	{
		for (int j = 0; j < NumberPlayer - 1; j++) 
		{
			if (ListPlayer[j + 1].GetIntScorePlayer() > ListPlayer[j].GetIntScorePlayer()) 
			{
				Temp = std::move(ListPlayer[j + 1]);
				ListPlayer[j + 1] = std::move(ListPlayer[j]);
				ListPlayer[j] = std::move(Temp);
			}
		}
	}

	for (int i = 0; i < NumberPlayer; i++) 
	{
		ListPlayer[i].GetNamePlayer();
		std::cout << " ";
		ListPlayer[i].GetScorePlayer();
		std::cout << '\n';
	}

	delete[] ListPlayer;
	ListPlayer = nullptr;

	return 0;
}	