#pragma once
#ifndef CATEGORY_HM
#define CATEGORY_HM

#include <SFML/Graphics.hpp>
using namespace sf;
class MediumCategory {
public:
    MediumCategory(float width, float height);

    void MediumCategoryDraw(RenderWindow& window);
    void MediumCategorymoveUp();
    void MediumCategorymoveDown();
    int GetSelectedMediumCategory();

private:
    static const int MAX_MediumCategoryITEMS = 3; 
    int MediumCategoryselectedItemIndex;
    Font font;
    Text categories[MAX_MediumCategoryITEMS]; 
};

#endif // CATEGORY_H
