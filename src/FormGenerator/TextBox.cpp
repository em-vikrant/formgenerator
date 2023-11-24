/* FILE: TextBox.cpp
 * TextBox class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/TextBox.hpp>


fg::TextBox::TextBox()
    : Widget()
{
    isLive = false;
}

fg::TextBox::TextBox(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor) 
    : fg::Widget(position, dimension)
{
    try
    {
        cursorChar = std::string(1, fg::CURSOR_CHAR);
        inputString = std::string("");
        margin = {xMargin, yMargin};

        /* Creating shape for this widget. */
        pShape = std::make_shared<sf::RectangleShape>();
        sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

        /* Widget shape characterstics. */
        shape.setPosition(position);
        shape.setSize(dimension);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);
        shape.setFillColor(bgColor);
        
        SetWidgetColor(bgColor);
        SetWidgetText("TextBox", textColor);

        /* Inline text characterstics. */
        SetTextParms(inlineText, inputString, position + margin); 

        /* Make the textbox widget live & unselected by default. */
        isLive = true;
        isSelected = false;
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
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    /* Display widget. */
    window.draw(shape);
    
    /* Display widget title. */
    if (IsWidgetTextEnabled() == true)
    {
        window.draw(GetWidgetText());
    }
    else
    {
        window.draw(inlineText);
    }
}

bool fg::TextBox::IsMouseOver(const sf::RenderWindow& window)
{
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f buttonPos = shape.getPosition();
    sf::Vector2f buttonSize = shape.getSize();

    return mousePos.x >= buttonPos.x && mousePos.x < buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y < buttonPos.y + buttonSize.y;
}

void fg::TextBox::TakeAction()
{
    /* Check and enable text box for text entering. */
    if (!isSelected && IsMouseClicked() == true)
    {
        isSelected = true;
        TrySetInlineText(inputString + cursorChar);

        /* Disable widget title. */
        DisableWidgetText();
    }
    /* If clicked outside of the text box area. */
    else if (isSelected && IsMouseClicked() == false)
    {
        isSelected = false;
        TrySetInlineText(inputString);
    }
    
    /* Handle text event for the text box. */
    sf::Event& event = GetCurrentEvent();
    if (isSelected && event.type == sf::Event::TextEntered)
    {
        unsigned int charCode = event.text.unicode;
        if (charCode < 128)
        {
            if (charCode == fg::KEY_BACKSPACE)
            {
                if (!inputString.empty())
                {
                    inputString.pop_back();
                }
            }
            else
            {
                /* In case a carriage-return. Change code to new line. */
                if (charCode == fg::KEY_ENTER)
                    charCode = fg::KEY_NEWLINE;

                inputString += static_cast<char>(charCode);
            }

            /* Set the inline text. */
            if (TrySetInlineText(inputString + cursorChar) == false)
                inputString.pop_back(); // Remove the extra char added
        }
    }
}

bool fg::TextBox::IsTextInLimits(const sf::Text& text)
{
    bool inLimits = false;
    std::string s = text.getString();

    uint16_t xLim = static_cast<uint16_t>(GetWidgetDimension().x - margin.x * 2.0);
    uint16_t yLim = static_cast<uint16_t>(GetWidgetDimension().y - margin.x * 2.0);

    sf::FloatRect textBounds = text.getGlobalBounds();

    uint16_t xChars = static_cast<uint16_t>(textBounds.width);
    uint16_t yChars = static_cast<uint16_t>(textBounds.height);

    if (xChars <= xLim && yChars <= yLim)
        inLimits = true;

    //printf("XCH, %d, XLIM, %d, YCH, %d, YLIM, %d\n", xChars, xLim, yChars, yLim);
    
    return inLimits;
}

void fg::TextBox::SetTextParms(sf::Text& text, std::string& input, sf::Vector2f coordinates)
{
    text.setFont(GetWidgetFont());
    text.setCharacterSize(GetWidgetFontSize());
    text.setFillColor(GetWidgetTextColor());
    text.setString(input);

    sf::FloatRect inlineTextBounds = text.getLocalBounds();
    text.setOrigin(inlineTextBounds.left + inlineTextBounds.width / 2.0f, 
            inlineTextBounds.top + inlineTextBounds.height / 2.0f);
    text.setPosition(static_cast<int>(coordinates.x), static_cast<int>(coordinates.y));
}

bool fg::TextBox::TrySetInlineText(std::string input)
{
    sf::Text text = inlineText;
    text.setString(input);

    if (IsTextInLimits(text))
    {
        inlineText.setString(input);
        return true;
    }

    return false;
}

