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
}

/* Brief: Vector/Pair structure. */
struct fg::Pair2f
{
    float x;
    float y;
};


/* Brief: Widget class. */
class fg::Widget
{
    public:
        /* Enum class: Widget parameters. */
        enum class Param { NONE, TYPE, POSITION, DIMENSION, COLOR, COLORHEX, TEXT_COLOR };
        
        /* Enum class: Widget type. */
        enum class Type { NONE, BUTTON, TEXTBOX };

        /* Constructor. */
        Widget();

        /* Destructor. */
        virtual ~Widget() {}

        /* Pure Virtual functions. */
        virtual void Draw(sf::RenderWindow& window) = 0;
        virtual bool IsMouseOver(const sf::RenderWindow& window) = 0;
        virtual void TakeAction() = 0;
        virtual bool IsLive() = 0;
        virtual void UnLive() = 0;

        /* Helper functions. */
        inline void DisableWidgetTitle()    { isTitleEnable = false; }
        inline void EnableWidgetTitle()     { isTitleEnable = true; }

        inline bool IsWidgetTitleEnabled()  { return isTitleEnable; }
        inline bool IsMouseClicked()        { return mouseClicked; }
        inline bool IsMouseHover()          { return mouseHovered; }
        inline bool IsMouseReleased()       { return mouseReleased; }

        /* Setter functions. */
        void SetCurrentEvent(sf::Event& event)  { this->event = event; }
        void SetMouseState(bool state);
        void SetWidgetInitText(const std::string& sText);

        /* Getter functions. */
        sf::FloatRect   GetWidgetTitleBounds()  { return widgetText.getLocalBounds(); }
        sf::Text        GetWidgetText()         { return widgetText; }
        sf::Color       GetWidgetColor()        { return widgetColor; }
        sf::Color       GetWidgetTextColor()    { return widgetTextColor; }
        sf::Vector2f&   GetWidgetCoordinates()  { return coordinates; }

        /* Static functions. */
        static std::string  GetWidgetParamStr(Param param);
        static Param        GetWidgetParam(const std::string& sParam);
        static Type         GetWidgetType(const std::string& sType);
        static sf::Color    GetSFMLColor(const std::string& sColor);
        static sf::Vector2f GetVector2f(const std::string& sVector2);
        static void         SetGlobalFont(const std::string sFontName);
        static void         SetGlobalFontSize(uint16_t fontSize);

    protected:
        /* Functions to be used by widgets. */
        void SetWidgetText(std::string sText, sf::Color textColor);

        void SetWidgetTitleOrigin(float xPos, float yPos);
        void SetWidgetTitlePosition(float xPos, float yPos);
        void SetWidgetTextFontSize(int size);
        void SetWidgetColor(sf::Color color)    { widgetColor = color; }

        void SetWidgetCoordinates(sf::Vector2f coordinates) { this->coordinates = coordinates; }

        uint16_t GetDefaultFontSize() { return globalFontSize; }
  
        sf::Font& GetDefaultFont();
        sf::Event& GetCurrentEvent() { return event; }

    private:
        std::string     sWidgetText;            /*! Text displayed on the widget. */
        sf::Text        widgetText;             /*! SFML Object for widget text. */
        sf::Vector2f    position;               /*! Position vector. */
        sf::Vector2f    dimension;              /*! Dimension vector. */
        sf::Color       widgetColor;            /*! Widget title color. */
        sf::Color       widgetTextColor;        /*! Widget title color. */
        int             widgetTextFontSize;     /*! Text title size of widget. */

        bool        isTitleEnable = false;      /*! Flag that get set when title is enabled / disabled. */
        sf::Font    font;                       /*! Widget title font. */
        bool        isFontSet = false;          /*! Flag that get when font is loaded. */
        sf::Event   event;                      /*! Current event, used when relevant to the widget. */

        /* Global members for all instances. */
        static std::string  globalFontName;
        static uint16_t     globalFontSize;

        /* Widget shape. */
        sf::Vector2f  coordinates;              /*! Top left coordinates of widget. */

        /* Mouse flags. */
        bool        mouseClicked;               /*! Mouse clicked status for a widget. */
        bool        mouseHovered;               /*! Mouse hovering status for a widget. */
        bool        mouseReleased;              /*! Mouse released status for a widget. */
};

#endif // WIDGETS_H
