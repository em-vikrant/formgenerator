/* File: Widget.hpp
 * Header file to include all the available widgets.
 */

#ifndef WIDGETS_H
#define WIDGETS_H

/* STD includes. */
#include <string>
#include <sstream>
#include <exception>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>


namespace fg
{
    class Widget;
    struct Pair2f;
    struct Color;
    enum class WidgetType;
}

/* Brief: Vector/Pair structure. */
struct fg::Pair2f
{
    float x;
    float y;
};

/* Brief: Color structure. */
struct fg::Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) :
        r(_r), g(_g), b(_b), a(_a) {}
};

/* Brief: Widget type enum class. */
enum class fg::WidgetType
{
    WG_Button,
    WG_TextBox
};

/* Brief: Widget class. */
class fg::Widget
{
    public:
        /* Constructor. */
        Widget() { isFontSet = false; }

        /* Pure Virtual functions. */
        virtual void Draw(sf::RenderWindow& window) = 0;
        virtual bool IsMouseOver(const sf::RenderWindow& window) = 0;
        virtual void TakeAction() = 0;
        virtual bool IsLive() = 0;
        virtual void UnLive() = 0;

        /* Helper Functions. */
        sf::FloatRect GetWidgetTitleBounds() { return title.getLocalBounds(); }
        sf::Text GetWidgetTitle() { return title; }
        sf::Color GetWidgetColor() { return color; }


    protected:
        void SetWidgetTitle(std::string title, fg::Color color)
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

                this->color = sf::Color(color.r, color.g, color.b, color.a);

                this->title.setFont(font);
                this->title.setString(title);
                this->title.setCharacterSize(titleSize);
                this->title.setFillColor(this->color);
            }
            catch(std::exception& e)
            {
                throw;
            }
        }

        void SetWidgetTitleOrigin(float xPos, float yPos) { title.setOrigin(xPos, yPos); }
        void SetWidgetTitlePosition(float xPos, float yPos) { title.setPosition(xPos, yPos); }
        void SetWidgetTitleCharSize(int size) { titleSize = size; }

    private:
        sf::Text title;
        int titleSize = 0;
        sf::Color color;
        sf::Font font;
        bool isFontSet = false;

        /* Private functions. */
        void LoadDefaultFont()
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
};

#endif // WIDGETS_H
