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

namespace fg
{
    class WidgetManager;
}

/* Brief: WidgetManager class. */
class fg::WidgetManager
{
    public:
        bool AddWidget(std::string name, 
            std::vector<std::pair<std::string, std::string>> configList);

        std::shared_ptr<fg::Widget> operator[](const std::string& name);

        void SetGlobalFontParms(const std::string& font, uint16_t fontSize);

    private:
        std::map<std::string, std::shared_ptr<fg::Widget>> widgetMap;
};

#endif // WIDGETMANAGER_H
