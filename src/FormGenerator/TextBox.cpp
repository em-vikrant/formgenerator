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
        limit = {0, 0};

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
        AddEntryToTextVec(inputString);

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

void fg ::TextBox::Create(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor)
{
    try
    {
        sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);
        
        /* Widget shape characterstics. */
        shape.setPosition(position);
        shape.setSize(dimension);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);
        shape.setFillColor(bgColor);
        
        SetWidgetColor(bgColor);
        SetWidgetText("TextBox", textColor);

        sf::FloatRect titleBounds = GetWidgetTitleBounds();
        SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
        SetWidgetTitlePosition(position.x + dimension.x / 2.0f, position.y + dimension.y / 2.0f);

        /* Inline text characterstics. */
        AddEntryToTextVec(inputString);

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
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    /* Display widget. */
    window.draw(shape);
    
    /* Display widget title. */
    if (IsWidgetTitleEnabled() == true)
    {
        window.draw(GetWidgetText());
    }
    else
    {
        for (auto text : textVec)
            window.draw(text);
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
    static bool IsEnabledForWriting = false;

    /* Check and enable text box for text entering. */
    if (IsEnabledForWriting == false && IsMouseClicked() == true)
    {
        IsEnabledForWriting = true;
        SetTextVecAtEnd(inputString + cursorChar);

        /* Disable widget title. */
        DisableWidgetTitle();
    }
    /* If clicked outside of the text box area. */
    else if (IsMouseClicked() == false)
    {
        IsEnabledForWriting = false;
        SetTextVecAtEnd(inputString);
    }
    
    /* Handle text event for the text box. */
    sf::Event& event = GetCurrentEvent();
    if (IsEnabledForWriting == true && event.type == sf::Event::TextEntered)
    {
        unsigned int charCode = event.text.unicode;
        if (charCode < 128)
        {
            inputString = std::string(textVec.back().getString());
            if (charCode == fg::KEY_BACKSPACE)
            {
                if (!inputString.empty())
                {
                    inputString.pop_back();

                    if (!inputString.empty())
                        inputString.pop_back();

                    SetTextVecAtEnd(inputString);
                }

                if (inputString.empty() && textVec.size() > 1)
                    textVec.pop_back();
            }
            else if (charCode == fg::KEY_ENTER)
            {
                inputString.pop_back();
                SetTextVecAtEnd(inputString);

                AddEntryToTextVec(std::string(""));
            }
            else
            {
                inputString.pop_back();
                inputString += static_cast<char>(charCode);
                SetTextVecAtEnd(inputString);
            }

            SetTextVecAtEnd(textVec.back().getString() + cursorChar);
        }
    }
}

void fg::TextBox::SetTextParms(sf::Text& text, std::string& input, sf::Vector2f coordinates)
{
    text.setFont(GetDefaultFont());
    text.setCharacterSize(GetDefaultFontSize());
    text.setFillColor(GetWidgetTextColor());
    text.setString(input);

    sf::FloatRect inlineTextBounds = text.getLocalBounds();
    text.setOrigin(inlineTextBounds.left + inlineTextBounds.width / 2.0f, inlineTextBounds.top + inlineTextBounds.height / 2.0f);
    text.setPosition(static_cast<int>(coordinates.x), static_cast<int>(coordinates.y));
}

void fg::TextBox::AddEntryToTextVec(std::string input)
{
    sf::Text newLineText;
    sf::Vector2f& position = GetWidgetPosition();

    if (textVec.empty())
    {
        SetTextParms(newLineText, input, position + margin);
    }
    else
    {
        sf::Vector2f textCoords{
            position.x + margin.x,
            position.y + (GetDefaultFontSize() + 1.0f) * textVec.size() + margin.y
        };
        SetTextParms(newLineText, input, textCoords);
    }

    if (IsTextInLimits(newLineText))
    {
        textVec.push_back(newLineText);
    }
}

bool fg::TextBox::IsTextInLimits(const sf::Text& text)
{
    bool inLimits = false;
    sf::RectangleShape& shape = *std::dynamic_pointer_cast<sf::RectangleShape>(pShape);

    sf::FloatRect textBounds = text.getGlobalBounds();

    if (textBounds.width < (shape.getSize().x - margin.x * 1.5) &&
       (GetDefaultFontSize() + textBounds.top) < ((GetWidgetPosition().y + shape.getSize().y) - margin.y * 0.5))
        inLimits = true;

//    printf("X: [%0.2f < %0.2f], Y: [%0.2f < %0.2f] == %s\n", textBounds.width, (shape.getSize().x - margin.x * 1.5), (defaultFontSize + textBounds.top), ((GetWidgetPosition().y + shape.getSize().y) - margin.y * 0.5), inLimits ? "true" : "false");

    return inLimits;
}

void fg::TextBox::SetTextVecAtEnd(std::string input)
{
    sf::Text text = textVec.back();
    text.setString(input);

    if (IsTextInLimits(text))
        textVec.back().setString(input);
}


