#include "Gamescreen.h"
#include <iostream>

Gamescreen::Gamescreen(float width, float height) {
    if (!font.loadFromFile("durbank.ttf")) {
        std::cerr << "Cannot open font" << std::endl;
    }

    SelectDifficulty.setFont(font);
    SelectDifficulty.setString("SELECT DIFFICULTY:");
    SelectDifficulty.setCharacterSize(60);
    SelectDifficulty.setFillColor(sf::Color::White);
    SelectDifficulty.setPosition(sf::Vector2f(850 / 4, 350 / 4));

    game[0].setFont(font);
    game[0].setFillColor(sf::Color::Red);
    game[0].setString("EASY");
    game[0].setPosition(sf::Vector2f(width / 2, height / 4 * 2));

    game[1].setFont(font);
    game[1].setFillColor(sf::Color::White);
    game[1].setString("MEDIUM");
    game[1].setPosition(sf::Vector2f(width / 2, height / 4 * 2.5));

    game[2].setFont(font);
    game[2].setFillColor(sf::Color::White);
    game[2].setString("HARD");
    game[2].setPosition(sf::Vector2f(width / 2, height / 4 * 3));
}

Gamescreen::~Gamescreen() {}

void Gamescreen::GameDraw(sf::RenderWindow& window) {
    window.draw(SelectDifficulty); // Draw the "SELECT DIFFICULTY:" text
    for (int i = 0; i < Max_Number_Of_GameItems; i++) {
        window.draw(game[i]);
    }
}

void Gamescreen::GameMoveUp() {
    if (GameIndex - 1 >= 0) {
        game[GameIndex].setFillColor(sf::Color::White);
        GameIndex--;
        game[GameIndex].setFillColor(sf::Color::Red);
    }
}

void Gamescreen::GameMoveDown() {
    if (GameIndex + 1 < Max_Number_Of_GameItems) {
        game[GameIndex].setFillColor(sf::Color::White);
        GameIndex++;
        game[GameIndex].setFillColor(sf::Color::Red);
    }
}

int Gamescreen::GameGetPressedItem() const {
    return GameIndex;
}
