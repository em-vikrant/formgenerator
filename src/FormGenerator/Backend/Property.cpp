/* FILE: Property.cpp
 * Property class implementation.
 */

/* STD includes. */
#include <iostream>

/* FG includes. */
#include <FormGenerator/Backend/Property.hpp>

/* Namespaces. */
using namespace fg::Backend;


void Property::SetProperty(const std::string& widgetKey, ElementAction action, ElementProperty property)
{
    auto itr = propertyMap.find(widgetKey);
    if (itr == propertyMap.end())
    {
        propertyMap.insert({widgetKey, {action, property}});
    }
}

bool Property::IsPropertyExists(const std::string widgetKey) const
{
    bool isPropertyExists = true;

    auto itr = propertyMap.find(widgetKey);
    if (itr == propertyMap.end())
    {
        isPropertyExists = false;
    }

    return isPropertyExists;
}

std::pair<Property::ElementAction, Property::ElementProperty> Property::GetProperty(const  std::string& widgetKey) const
{
    // ** IMPORTANT **
    // It can cause issues.
    // Hence, should always be used after making a check call
    // to "IsPropertyExists" method.

    std::pair<Property::ElementAction, Property::ElementProperty> propertyMapping;

    auto itr = propertyMap.find(widgetKey);
    if (itr != propertyMap.end())
    {
        propertyMapping.first = itr->second.first;
        propertyMapping.second = itr->second.second;
    }

    return propertyMapping;
}