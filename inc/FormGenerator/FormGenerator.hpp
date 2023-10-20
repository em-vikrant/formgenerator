/* File: FormGenerator.hpp
 * Header file for the form generator library.
 */

#ifndef FORM_GENERATOR_H
#define FORM_GENERATOR_H

/* STD includes. */
#include <string>
#include <vector>
#include <memory>

/* SFML includes. */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Widget.hpp>
#include <FormGenerator/Utils/Config.hpp>

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

        /* Formgenerator driver functions. */
        void Create(std::string title, fg::FormDimensions dimensions);
        void Update();
        void Display();
        void Close();

        /* Getters. */
        sf::Event GetCurrentEvent() { return event; }

        /* Widget generator function. */
        void AddWidget(fg::WidgetType widgetType, std::string title, float xPos, float yPos);

        inline bool IsLive() { return isLive; }
        inline void UnLive() { isLive = false; }

    private:
        bool                isLive;         /*! To check if form window is open. */
        sf::RenderWindow    formWindow;     /*! Window instance to hold the form. */
        sf::String          formTitle;      /*! Form title. */
        sf::Color           color;          /*! Form title. */
        sf::Event           event;          /*! Pointer to the sfml event occured. */

        /* WIDGETS */
        std::vector<std::shared_ptr<fg::Widget>> widgetVector;

        std::shared_ptr<fg::utils::Config> pConfig;
};

#endif // FORM_GENERATOR_H
