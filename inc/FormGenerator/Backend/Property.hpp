/* File: Property.hpp
 * Header file for the Property setter class.
 */

#ifndef PROPERTY_H
#define PROPERTY_H

/* STD includes. */
#include <string>
#include <vector>

/* SFML includes. */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Widget.hpp>


namespace fg::Backend
{
    class Property;
}

/**
 * @brief Class that is used to set properties of form elements.
 * 
 * This class provides methods to set properties of form elements.
*/
class fg::Backend::Property
{
    public:
        enum class ElementAction { ON_CLICK };
        enum class ElementProperty
        {
            SAVE_STATE_LOCALLY,             /*! Save the state of the form in local data structures. */
            SAVE_STATE_IN_BIN_FILE,         /*! Save the state of the form in binary files. */
            SAVE_STATE_IN_CSV,              /*! Save the state of the form in CSV files. */
        };

        Property& operator=(const Property& property) {
            if (this != &property)
                this->propertyMap = property.propertyMap;

            return *this;
        }

        /**
         * @brief Function used to set the property of a widget.
         * 
         * This will take a widget name along with the property and then save property state for that widget.
         * 
         * @param[in] widgetKey Widget name.
         * @param[in] action    Action for which property to be enabled.
         * @param[in] pWidget   Property of the widget that is to be executed for its attached action.
         * @return              Nothing.
        */
        void SetProperty(const std::string& widgetKey, ElementAction action, ElementProperty property);

        /**
         * @brief Function to check if a property exists for the widget.
         * 
         * This function will take widget object name and check if it's property exists or not.
         * 
         * @param[in] widgetKey Widget name.
         * @return              Action-Property pair for the input widget.
        */
        bool IsPropertyExists(const std::string widgetKey) const;

        /**
         * @brief Function to get the property map for a widget.
         * 
         * This function will take widget pointer.
         * 
         * @param[in] widgetKey Widget name.
         * @return              Action-Property pair for the input widget.
        */
        std::pair<ElementAction, ElementProperty> GetProperty(const std::string& widgetKey) const;

    private:
        std::map<std::string, std::pair<ElementAction, ElementProperty>> propertyMap;
};

#endif // PROPERTY_H