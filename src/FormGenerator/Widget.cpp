/* FILE: Widget.cpp
 * Widget class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* FG includes. */
#include <FormGenerator/Widget.hpp>


void fg::Widget::SetWidgetTitle(std::string title, fg::Color color)
{
    try
    {
        if (isFontSet == false)
        {
            LoadDefaultFont();
        }

        if (titleSize <= 0)
        {
            titleSize = defaultFontSize;
        }

        this->titleColor = sf::Color(color.r, color.g, color.b, color.a);

        this->title.setFont(font);
        this->title.setString(title);
        this->title.setCharacterSize(titleSize);
        this->title.setFillColor(this->titleColor);

        EnableWidgetTitle();
    }
    catch(std::exception& e)
    {
        throw;
    }
}

void fg::Widget::SetWidgetTitleOrigin(float xPos, float yPos)
{
    title.setOrigin(xPos, yPos);
}

void fg::Widget::SetWidgetTitlePosition(float xPos, float yPos)
{
    title.setPosition(xPos, yPos);
}

void fg::Widget::SetWidgetTitleCharSize(int size)
{
    titleSize = size;
}

void fg::Widget::LoadDefaultFont()
{
    try
    {
        if (!font.loadFromFile(DEFAULT_FONT))
        {
            std::ostringstream oss;
            oss << "[" << __func__ << ":" << __LINE__ << "]";
            oss << " FAILED TO LOAD DEFAULT FONT";
            throw oss.str();
        }
    }
    catch (std::exception& e)
    {
        throw;
    }
}

sf::Font& fg::Widget::GetDefaultFont()
{
    return font;
}
