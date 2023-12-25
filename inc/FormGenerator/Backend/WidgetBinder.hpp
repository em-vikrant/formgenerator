/* File: WidgetBinder.hpp
 * Header file for the WidgetBinder class.
 */

#ifndef WIDGET_BINDER_H
#define WIDGET_BINDER_H

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
    class WidgetBinder;
}

/**
 * @brief Class that binds two widgets together.
 * 
 * This class provides methods to bind two widgets.
*/
class fg::Backend::WidgetBinder
{
    public:
        /**
         * @brief Operator function
         * 
         * This will take a widget object pointer and returns another widget object pointer binded to it.
         * 
         * @param[in] widget Widget object pointer to be searched in bind vector of this class.
         * @return A widget object that is binded with the input widget object.
        */
        std::shared_ptr<fg::Widget> operator[](std::shared_ptr<fg::Widget> widget);

        /**
         * @brief Binder function to bind widgets.
         * 
         * This function binds two widget object pointers and store them in class intance.
         * 
         * @param[in] widget1 Widget object pointer to be bind with other widget object.
         * @param[in] widget2 Widget object pointer to be bind with other widget object.
         * @return Nothing.
        */
        void Bind(std::shared_ptr<fg::Widget> widget1, std::shared_ptr<fg::Widget> widget2);

    private:
        std::vector<std::pair<std::shared_ptr<fg::Widget>, std::shared_ptr<fg::Widget>>> m_bindWidgetVec;
};

#endif // WIDGET_BINDER_H