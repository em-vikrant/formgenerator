


#include "FormGenerator/TextBox.hpp"


fg::TextBox::TextBox(int size, sf::Color color, bool sel)
{
    textBox.setCharacterSize(size);
    textBox.setColor(color);
    isSelected = sel;
}

void fg::TextBox::SetFont(sf::Font& font)
{
    textBox.setFont(font);
}

void fg::TextBox::SetPosition(sf::Vector2f pos)
{
    textBox.setPosition(pos);
}

void fg::TextBox::SetLimit(bool tof)
{
    hasLimit = tof;
}

void fg::TextBox::SetLimit(bool tof, int lim)
{
    hasLimit = tof;
    limit = limit;
}

void fg::TextBox::SetSelected(bool sel)
{
    isSelected = sel;
    if (sel == false)
    {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textBox.setString(newT);
    }
}

void fg::TextBox::InputLogic(int charTyped)
{
    if (charTyped != ENTER_KEY && charTyped != DELETE_KEY && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    else if (charTyped == DELETE_KEY)
    {
        if (text.str().length() > 0)
        {
            DeleteLastChar();
        }
    }
    textBox.setString(text.str() + "_");
}

void fg::TextBox::DeleteLastChar()
{
}
