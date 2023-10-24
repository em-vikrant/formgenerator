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
#include <FormGenerator/WidgetManager.hpp>
#include <FormGenerator/Utils/Config.hpp>


namespace fg
{
    class FormGenerator;
}


/* Brief: FormGenerator class. */
class fg::FormGenerator
{
    public:
        /* Constructors. */
        FormGenerator(std::string sAppPath);

        /* Destructors. */
        ~FormGenerator();

        /* Formgenerator driver functions. */
        bool Create(std::string title);
        void Update();
        void Display();
        void Close();

        inline bool IsLive() { return isLive; }
        inline void UnLive() { isLive = false; }

        /* Client level widget manipulation. */
        void SetWidgetInitText(const std::string widgetKey, const std::string sText);

    private:
        sf::RenderWindow    formWindow;     /*! Window instance to hold the form. */
        sf::String          formTitle;      /*! Form title. */
        sf::Color           color;          /*! Form title. */
        sf::Event           event;          /*! Pointer to the sfml event occured. */
        std::string         sAppName;       /*! Current application name. */
        bool                isLive;         /*! To check if form window is open. */
        
        bool                configFlag;     /*! Config flag, set to true on successful configuration read. */
        uint16_t            width;          /*! Form width. */
        uint16_t            height;         /*! Form height. */

        std::shared_ptr<fg::utils::Config> pConfig;
        fg::WidgetManager   oWidgetManager;
        std::vector<std::string> widgetKeys;
};

#endif // FORM_GENERATOR_H
