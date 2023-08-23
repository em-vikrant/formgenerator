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
#include <SFML/Window.hpp>
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
#if 0
        virtual void InCtxTakeAction() = 0;
        virtual void OffCtxTakeAction() = 0;
#endif
        virtual bool IsLive() = 0;
        virtual void UnLive() = 0;

        /* Helper functions. */
        sf::FloatRect GetWidgetTitleBounds() { return title.getLocalBounds(); }
        sf::Text GetWidgetTitle()   { return title; }
        sf::Color GetWidgetColor()  { return titleColor; }

        inline void DisableWidgetTitle()   { isTitleEnable = false; }
        inline void EnableWidgetTitle()    { isTitleEnable = true; }

        inline bool IsWidgetTitleEnabled() { return isTitleEnable; }

        /* Setter functions. */
        void SetCurrentEvent(sf::Event& event) { this->event = event; }

    protected:
        /* Functions to be used by widgets. */
        void SetWidgetTitle(std::string title, fg::Color color);

        void SetWidgetTitleOrigin(float xPos, float yPos);
        void SetWidgetTitlePosition(float xPos, float yPos);
        void SetWidgetTitleCharSize(int size);

        sf::Font GetDefaultFont();
        sf::Event& GetCurrentEvent() { return event; }

    private:
        sf::Text    title;                      /*! Text title of widget. */
        int         titleSize = 0;              /*! Text title size of widget. */
        bool        isTitleEnable = false;      /*! Flag that get set when title is enabled / disabled. */
        sf::Color   titleColor;                 /*! Widget title color. */ 
        sf::Font    font;                       /*! Widget title font. */
        bool        isFontSet = false;          /*! Flag that get when font is loaded. */
        sf::Event   event;                      /*! Current event, used when relevant to the widget. */

        /* Private functions. */
        void LoadDefaultFont();
};

#endif // WIDGETS_H
