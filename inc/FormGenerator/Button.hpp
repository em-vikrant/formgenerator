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
        Button(float xPos, float yPos, std::string title);
        Button(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor);

        /* Functions. */
        void Create(float xPos, float yPos, float width, float height, std::string title, fg::Color bgColor, fg::Color titleColor);
        void Draw(sf::RenderWindow& window) override;
        bool IsMouseOver(const sf::RenderWindow& window) override;
        void TakeAction() override;

        inline bool IsLive() override { return isLive; }
        inline void UnLive() override { isLive = false; }

    private:
        sf::RectangleShape shape;
        sf::Color color;
        bool isLive;
};

#endif // BUTTON_H
