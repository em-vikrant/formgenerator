/* File: TextBox.hpp
 * Header file for button class.
 */

#ifndef TEXTBOX_H
#define TEXTBOX_H

/* STD includes. */
#include <string>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>


namespace fg
{
    class TextBox;

    /* Preprocess Constants. */
    constexpr char CURSOR_CHAR = '|';
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
        sf::Color color;
        std::string inputString;
        std::string cursorChar;
        bool isLive;
};

#endif // TEXTBOX_H
