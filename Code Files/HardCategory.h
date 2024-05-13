#pragma once
#ifndef CATEGORY_HH
#define CATEGORY_HH

#include <SFML/Graphics.hpp>
using namespace sf;
class HardCategory {
public:
    HardCategory(float width, float height);

    void HardCategoryDraw(RenderWindow& window);
    void HardCategorymoveUp();
    void HardCategorymoveDown();
    int GetSelectedHardCategory();

private:
    static const int MAX_HardCategoryITEMS = 3; 
    int HardCategoryselectedItemIndex;
    Font font;
    Text categories[MAX_HardCategoryITEMS]; 
};

#endif // CATEGORY_H
