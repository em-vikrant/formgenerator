/* FILE: WidgetManager.cpp
 * WidgetManager class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>

/* SFML includes. */
#include <SFML/Graphics.hpp>

/* FG includes. */
#include <FormGenerator/Button.hpp>
#include <FormGenerator/TextBox.hpp>
#include <FormGenerator/WidgetManager.hpp>


void fg::WidgetManager::AddWidget(std::string name, 
    std::vector<std::pair<std::string, std::string>> configParamList)
{
    fg::Widget::Type widgetType;
    sf::Vector2f position;
    sf::Vector2f dimension;
    sf::Color widgetColor;
    sf::Color textColor;

    for (auto cPair : configParamList) 
    {
        fg::Widget::Param param = fg::Widget::GetWidgetParam(cPair.first);
        switch (param)
        {
            case fg::Widget::Param::TYPE:
                widgetType = fg::Widget::GetWidgetType(cPair.second);
                break;

            case fg::Widget::Param::COLOR:
                widgetColor = fg::Widget::GetSFMLColor(cPair.second);
                break;
            
            case fg::Widget::Param::POSITION:
                position = fg::Widget::GetVector2f(cPair.second);
                break;
            
            case fg::Widget::Param::DIMENSION:
                dimension = fg::Widget::GetVector2f(cPair.second);
                break;
            
            case fg::Widget::Param::TEXT_COLOR:
                textColor = fg::Widget::GetSFMLColor(cPair.second);
                break;
            
            default:
                break;
        }
    }

    /* Add entry in the widget map. */
    if (widgetType == fg::Widget::Type::BUTTON)
        widgetMap.emplace(name, std::make_shared<fg::Button>(position, dimension, widgetColor, textColor));
    else if (widgetType == fg::Widget::Type::TEXTBOX)
        widgetMap.emplace(name, std::make_shared<fg::TextBox>(position, dimension, widgetColor, textColor));
}

std::shared_ptr<fg::Widget> fg::WidgetManager::operator[](const std::string& name)
{
    return widgetMap[name];
}

void fg::WidgetManager::SetGlobalFontParms(const std::string& font, uint16_t fontSize)
{
    fg::Widget::SetGlobalFont(font);
    fg::Widget::SetGlobalFontSize(fontSize);
}

