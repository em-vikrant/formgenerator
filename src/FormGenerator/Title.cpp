/* FILE: Title.cpp
 * Title class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/Title.hpp>


fg::Title::Title(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor)
    : Widget(position, dimension)
{
    try
    {
        /* Create shape for this class. */
        pShape = std::make_shared<sf::RectangleShape>();
        sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

        shape.setPosition(position);
        shape.setSize({0, 0});          // Emulates only text is there.
        shape.setFillColor(bgColor);
        
        SetWidgetColor(bgColor);
        SetWidgetText("Title", textColor);
        SetWidgetTextFontSize(dimension.y);

        /* Make the title live. */
        isLive = true;
    }
    catch(std::exception& e)
    {
        std::ostringstream oss;
        oss << "CAUGHT AT [" << __func__ << ":" << __LINE__ << "]\n";
        oss << "\tINFO " << e.what();
        std::cout << oss.str() << std::endl;
    }
}

bool fg::Title::IsMouseOver(const sf::RenderWindow& window)
{
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f titlePos = shape.getPosition();
    sf::Vector2f titleSize = shape.getSize();

    return mousePos.x >= titlePos.x && mousePos.x < titlePos.x + titleSize.x &&
        mousePos.y >= titlePos.y && mousePos.y < titlePos.y + titleSize.y;
}

void fg::Title::TakeAction()
{
    /* No action. It's an inactive widget. */
}


