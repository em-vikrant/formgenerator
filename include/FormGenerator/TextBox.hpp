/* File: TextBox.hpp
 * Header file for text box class.
 */

#ifndef TEXTBOX_H
#define TEXTBOX_H

/* STD includes. */
#include <string>

/* SFML includes. */


using DELETE_KEY = 8;
using ENTER_KEY = 13;
using ESCAPE_KEY = 27;

/* Brief: TextBox class. */
class TextBox
{
    public:
        TextBox(int size, sf::Color color, bool sel);

        void SetFont(sf::Font& font);
        void SetPosition(sf::Vector2f pos);
        void SetLimit(bool tof);
        void SetLimit(bool tof, int limit);
        void SetSelected(bool sel);

    private:
        sf::Text textBox;
        std::ostringstream text;
        bool isSelected = false;
        bool hasLimit = false;
        int limit;

        void InputLogic(int charTyped);
        void DeleteLastChar();
};

#endif // TEXTBOX_H
