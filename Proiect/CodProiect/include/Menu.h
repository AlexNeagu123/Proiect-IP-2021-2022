//#pragma once
//#include "SFML/Graphics.hpp"
//#include <bits/stdc++.h>
//
//#define MAX_NUMBER_OF_ITEMS 3
//
//int selectedItemIndex;
//sf::Font font;
//sf::Text menu[MAX_NUMBER_OF_ITEMS];
//
//void Meniu(float width, float height)
//{
//    if (!font.loadFromFile("Fonts/arial.ttf"))
//    {
//        std::cout << "Error - load font from file";
//    }
//
//
//    menu[0].setFont(font);
//    menu[0].setColor(sf::Color::Red);
//    menu[0].setString("Creeaza");
//    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
//
//    menu[1].setFont(font);
//    menu[1].setColor(sf::Color::White);
//    menu[1].setString("Informatii");
//    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
//
//    menu[2].setFont(font);
//    menu[2].setColor(sf::Color::White);
//    menu[2].setString("Exit");
//    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
//
//    selectedItemIndex = 0;
//}
//
//void meniuDraw(sf::RenderWindow &window)
//{
//    CreazaDiagrama.drawTo(window);
//    Info.drawTo(window);
//    Exit.drawTo(window);
//}



//class Menu
//{
//public:
//	Menu(float width, float height);
//	~Menu();
//
//	void draw(sf::RenderWindow &window);
//	void MoveUp();
//	void MoveDown();
//	int GetPressedItem() { return selectedItemIndex; }
//
//private:
//	int selectedItemIndex;
//	sf::Font font;
//	sf::Text menu[MAX_NUMBER_OF_ITEMS];
//
//};
