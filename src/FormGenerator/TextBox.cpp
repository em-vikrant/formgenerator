/* FILE: TextBox.cpp
 * TextBox class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/TextBox.hpp>


fg::TextBox::TextBox()
{
    isLive = false;
    inputString = std::string("");
}

fg::TextBox::TextBox(float xPos, float yPos, std::string title) :
    fg::TextBox()
{
    Create(xPos, yPos, defaultTextBoxWidth, defaultTextBoxHeight, title, fg::Color{255, 255, 255, 255}, fg::Color{0, 0, 0, 180});
}

fg::TextBox::TextBox(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor) :
    fg::TextBox()
{
    Create(xPos, yPos, width, height, title, bgColor, titleColor);
}

void fg::TextBox::Create(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor)
{
    try
    {
        /* Widget shape characterstics. */
        shape.setPosition(xPos, yPos);
        shape.setSize(sf::Vector2f(width, height));
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);

        color = sf::Color{bgColor.r, bgColor.g, bgColor.b, bgColor.a};
        shape.setFillColor(color);

        /* Widget title characterstics. */
        SetWidgetTitle(title, titleColor);

        sf::FloatRect titleBounds = GetWidgetTitleBounds();
        SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
        SetWidgetTitlePosition(xPos + width / 2.0f, yPos + height / 2.0f);

        /* Inline text characterstics. */
        inlineText.setFont(GetDefaultFont());
        inlineText.setString(inputString);
        inlineText.setCharacterSize(defaultFontSize);
        inlineText.setFillColor(sf::Color::Black);

        sf::FloatRect inlineTextBounds = inlineText.getLocalBounds();
//        inlineText.setOrigin(inlineTextBounds.left + inlineTextBounds.width / 2.0f, inlineTextBounds.top + inlineTextBounds.height / 2.0f);
        inlineText.setOrigin(inlineTextBounds.left, inlineTextBounds.top);
        inlineText.setPosition(xPos + 20.0f, yPos + 10.0f);

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

void fg::TextBox::Draw(sf::RenderWindow& window)
{
    /* Display widget. */
    window.draw(shape);
    
    /* Display widget title. */
    if (IsWidgetTitleEnabled() == true)
    {
        window.draw(GetWidgetTitle());
    }
    else
    {
        window.draw(inlineText);
    }
}

bool fg::TextBox::IsMouseOver(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    return mousePos.x >= buttonPos.x && mousePos.x < buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y < buttonPos.y + buttonSize.y;
}

void fg::TextBox::TakeAction()
{
    /* Disable widget title. */
    DisableWidgetTitle();

    /* Get the event and take action accordingly. */
    sf::Event& event = GetCurrentEvent();
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128) {
            if (event.text.unicode == '\b' && !inputString.empty()) {
                inputString.pop_back();
            } else if (event.text.unicode != '\b') {
                inputString += static_cast<char>(event.text.unicode);
            }
            inlineText.setString(inputString + "|");
        }
    }
}


