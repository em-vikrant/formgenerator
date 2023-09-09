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
        KEY_ENTER       = 0x0D
    };
}

/* Brief: TextBox class. */
class fg::TextBox : public fg::Widget
{
    public:
        /* Constructor. */
        TextBox();
        TextBox(float xPos, float yPos, std::string title);
        TextBox(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor);

        /* Functions. */
        void Create(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor);
        void Draw(sf::RenderWindow& window) override;
        bool IsMouseOver(const sf::RenderWindow& window) override;
        void TakeAction() override;

        inline bool IsLive() override { return isLive; }
        inline void UnLive() override { isLive = false; }

    private:
        sf::RectangleShape shape;
        sf::Text inlineText;
        std::vector<sf::Text> textVec;
        sf::Color color;
        std::string inputString;
        std::string cursorChar;
        bool isLive;
        fg::Pair2f margin;
        fg::Pair2f limit;
        
        void SetTextParms(sf::Text& text, std::string& input, fg::Pair2f coordinate);
        void AddEntryToTextVec(std::string input);
        void SetTextVecAtEnd(std::string input);
        bool IsTextInLimits(const sf::Text& text);
};

#endif // TEXTBOX_H
