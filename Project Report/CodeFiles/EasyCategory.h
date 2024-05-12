#ifndef CATEGORY_HE
#define CATEGORY_HE
#include <SFML/Graphics.hpp>
using namespace sf;

class EasyCategory {
public:
    EasyCategory(float width, float height);

    void EasyCategoryDraw(RenderWindow& window);
    void EasyCategorymoveUp();
    void EasyCategorymoveDown();
    int  GetSelectedEasyCategory();

private:
    static const int MAX_EasyCategoryITEMS = 3;
    int EasyCategoryselectedItemIndex;
    Font font;
    Text categories[MAX_EasyCategoryITEMS];
};

#endif // CATEGORY_H
