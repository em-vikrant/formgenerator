/* File: Button.hpp
 * Header file for button class.
 */

#ifndef BUTTON_H
#define BUTTON_H

/* STD includes. */
#include <string>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>


namespace fg
{
    class Button;
}

/* Brief: Button class. */
class fg::Button : public fg::Widget
{
    public:
        /* Constructor. */
        Button() : Widget() { isLive = false; }
        Button(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor);

        /* Functions. */
        bool IsMouseOver(const sf::RenderWindow& window) override;
        void TakeAction() override;

        inline bool IsLive() override { return isLive; }
        inline void UnLive() override { isLive = false; }

    private:
        bool isLive;
};

#endif // BUTTON_H
