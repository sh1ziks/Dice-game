#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

int main()
{
	setlocale(LC_ALL, "ru");
	ContextSettings settings;
	settings.antialiasingLevel = 12;

	RenderWindow window(VideoMode(1366, 768), "Dice Game", Style::Close, settings);
	window.setVerticalSyncEnabled(true);

	Vector2f coord(window.getSize());

	int playerScore = 0, botScore = 0, playerResult = 0, botResult = 0;
	srand(time(NULL));
	Clock clock;

	Font font1;
	font1.loadFromFile("Font\\PressStart2P.ttf");

	Text titleText("Dice game", font1, 40);
	titleText.setFillColor(Color(0, 0, 0));
	titleText.setPosition(coord.x - 850, coord.y - 748);

	Text scoreText("Player Score - ", font1, 25);
	scoreText.setFillColor(Color(0, 0, 0));
	scoreText.setPosition(coord.x - 1100, coord.y - 695);

	Text managementText("1 - Roll the Dice\t2 - Restart\tEscape - Exit", font1, 20);
	managementText.setFillColor(Color(0, 0, 0));
	managementText.setPosition(coord.x - 1200, coord.y - 650);

	Text playerText("Player move: ", font1, 20);
	playerText.setFillColor(Color(0, 0, 0));
	playerText.setPosition(coord.x - 1225, coord.y - 600);

	Text botText("Bot move: ", font1, 20);
	botText.setFillColor(Color(0, 0, 0));
	botText.setPosition(coord.x - 350, coord.y - 600);

	Text winner("", font1, 20);
	winner.setFillColor(Color(0, 0, 0));
	winner.setPosition(coord.x - 750, coord.y - 400);

	bool playerMove = false, botMove = false;
	bool changeWinner = false, winnerHasBeen = false;


	//ќгромный, ужасный кусок кода, где все варианты кубиков:(
	CircleShape dot1(50);
	dot1.setFillColor(Color(255, 255, 255));
	dot1.setOrigin(dot1.getRadius(), dot1.getRadius());

	CircleShape dot2(50);
	dot2.setFillColor(Color(255, 255, 255));
	dot2.setOrigin(dot2.getRadius(), dot2.getRadius());

	CircleShape dot3(50);
	dot3.setFillColor(Color(255, 255, 255));
	dot3.setOrigin(dot3.getRadius(), dot3.getRadius());

	CircleShape dot4(50);
	dot4.setFillColor(Color(255, 255, 255));
	dot4.setOrigin(dot4.getRadius(), dot4.getRadius());

	CircleShape dot5(50);
	dot5.setFillColor(Color(255, 255, 255));
	dot5.setOrigin(dot5.getRadius(), dot5.getRadius());

	CircleShape dot6(50);
	dot6.setFillColor(Color(255, 255, 255));
	dot6.setOrigin(dot6.getRadius(), dot6.getRadius());

	RectangleShape squarePlayer(Vector2f(400, 400));
	squarePlayer.setFillColor(Color(255, 0, 0));
	squarePlayer.setOrigin(squarePlayer.getSize().x / 2, squarePlayer.getSize().y / 2);
	squarePlayer.setPosition(coord.x - 1100, coord.y - 350);

	bool cube1 = false;
	bool cube2 = false;
	bool cube3 = false;
	bool cube4 = false;
	bool cube5 = false;
	bool cube6 = false;


	RectangleShape squareBot(Vector2f(400, 400));
	squareBot.setFillColor(Color(255, 0, 0));
	squareBot.setOrigin(squareBot.getSize().x / 2, squareBot.getSize().y / 2);
	squareBot.setPosition(coord.x - 250, coord.y - 350);

	CircleShape dot1bot(50);
	dot1bot.setFillColor(Color(255, 255, 255));
	dot1bot.setOrigin(dot1bot.getRadius(), dot1bot.getRadius());

	CircleShape dot2bot(50);
	dot2bot.setFillColor(Color(255, 255, 255));
	dot2bot.setOrigin(dot2bot.getRadius(), dot2bot.getRadius());

	CircleShape dot3bot(50);
	dot3bot.setFillColor(Color(255, 255, 255));
	dot3bot.setOrigin(dot3bot.getRadius(), dot3bot.getRadius());

	CircleShape dot4bot(50);
	dot4bot.setFillColor(Color(255, 255, 255));
	dot4bot.setOrigin(dot4bot.getRadius(), dot4bot.getRadius());

	CircleShape dot5bot(50);
	dot5bot.setFillColor(Color(255, 255, 255));
	dot5bot.setOrigin(dot5bot.getRadius(), dot5bot.getRadius());

	CircleShape dot6bot(50);
	dot6bot.setFillColor(Color(255, 255, 255));
	dot6bot.setOrigin(dot6bot.getRadius(), dot6bot.getRadius());

	bool cube1Bot = false;
	bool cube2Bot = false;
	bool cube3Bot = false;
	bool cube4Bot = false;
	bool cube5Bot = false;
	bool cube6Bot = false;


	while (window.isOpen())
	{
		Event event;

		Time botMoveTime;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Num1:
					if (!playerMove && !winnerHasBeen)
					{
						playerResult = ((rand() % 12) / 2) + 1;
						playerMove = true;
						changeWinner = true;
						Time botMoveTime = clock.restart();

						switch (playerResult)
						{
						case 1:
							dot1.setPosition(squarePlayer.getPosition().x, squarePlayer.getPosition().y);

							cube1 = true;
							break;

						case 2:
							dot1.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y - 100);
							dot2.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y + 100);

							cube2 = true;
							break;

						case 3:
							dot1.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y + 100);
							dot2.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y - 100);
							dot3.setPosition(squarePlayer.getPosition().x, squarePlayer.getPosition().y);

							cube3 = true;
							break;

						case 4:
							dot1.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y - 100);
							dot2.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y - 100);
							dot3.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y + 100);
							dot4.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y + 100);

							cube4 = true;
							break;

						case 5:
							dot1.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y - 100);
							dot2.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y - 100);
							dot3.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y + 100);
							dot4.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y + 100);
							dot5.setPosition(squarePlayer.getPosition().x, squarePlayer.getPosition().y);

							cube5 = true;
							break;

						case 6:
							dot1.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y - 115);
							dot2.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y - 115);
							dot3.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y);
							dot4.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y);
							dot5.setPosition(squarePlayer.getPosition().x - 100, squarePlayer.getPosition().y + 115);
							dot6.setPosition(squarePlayer.getPosition().x + 100, squarePlayer.getPosition().y + 115);

							cube6 = true;
							break;
						}
					}
					break;


				case Keyboard::Num2:
					playerMove = false; botMove = false;

					if ((playerScore == 5) || (botScore == 5))
					{
						winnerHasBeen = false;
						playerScore = 0; 
						botScore = 0;
					}

					cube1 = false;
					cube2 = false;
					cube3 = false;
					cube4 = false;
					cube5 = false;
					cube6 = false;

					cube1Bot = false;
					cube2Bot = false;
					cube3Bot = false;
					cube4Bot = false;
					cube5Bot = false;
					cube6Bot = false;
				}
			}
		}

		if (playerMove && !botMove)// && botMoveTime.asSeconds() > 2)
		{
			botResult = ((rand() % 36) / 6) + 1;
			botMove = true;

			switch (botResult)
			{
			case 1:
				dot1bot.setPosition(squareBot.getPosition().x, squareBot.getPosition().y);

				cube1Bot = true;
				break;

			case 2:
				dot1bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y - 100);
				dot2bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y + 100);

				cube2Bot = true;
				break;

			case 3:
				dot1bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y + 100);
				dot2bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y - 100);
				dot3bot.setPosition(squareBot.getPosition().x, squareBot.getPosition().y);

				cube3Bot = true;
				break;

			case 4:
				dot1bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y - 100);
				dot2bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y - 100);
				dot3bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y + 100);
				dot4bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y + 100);

				cube4Bot = true;
				break;

			case 5:
				dot1bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y - 100);
				dot2bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y - 100);
				dot3bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y + 100);
				dot4bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y + 100);
				dot5bot.setPosition(squareBot.getPosition().x, squareBot.getPosition().y);

				cube5Bot = true;
				break;

			case 6:
				dot1bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y - 115);
				dot2bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y - 115);
				dot3bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y);
				dot4bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y);
				dot5bot.setPosition(squareBot.getPosition().x - 100, squareBot.getPosition().y + 115);
				dot6bot.setPosition(squareBot.getPosition().x + 100, squareBot.getPosition().y + 115);

				cube6Bot = true;
				break;
			}

		}

		std::ostringstream playerScoreString, botScoreString;
		playerScoreString << playerScore; botScoreString << botScore;
		scoreText.setString("Player score - " + playerScoreString.str() + "\tBot score - " + botScoreString.str());


		window.clear(Color(240, 240, 240));
		window.draw(titleText);
		window.draw(scoreText);
		window.draw(managementText);

		if (playerMove && botMove)
		{
			//¬арианты отрисовки кубиков игрока
			if (cube1)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(playerText);
			}

			if (cube2)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(dot2);
				window.draw(playerText);
			}

			if (cube3)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(dot2);
				window.draw(dot3);
				window.draw(playerText);
			}

			if (cube4)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(dot2);
				window.draw(dot3);
				window.draw(dot4);
				window.draw(playerText);
			}

			if (cube5)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(dot2);
				window.draw(dot3);
				window.draw(dot4);
				window.draw(dot5);
				window.draw(playerText);
			}

			if (cube6)
			{
				window.draw(squarePlayer);
				window.draw(dot1);
				window.draw(dot2);
				window.draw(dot3);
				window.draw(dot4);
				window.draw(dot5);
				window.draw(dot6);
				window.draw(playerText);
			}

			//¬арианты отрисовки кубиков бота
			if (cube1Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(botText);
			}

			if (cube2Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(dot2bot);
				window.draw(botText);
			}

			if (cube3Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(dot2bot);
				window.draw(dot3bot);
				window.draw(botText);
			}

			if (cube4Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(dot2bot);
				window.draw(dot3bot);
				window.draw(dot4bot);
				window.draw(botText);
			}

			if (cube5Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(dot2bot);
				window.draw(dot3bot);
				window.draw(dot4bot);
				window.draw(dot5bot);
				window.draw(botText);
			}

			if (cube6Bot)
			{
				window.draw(squareBot);
				window.draw(dot1bot);
				window.draw(dot2bot);
				window.draw(dot3bot);
				window.draw(dot4bot);
				window.draw(dot5bot);
				window.draw(dot6bot);
				window.draw(botText);
			}

			//ќбъ€вление победител€

			if (playerResult > botResult && changeWinner)
			{
				winner.setPosition(coord.x - 775, coord.y - 400);
				winner.setScale(1, 1);
				winner.setString("Player win!");
				++playerScore;
			}

			else if (playerResult < botResult && changeWinner)
			{
				winner.setPosition(coord.x - 750, coord.y - 400);
				winner.setScale(1, 1);
				winner.setString("Bot win!");
				++botScore;
			}

			else if (playerResult == botResult && changeWinner)
			{
				winner.setPosition(coord.x - 700, coord.y - 400);
				winner.setScale(1, 1);
				winner.setString("Draw");
			}

			playerResult = 0;
			botResult = 0;

			window.draw(winner);
			changeWinner = false;
		}

		if ((playerScore == 5) || (botScore == 5))
		{
			playerMove = false; botMove = false;
			winnerHasBeen = true;
			winner.setScale(3, 3);
			winner.setPosition(coord.x - 950, coord.y - 400);

			window.draw(winner);
		}

		window.display();
	}
}