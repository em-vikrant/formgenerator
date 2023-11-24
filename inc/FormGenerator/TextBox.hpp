/* File: TextBox.hpp
 * Header file for TextBox class.
 */

#ifndef TEXTBOX_H
#define TEXTBOX_H

/* STD includes. */
#include <string>
#include <vector>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>


namespace fg
{
    class TextBox;

    /* Preprocess Constants. */
    constexpr char CURSOR_CHAR  = '|';
    constexpr int xMargin       = 10;
    constexpr int yMargin       = 8;

    /* Keys. */
    enum Key
    {
        KEY_BACKSPACE   = 0x08,
        KEY_ENTER       = 0x0D,
        KEY_NEWLINE     = 0x0A
    };
}

/* Brief: TextBox class. */
class fg::TextBox : public fg::Widget
{
    public:
        /* Constructor. */
        TextBox();
        TextBox(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor);

        /* Functions. */
        void Draw(sf::RenderWindow& window) override;
        bool IsMouseOver(const sf::RenderWindow& window) override;
        void TakeAction() override;

        inline bool IsLive() override { return isLive; }
        inline void UnLive() override { isLive = false; }

    private:
        sf::Text inlineText;
        std::string inputString;
        std::string cursorChar;
        bool isLive;
        bool isSelected;

        sf::Vector2f margin;
        
        void SetTextParms(sf::Text& text, std::string& input, sf::Vector2f coordinate);
        bool TrySetInlineText(std::string input);
        bool IsTextInLimits(const sf::Text& text);
};

#endif // TEXTBOX_H
