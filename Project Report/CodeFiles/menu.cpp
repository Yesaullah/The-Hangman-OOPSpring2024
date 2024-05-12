#include <SFML/Graphics.hpp>
#include "menu.h" // Include the header file to access the Menu class
#include <iostream> // Include necessary headers

using namespace std;
using namespace sf;
Menu::Menu(float width, float height) {
    if (!font.loadFromFile("durbank.ttf")) {
        std::cout << "Cannot open font" << std::endl;
    }

    menu[0].setFont(font);
    menu[0].setFillColor(Color::Red);
    menu[0].setString("PLAY");
    menu[0].setPosition(Vector2f(width / 2, height / 4 * 2));

    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("OPTIONS");
    menu[1].setPosition(Vector2f(width / 2, height / 4 * 2.5));

    menu[2].setFont(font);
    menu[2].setFillColor(Color::White);
    menu[2].setString("EXIT");
    menu[2].setPosition(Vector2f(width / 2, height / 4 * 3));
}

Menu::~Menu() {}

void Menu::Draw(sf::RenderWindow& window) {
    for (int i = 0; i < Max_Number_Of_Items; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if (Index - 1 >= 0) {
        menu[Index].setFillColor(Color::White);
        Index--;
        menu[Index].setFillColor(Color::Red);
    }
}

void Menu::MoveDown() {
    if (Index + 1 < Max_Number_Of_Items) {
        menu[Index].setFillColor(Color::White);
        Index++;
        menu[Index].setFillColor(Color::Red);
    }
}

