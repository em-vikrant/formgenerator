/* File: Title.hpp
 * Header file for title class.
 */

#ifndef TITLE_H
#define TITLE_H

/* STD includes. */
#include <string>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>


namespace fg
{
    class Title;
}

/* Brief: Title class. */
class fg::Title : public fg::Widget
{
    public:
        /* Constructor. */
        Title() : Widget() { isLive = false; }
        Title(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor);

        /* Functions. */
        void Create(sf::Vector2f position, sf::Vector2f dimension, sf::Color bgColor, sf::Color textColor);
        void Draw(sf::RenderWindow& window) override;
        bool IsMouseOver(const sf::RenderWindow& window) override;
        void TakeAction() override;

        inline bool IsLive() override { return isLive; }
        inline void UnLive() override { isLive = false; }

    private:
        bool isLive;
};

#endif // TITLE_H
