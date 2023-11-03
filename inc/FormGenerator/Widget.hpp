/* File: Widget.hpp
 * Header file to include all the available widgets.
 */

#ifndef WIDGETS_H
#define WIDGETS_H

/* STD includes. */
#include <string>
#include <sstream>
#include <exception>
#include <memory>

/* SFML includes. */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>


namespace fg
{
    class Widget;
}


/* Brief: Widget class. */
class fg::Widget
{
    public:
        /* Enum class: Widget parameters. */
        enum class Param { NONE, TYPE, POSITION, DIMENSION, COLOR, TEXT_COLOR };
        
        /* Enum class: Widget type. */
        enum class Type { NONE, BUTTON, TEXTBOX, TITLE };

        /* Constructor. */
        Widget();
        Widget(sf::Vector2f _position, sf::Vector2f _dimension);

        /* Destructor. */
        virtual ~Widget() {}

        /* Virtual functions. */
        virtual void Draw(sf::RenderWindow& window);
        virtual bool IsMouseOver(const sf::RenderWindow& window) = 0;
        virtual void TakeAction() = 0;
        virtual bool IsLive() = 0;
        virtual void UnLive() = 0;

        /* Helper functions. */
        inline void DisableWidgetText()     { isTextEnable = false; }
        inline void EnableWidgetText()      { isTextEnable = true; }

        inline bool IsWidgetTextEnabled()   { return isTextEnable; }
        inline bool IsMouseClicked()        { return mouseClicked; }
        inline bool IsMouseHover()          { return mouseHovered; }
        inline bool IsMouseReleased()       { return mouseReleased; }

        /* Setter functions. */
        void SetCurrentEvent(sf::Event& event)  { this->event = event; }
        void SetMouseState(bool state);
        void SetWidgetInitText(const std::string& sText);

        /* Getter functions. */
        sf::FloatRect   GetWidgetTextBounds()   { return widgetText.getLocalBounds(); }
        sf::Text&       GetWidgetText()         { return widgetText; }
        sf::Color       GetWidgetColor()        { return widgetColor; }
        sf::Color       GetWidgetTextColor()    { return widgetTextColor; }
        sf::Vector2f    GetWidgetPosition()     { return position; }
        sf::Vector2f    GetWidgetDimension()    { return dimension; }

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

        void SetWidgetTextFontSize(int size);
        void SetWidgetColor(sf::Color color)            { widgetColor = color; }
        void SetWidgetPosition(sf::Vector2f pos)        { position = pos; }
        void SetWidgetDimension(sf::Vector2f dmn)       { dimension = dmn; }

        sf::Font& GetWidgetFont()                       { return font; }
        uint16_t GetWidgetFontSize()                    { return widgetTextFontSize; }
        sf::Event& GetCurrentEvent()                    { return event; }

        void PositionWidgetTextAtCenter();

        /* Protected data member. */
        std::shared_ptr<sf::Shape> pShape;      /*! Shape pointer. */

    private:
        std::string     sWidgetText;            /*! Text displayed on the widget. */
        sf::Text        widgetText;             /*! SFML Object for widget text. */
        sf::Vector2f    position;               /*! Position vector. */
        sf::Vector2f    dimension;              /*! Dimension vector. */
        sf::Color       widgetColor;            /*! Widget background color. */
        sf::Color       widgetTextColor;        /*! Widget text color. */
        int             widgetTextFontSize;     /*! Font size of widget text. */

        bool            isTextEnable = false;   /*! Flag to check if initial text is enabled. */
        sf::Font        font;                   /*! Widget text font. */
        bool            isFontSet = false;      /*! Flag to check if font is loaded. */
        sf::Event       event;                  /*! Current event. */

        /* Global members for all instances. */
        static std::string  globalFontName;
        static uint16_t     globalFontSize;

        /* Mouse event flags. */
        bool        mouseClicked;               /*! Mouse clicked status for a widget. */
        bool        mouseHovered;               /*! Mouse hovering status for a widget. */
        bool        mouseReleased;              /*! Mouse released status for a widget. */
};

#endif // WIDGETS_H
