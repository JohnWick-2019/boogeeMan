
#include <iostream>

using namespace std;

void FilOutCicl();//функция заполняет пространство вокруг коробля 0
/*
void ShowGameBoard1();//показывает игровое поле для первого игрока
void ShowGameBoard2();//показывает игровое поле для второго игрока
*/


void ShowGameBoard1withShips();
void ShowGameBoard1withoutShips();
void ShowGameBoard2withShips();
void ShowGameBoard2withoutShips();

void ShowGameBoardForFirstPlayer();
void ShowGameBoardForSecondPlayer();

void FirstGamer();//заполнение поля первого игрока короблями
void SecondGamer();//заполнение поля второго игрока короблями


//заполнение короблями поля первого игрока
void FirstFillOutShips1();						  
void FirstFillOutShips2();  
void FirstFillOutShips3();
void FirstFillOutShips4();
//заполнение короблями поля второго игрока
void SecondFillOutShips1();
void SecondFillOutShips2();
void SecondFillOutShips3();
void SecondFillOutShips4();
//ходы игроков
void GameFirstUser();
void GameSecondUser();

int const ROW = 10;
int const COL = 10;

char choseUserMenu;// переменная в меню switch
char userChosePosition;// переменная выбора положения корабля
char fartherNearer;// положение корабля "дальше" / "ближе" начальной точки
char chekSwitch; // счетчик для меню выбора switch
int userRow, userCol;// переменные для выбора строки и столбца при заполнении поля кораблями
int ships = 20;// счетчик количества кораблей. Считается по количеству палуб
int coordX, coordY; //координаты хода игрока
int chek = 0;//счетчик
bool flag=true;//игровой счетчик

char gameBoard1[ROW][COL], gameBoard2[ROW][COL];

int main()
{
	setlocale(LC_ALL, "rus");

	
    
	
	
	//заполнение поля кораблями первым игроком
	ShowGameBoardForFirstPlayer();
	FirstGamer();

//заполнение поля кораблями вторым игроком
	ShowGameBoardForSecondPlayer();
	SecondGamer();

	//игра
	
	do
	{
		GameFirstUser();
		GameSecondUser();

	} while (flag);

			
		
	
	
   
	
	  
}
void FirstGamer() {
	cout << "Первый игрок" << endl;
	cout << endl;
	cout << "Введите однопалубные корабли" << endl;
	cout << endl;
	FirstFillOutShips1();
	chek = 0;
	cout << "Введите двупалубные корабли корабли" << endl;
	cout << endl;
	FirstFillOutShips2();
	chek = 0;
	cout << "Введите трехпалубные корабли" << endl;
	cout << endl;
	FirstFillOutShips3();
	chek = 0;
	cout << "Введите четырехпалубный корабль" << endl;
	cout << endl;
	FirstFillOutShips4();
}
void SecondGamer() {
	cout << "Второй игрок" << endl;
	cout << endl;
	cout << "Введите однопалубные корабли" << endl;
	cout << endl;
	SecondFillOutShips1();
	chek = 0;
	cout << "Введите двупалубные корабли корабли" << endl;
	cout << endl;
	SecondFillOutShips2();
	chek = 0;
	cout << "Введите трехпалубные корабли" << endl;
	cout << endl;
	SecondFillOutShips3();
	chek = 0;
	cout << "Введите четырехпалубный корабль" << endl;
	cout << endl;
	SecondFillOutShips4();
}
/*
void ShowGameBoard1()
{
	system("cls");
	cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < ROW; i++)
	{

		cout << i;
		for (int j = 0; j < COL; j++)
		{

				cout << gameBoard1[i][j] << "|";





		}
		cout << endl;
	}
	cout << endl;

	cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < ROW; i++)
	{

		cout << i;
		for (int j = 0; j < COL; j++)
		{

			if (gameBoard2[i][j] == 'r')
			{
				cout << ' ' << "|";
			}
			else
			{
				cout << gameBoard2[i][j] << "|";
			}



		}
		cout << endl;
	}
}
void ShowGameBoard2() {
	system("cls");
	cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < ROW; i++)
	{

		cout << i;
		for (int j = 0; j < COL; j++)
		{

		cout << gameBoard2[i][j] << "|";

		}
		cout << endl;
	}
	cout << endl;

	cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < ROW; i++)
	{

		cout << i;
		for (int j = 0; j < COL; j++)
		{

			if (gameBoard1[i][j] == 's')
			{
				cout << ' ' << "|";
			}
			else
			{
				cout << gameBoard1[i][j] << "|";
			}



		}
		cout << endl;
	}
}

*/


//Заполнение первого игрока

void FirstFillOutShips1()
{
	do
	{
		cout << "Введите координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;

		if (gameBoard1[userRow][userCol] !='s' )
		{
			gameBoard1[userRow][userCol] = 's';

			ShowGameBoardForFirstPlayer();
			
			chek++;
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	
	} while (chek != 4);
}
void FirstFillOutShips2()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard1[userRow][userCol] != 's')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';
					gameBoard1[userRow][userCol + 1] = 's';
					chek++;
				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';
					gameBoard1[userRow][userCol - 1] = 's';
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard1[userRow][userCol] = 's';
						gameBoard1[userRow][userCol + 1] = 's';
						chek++;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard1[userRow][userCol] = 's';
						gameBoard1[userRow][userCol - 1] = 's';
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';
					gameBoard1[userRow + 1][userCol] = 's';
					chek++;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';
					gameBoard1[userRow - 1][userCol] = 's';
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard1[userRow][userCol] = 's';
						gameBoard1[userRow - 1][userCol] = 's';
						chek++;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard1[userRow][userCol] = 's';
						gameBoard1[userRow + 1][userCol] = 's';
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForFirstPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek !=3);

}
void FirstFillOutShips3()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard1[userRow][userCol] != 's')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow][userCol + i] = 's';
					}
					chek++;

				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow][userCol - i] = 's';
					}
					chek++;

				}
				else if (userCol <= 1)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow][userCol + i] = 's';
					}
					chek++;
				}
				else if (userCol >= 8)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow][userCol - i] = 's';
					}
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 3; i++)
						{
							gameBoard1[userRow][userCol + i] = 's';
						}
						chek++;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 3; i++)
						{
							gameBoard1[userRow][userCol - i] = 's';
						}
						chek++;
					}
				}

            }
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow + i][userCol] = 's';
					}
					chek++;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow - i][userCol] = 's';
					}
					chek++;
				}
				else if (userRow <= 1)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow + i][userCol] = 's';
					}
					chek++;
				}
				else if (userRow >= 8)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow - i][userCol] = 's';
					}
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 3; i++)
						{
							gameBoard1[userRow - i][userCol] = 's';
						}
						chek++;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 3; i++)
						{
							gameBoard1[userRow + i][userCol] = 's';
						}
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForFirstPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek != 2);
}
void FirstFillOutShips4()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard1[userRow][userCol] != 's')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow][userCol + i] = 's';
					}
					chek = false;

				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow][userCol - i] = 's';
					}
					chek = false;

				}
				else if (userCol<=2)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow][userCol + i] = 's';
					}
					chek = false;
				}
				else if (userCol>=7)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 3; i++)
					{
						gameBoard1[userRow][userCol - i] = 's';
					}
					chek = false;
				}
				else 
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 4; i++)
						{
							gameBoard1[userRow][userCol + i] = 's';
						}
						chek = false;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 3; i++)
						{
							gameBoard1[userRow][userCol - i] = 's';
						}
						chek = false;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow + i][userCol] = 's';
					}
					chek = false;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow - i][userCol] = 's';
					}
					chek = false;
				}
				else if (userRow<=2)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow + i][userCol] = 's';
					}
					chek = false;
				}
				else if (userRow>=7)
				{
					gameBoard1[userRow][userCol] = 's';

					for (int i = 0; i < 4; i++)
					{
						gameBoard1[userRow - i][userCol] = 's';
					}
					chek = false;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 4; i++)
						{
							gameBoard1[userRow - i][userCol] = 's';
						}
						chek = false;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard1[userRow][userCol] = 's';

						for (int i = 0; i < 4; i++)
						{
							gameBoard1[userRow + i][userCol] = 's';
						}
						chek = false;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForFirstPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek);

}

//заполнение вторым игроком

void SecondFillOutShips1()
{
    do
	{
		cout << "Введите координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;

		if (gameBoard2[userRow][userCol] != 'r')
		{
			gameBoard2[userRow][userCol] = 'r';

			ShowGameBoardForSecondPlayer();
			
			chek++;
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek != 4);
}
void SecondFillOutShips2()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard2[userRow][userCol] != 'r')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';
					gameBoard2[userRow][userCol + 1] = 'r';
					chek++;
				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';
					gameBoard2[userRow][userCol - 1] = 'r';
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard2[userRow][userCol] = 'r';
						gameBoard2[userRow][userCol + 1] = 'r';
						chek++;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard2[userRow][userCol] = 'r';
						gameBoard2[userRow][userCol - 1] = 'r';
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';
					gameBoard2[userRow + 1][userCol] = 'r';
					chek++;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';
					gameBoard2[userRow - 1][userCol] = 'r';
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard2[userRow][userCol] = 'r';
						gameBoard2[userRow - 1][userCol] = 'r';
						chek++;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard2[userRow][userCol] = 'r';
						gameBoard2[userRow + 1][userCol] = 'r';
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForSecondPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek != 3);
}
void SecondFillOutShips3()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard2[userRow][userCol] != 'r')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow][userCol + i] = 'r';
					}
					chek++;

				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow][userCol - i] = 'r';
					}
					chek++;

				}
				else if (userCol<=1)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow][userCol + i] = 'r';
					}
					chek++;
				}
				else if (userCol>=8)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow][userCol - i] = 'r';
					}
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 3; i++)
						{
							gameBoard2[userRow][userCol + i] = 'r';
						}
						chek++;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 3; i++)
						{
							gameBoard2[userRow][userCol - i] = 'r';
						}
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow + i][userCol] = 'r';
					}
					chek++;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow - i][userCol] = 'r';
					}
					chek++;
				}
				else if (userRow<=1)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow + i][userCol] = 'r';
					}
					chek++;
				}
				else if (userRow>=8)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow - i][userCol] = 'r';
					}
					chek++;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 3; i++)
						{
							gameBoard2[userRow - i][userCol] = 'r';
						}
						chek++;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 3; i++)
						{
							gameBoard2[userRow + i][userCol] = 'r';
						}
						chek++;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForSecondPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek != 2);
}
void SecondFillOutShips4()
{
	do
	{
		cout << "Введите начальные координаты коробля..." << endl;
		cout << "Введите номер строки.." << endl;
		cin >> userRow; cout << endl;
		cout << "Введите номер столбца" << endl;
		cin >> userCol; cout << endl;
		cout << "Как будет располагаться корабль?" << endl;
		cout << "'-' Горизонтально." << endl;
		cout << "'|' Вертикально.";
		cin >> userChosePosition;

		if (gameBoard2[userRow][userCol] != 'r')
		{
			if (userChosePosition == '-')
			{
				if (userCol == 0)//если выбрал 0 столбец, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow][userCol + i] = 'r';
					}
					chek = false;

				}
				else if (userCol == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow][userCol - i] = 'r';
					}
					chek = false;

				}
				else if (userCol<=2)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow][userCol + i] = 'r';
					}
					chek = false;
				}
				else if (userCol>=7)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 3; i++)
					{
						gameBoard2[userRow][userCol - i] = 'r';
					}
					chek = false;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "d. Дальше начальной точки" << endl;
					cout << "b. Ближе начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'd')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 4; i++)
						{
							gameBoard2[userRow][userCol + i] = 'r';
						}
						chek = false;
					}
					else if (fartherNearer == 'b')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 3; i++)
						{
							gameBoard2[userRow][userCol - i] = 'r';
						}
						chek = false;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else if (userChosePosition == '|')
			{
				if (userRow == 0)//если выбрал 0 строку, можно только прибавлять
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow + i][userCol] = 'r';
					}
					chek = false;
				}
				else if (userRow == 9)// при 9 столбце можно только отнимать
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow - i][userCol] = 'r';
					}
					chek = false;
				}
				else if (userRow<=2)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow + i][userCol] = 'r';
					}
					chek = false;
				}
				else if (userRow>=7)
				{
					gameBoard2[userRow][userCol] = 'r';

					for (int i = 0; i < 4; i++)
					{
						gameBoard2[userRow - i][userCol] = 'r';
					}
					chek = false;
				}
				else
				{
					cout << "Как разместить корабль?" << endl;
					cout << "v. Выше начальной точки" << endl;
					cout << "n. Ниже начальной точки" << endl;
					cin >> fartherNearer; cout << endl;

					if (fartherNearer == 'v')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 4; i++)
						{
							gameBoard2[userRow - i][userCol] = 'r';
						}
						chek = false;
					}
					else if (fartherNearer == 'n')
					{
						gameBoard2[userRow][userCol] = 'r';

						for (int i = 0; i < 4; i++)
						{
							gameBoard2[userRow + i][userCol] = 'r';
						}
						chek = false;
					}
					else
					{
						cout << "Неверный ввод..." << endl;
					}
				}
			}
			else
			{
				cout << "Введены неверные координаты";
			}

			ShowGameBoardForSecondPlayer();
			
		}
		else
		{
			cout << "Здесь уже есть корабль" << endl;
		}
	} while (chek);
}
//игра первого игрока
void GameFirstUser() {
	
	do
	{
		ShowGameBoardForFirstPlayer();
		
		cout << "ПЕРВЫЙ ИГРОК ХОДИТ..." << endl;
		cout << endl;

		
		cout << "Введите первую координату (от 0 до 9): ";
		cin >> coordX;

		cout << "Введите вторую координату (от 0 до 9): ";
		cin >> coordY;

		if (gameBoard2[coordX][coordY] == 'r')
		{
			gameBoard2[coordX][coordY] = 'x';
			ships--;
		}
		else
		{
			gameBoard2[coordX][coordY] = 'O';
			break;
		}
		ShowGameBoardForFirstPlayer();

		
		
	} while (gameBoard2[coordX][coordY]=='x');
}

//игра второго инрока
void GameSecondUser() {

	do
	{
		ShowGameBoardForSecondPlayer();
		
		cout << "ВТОРОЙ ИГРОК ХОДИТ..." << endl;
		cout << endl;

		cout << "Введите первую координату (от 0 до 9): ";
		cin >> coordX;

		cout << "Введите вторую координату (от 0 до 9): ";
		cin >> coordY;

		if (gameBoard1[coordX][coordY] == 's')
		{
			gameBoard1[coordX][coordY] = 'x';
			ships--;
		}
		else
		{
			gameBoard1[coordX][coordY] = 'O';
			break;
		}
		ShowGameBoardForSecondPlayer();
		
	} while (gameBoard1[coordX][coordY] == 'x');
}

//заполнение 0 вокруг коробля
 void FilOutCicl() {
	for (int i = userRow - 1; i <= 3; i++)
	{
		for (int j = userCol - 1; j < 3; j++)
		{
			gameBoard1[i][j] = '0';

			if (gameBoard1[i][j] == 's')
			{
				continue;
			}
		}
	}
}

//игровое поле первого игрока с короблями
 void ShowGameBoard1withShips()
 {
	 system("cls");
	 cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	 for (int i = 0; i < ROW; i++)
	 {

		 cout << i;
		 for (int j = 0; j < COL; j++)
		 {

			 cout << gameBoard1[i][j] << "|";





		 }
		 cout << endl;
	 }
 }

 //игровое поле первого игрока без короблей
 void ShowGameBoard1withoutShips()
 {
	 cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	 for (int i = 0; i < ROW; i++)
	 {

		 cout << i;
		 for (int j = 0; j < COL; j++)
		 {

			 if (gameBoard1[i][j] == 's')
			 {
				 cout << ' ' << "|";
			 }
			 else
			 {
				 cout << gameBoard1[i][j] << "|";
			 }



		 }
		 cout << endl;
	 }
 }

 //игровое поле 2-го игрока с короблями
 void ShowGameBoard2withShips()
 {
	 system("cls");
	 cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	 for (int i = 0; i < ROW; i++)
	 {

		 cout << i;
		 for (int j = 0; j < COL; j++)
		 {

			 cout << gameBoard2[i][j] << "|";

		 }
		 cout << endl;
	 }
 }

 //игровое поле 2-го игрока без короблей
 void ShowGameBoard2withoutShips()
 {
	 cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
	 for (int i = 0; i < ROW; i++)
	 {

		 cout << i;
		 for (int j = 0; j < COL; j++)
		 {

			 if (gameBoard2[i][j] == 'r')
			 {
				 cout << ' ' << "|";
			 }
			 else
			 {
				 cout << gameBoard2[i][j] << "|";
			 }



		 }
		 cout << endl;
	 }
 }

 //игровое поля в игре для 1-го игрока
 void ShowGameBoardForFirstPlayer()
 {
	 ShowGameBoard1withShips();
	 cout << endl;
	 ShowGameBoard2withoutShips();
 }

 //игровое поля в игре для 2-го игрока
 void ShowGameBoardForSecondPlayer()
 {
	 ShowGameBoard2withShips();
	 cout << endl;
	 ShowGameBoard1withoutShips();
 }
/*void ShowMenu()
{
	cout << "Выберите тип корабля:" << endl;
	cout << endl;
	cout << "1. Однопалубный." << endl;
	cout << endl;
	cout << "2. Двухпалубный." << endl;
	cout << endl;
	cout << "3. Трехпалубный." << endl;
	cout << endl;
	cout << "4. Четырехпалубный." << endl;
}*/
/*
for (int i = 0; i < 4; i++)
{
	cout << "Введите координаты коробля..." << endl;
	cout << "Введите номер строки.." << endl;
	cin >> userRow; cout << endl;
	cout << "Введите номер столбца" << endl;
	cin >> userCol; cout << endl;

	gameBoard[userRow][userCol] = 'x';
	ShowGameBoard();

}
*/
/*
#include <iostream>
using namespace std;

const int SIZE = 10;

char gameBoard[SIZE][SIZE];
int tanks = 5;//количество танков
int step = 0;// количество ходов
int coordX, coordY;
void GameInit();
void CreatTanks();
void ShowGameBoard();

int main()
{
	setlocale(LC_ALL, "rus");

	GameInit();
	CreatTanks();


	//TODOнаписать проверку правильности ввода координат
	//и стрельбу в одну точку


	do
	{
		ShowGameBoard();
		cout << "Введите первую координату (от 0 до 9): ";
		cin >> coordX;

		cout << "Введите вторую координату (от 0 до 9): ";
		cin >> coordY;

		if (gameBoard[coordX][coordY] == 'T')
		{
			gameBoard[coordX][coordY] = 'X';
			tanks--;
			step++;
		}
		else
		{
			gameBoard[coordX][coordY] = 'O';
			step++;
		}
		ShowGameBoard();

	} while (tanks != 0);

	cout << "Вы подбили 5 танков за " << step << "шагов!";
}

void GameInit()
{
	//присваиваем каждому элементу пробел
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			gameBoard[i][i] = ' ';
		}
	}
}
void CreatTanks()
{
	gameBoard[0][0] = 'T';
	gameBoard[1][1] = 'T';
	gameBoard[2][2] = 'T';
	gameBoard[3][3] = 'T';
	gameBoard[4][4] = 'T';
}
void ShowGameBoard()
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		cout << i;
		for (int j = 0; j < SIZE; j++)
		{

			if (gameBoard[i][j] == 'T')
			{
				cout << ' ' << "|";
			}
			else
			{
				cout << gameBoard[i][j] << "|";
			}

		}
		cout << endl;
	}

}
*/

