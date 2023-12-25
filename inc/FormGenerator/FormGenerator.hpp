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
#include <FormGenerator/Utils/Config.hpp>
#include <FormGenerator/WidgetManager.hpp>
#include <FormGenerator/Backend/WidgetBinder.hpp>
#include <FormGenerator/Backend/Property.hpp>


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

        /**
         * @brief Method to apply properties on the widgets.
         * 
         * This method will set the properties of the widgets.
         * 
         * @param[in] property          Properties to be applied on the widgets.
         * @return                      Nothing.
         */
        void ApplyWidgetProperty(const fg::Backend::Property& property);
        
        /**
         * @brief Method to apply widget bindings.
         * 
         * This method will set the widget bindings.
         * 
         * @param[in] widgetBindings    Properties to be applied on the widgets.
         * @return                      Nothing.
         */
        void ApplyWidgetBindings(const fg::Backend::WidgetBinder& widgetBindings);

    private:
        sf::RenderWindow    formWindow;     /*! Window instance to hold the form. */
        sf::String          formTitle;      /*! Form title. */
        sf::Color           color;          /*! Form background color. */
        sf::Event           event;          /*! Pointer to the sfml event occured. */
  
        std::string         sAppName;       /*! Current application name. */
        bool                isLive;         /*! To check if form window is open. */        
        bool                configFlag;     /*! Config flag, set to true on successful configuration read. */
        uint16_t            width;          /*! Form width. */
        uint16_t            height;         /*! Form height. */

        std::shared_ptr<fg::utils::Config>          pConfig;
        std::vector<std::pair<std::string, bool>>   widgetKeys;
        fg::WidgetManager                           oWidgetManager;
};

#endif // FORM_GENERATOR_H
