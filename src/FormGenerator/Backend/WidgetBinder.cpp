/* FILE: WidgetBinder.cpp
 * WidgetBinder class implementation.
 */

/* STD includes. */
#include <iostream>
#include <sstream>
#include <algorithm>

/* FG includes. */
#include <FormGenerator/Backend/WidgetBinder.hpp>


std::shared_ptr<fg::Widget> fg::Backend::WidgetBinder::operator[](std::shared_ptr<fg::Widget> widget)
{
    std::shared_ptr<fg::Widget> pWidget;
    bool widgetBindingAvailable = false;

    for (auto itr = m_bindWidgetVec.begin(); itr != m_bindWidgetVec.end(); itr++)
    {
        if (itr->first == widget)
        {
            widgetBindingAvailable = true;
            pWidget = itr->second;
            break;
        }
    }

    if (!widgetBindingAvailable)  
    {
        std::ostringstream oss;
        oss << "[" << __func__ << ":" << __LINE__ << "]";
        oss << " FAILED! INPUT WIDGET IS NOT BINDED!";
        throw std::runtime_error(oss.str());
    }

    return pWidget;
}

void fg::Backend::WidgetBinder::Bind(std::shared_ptr<fg::Widget> widget1, std::shared_ptr<fg::Widget> widget2)
{
    if (m_bindWidgetVec.size() <= 0)
    {
        m_bindWidgetVec.push_back({widget1, widget2});
    }
    else
    {
        std::pair<std::shared_ptr<fg::Widget>, std::shared_ptr<fg::Widget>> widgetPair;
        std::shared_ptr<fg::Widget> pWidget;

        /* Add pointer objects pari to the vector. Ignore in case pair is alredy there. */
        auto itr = std::find(m_bindWidgetVec.begin(), m_bindWidgetVec.end(), widgetPair);
        if (itr == m_bindWidgetVec.end())
            m_bindWidgetVec.push_back(widgetPair);
    }
}