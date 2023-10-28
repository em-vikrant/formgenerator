/* FILE: Button.cpp
 * Button class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/Button.hpp>


fg::Button::Button(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor)
    : Button()
{
    try
    {
        /* Create shape for this class. */
        pShape = std::make_shared<sf::RectangleShape>();
        sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

        shape.setPosition(position);
        shape.setSize(dimension);
        shape.setFillColor(bgColor);
        
        SetWidgetColor(bgColor);
        SetWidgetText("Button", textColor);

        sf::FloatRect titleBounds = GetWidgetTitleBounds();
        SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
        SetWidgetTitlePosition(position.x + dimension.x / 2.0f, position.y + dimension.y / 2.0f);

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

void fg::Button::Create(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor)
{
    try
    {
        sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

        shape.setPosition(position);
        shape.setSize(dimension);
        shape.setFillColor(bgColor);

        SetWidgetColor(bgColor);
        SetWidgetText("Button", textColor);

        sf::FloatRect titleBounds = GetWidgetTitleBounds();
        SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
        SetWidgetTitlePosition(position.x + dimension.x / 2.0f, position.y + dimension.y / 2.0f);

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
    /* Display widget. */
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);
    window.draw(shape);
    
    /* Display widget title. */
    if (IsWidgetTitleEnabled() == true)
    {
        window.draw(GetWidgetText());
    }
}

bool fg::Button::IsMouseOver(const sf::RenderWindow& window)
{
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    return mousePos.x >= buttonPos.x && mousePos.x < buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y < buttonPos.y + buttonSize.y;
}

void fg::Button::TakeAction()
{
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    /* Get the event and take action accordingly. */
    if (IsMouseClicked())
        shape.setFillColor(sf::Color::Red);
    else if (IsMouseReleased())
        shape.setFillColor(GetWidgetColor());
    else if (IsMouseHover())
        shape.setFillColor(sf::Color::Green);
}


