/* FILE: Button.cpp
 * Button class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/Button.hpp>


fg::Button::Button(float xPos, float yPos, std::string title) :
    fg::Button()
{
    Create(xPos, yPos, defaultButtonWidth, defaultButtonHeight, title, fg::Color{0, 255, 0, 100}, fg::Color{0, 0, 0, 100});
}

fg::Button::Button(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor) :
    fg::Button()
{
    Create(xPos, yPos, width, height, title, bgColor, titleColor);
}

void fg::Button::Create(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor)
{
    try
    {
        shape.setPosition(xPos, yPos);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color{bgColor.r, bgColor.g, bgColor.b, bgColor.a});

        SetWidgetTitle(title, titleColor);

        sf::FloatRect titleBounds = GetWidgetTitleBounds();
        SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
        SetWidgetTitlePosition(xPos + width / 2.0f, yPos + height / 2.0f);

        /* Make the button live. */
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

void fg::Button::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(GetWidgetTitle());
}

bool fg::Button::IsMouseOver(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    return mousePos.x >= buttonPos.x && mousePos.x < buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y < buttonPos.y + buttonSize.y;
}

void fg::Button::TakeAction()
{
}


