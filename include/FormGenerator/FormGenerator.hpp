/* File: FormGenerator.hpp
 * Header file for the form generator library.
 */

#ifndef FORM_GENERATOR_H
#define FORM_GENERATOR_H

/* STD includes. */
#include <string>

/* SFML includes. */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Widget.hpp>

namespace fg
{
    class FormGenerator;
    struct FormDimensions;
}

/* Brief: Form Dimensions. */
struct fg::FormDimensions
{
    uint16_t width;
    uint16_t height;
};

/* Brief: FormGenerator class. */
class fg::FormGenerator
{
    public:
        /* Constructors. */
        FormGenerator();

        /* Destructors. */
        ~FormGenerator();

        /* Functions. */
        void Create(std::string title, fg::FormDimensions dimensions);
        void Update();
        void Display();
        void Close();

        /* Widget generators. */
        void AddWidget(fg::WidgetType widgetType, std::string title, float xPos, float yPos);

        inline bool IsLive() { return isLive; }
        inline void UnLive() { isLive = false; }

    private:
        bool isLive;                        /*! To check if form window is open. */
        sf::RenderWindow formWindow;        /*! Window instance to hold the form. */
        sf::String formTitle;               /*! Form title. */
        sf::Color color;                    /*! Form title. */
        fg::FormDimensions formDimensions;  /*! Form dimensions. */

        /* WIDGETS */
        std::vector<fg::Widget*> widgetVector;
};

#endif // FORM_GENERATOR_H
