/* File: WidgetManager.hpp
 * Header file of Widget Manager class.
 */

#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

/* STD includes. */
#include <string>
#include <memory>
#include <vector>
#include <map>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>
#include <FormGenerator/Backend/Property.hpp>
#include <FormGenerator/Backend/WidgetBinder.hpp>


namespace fg
{
    class WidgetManager;
}

/* Brief: WidgetManager class. */
class fg::WidgetManager
{
    public:
        /**
         * @brief AddWidget function will create and add a new widget.
         * 
         * This function will take in widget name and it's configurations and create a widget object.
         * 
         * @param[in] name          Widget name.
         * @param[in] configList    Configuration vector of the widget.
         * @return                  Boolean value that represents whether a widget is added & created successfully or not.
         *                          true - Success
         *                          false - failure
        */
        bool AddWidget(std::string name, std::vector<std::pair<std::string, std::string>> configList);

        /**
         * @brief Operator function
         * 
         * This will take a widget name and returns a shared pointer pointing to it's object.
         * 
         * @param[in] name          Widget object pointer to be searched in bind vector of this class.
         * @return                  A shared pointer to widget object.
        */
        std::shared_ptr<fg::Widget> operator[](const std::string& name);

        //TODO: Have to remove this method and add this feature to somewhere else in the architecture.
        /**
         * @brief Used to set the global font parameters of the form UI.
         * 
         * This function will take in font name and it's size to be applied to the global UI.
         * 
         * @param[in] font          font name.
         * @param[in] fontSize      Font size.
         * @return                  Nothing.
        */
        void SetGlobalFontParms(const std::string& font, uint16_t fontSize);

        /**
         * @brief Function to set the property instance of this class.
         * 
         * This function will take property object and set the property instance variable using it.
         * 
         * @param[in] oProperty     Property object input.
         * @return                  Nothing.
        */
       void SetProperty(const fg::Backend::Property& oProperty);

       /**
         * @brief Function to set the widget binder instance of this class.
         * 
         * This function will take widget binder object and set the widget binder instance variable using it.
         * 
         * @param[in] oWidgetBinder Property object input.
         * @return                  Nothing.
        */
       void SetWidgetBinder(const fg::Backend::WidgetBinder& oWidgetBinder);

    private:
        std::map<std::string, std::shared_ptr<fg::Widget>> widgetMap;
        fg::Backend::Property oProperty;
        fg::Backend::WidgetBinder oWidgetBinder;
};

#endif // WIDGETMANAGER_H
