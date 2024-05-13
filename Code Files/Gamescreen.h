#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>

class Gamescreen {
public:
    Gamescreen(float width, float height);
    ~Gamescreen();

    void GameDraw(sf::RenderWindow& window);
    void GameMoveUp();
    void GameMoveDown();
    int GameGetPressedItem() const;

private:
    static const int Max_Number_Of_GameItems = 3;
    int GameIndex = 0;
    sf::Font font;
    sf::Text game[Max_Number_Of_GameItems];
    sf::Text SelectDifficulty;
};

#endif
