/* FILE: Widget.cpp
 * Widget class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>
#include <algorithm>

/* FG includes. */
#include <FormGenerator/Widget.hpp>


/* Global instance members. */
std::string fg::Widget::globalFontName = DEFAULT_FONT;
uint16_t fg::Widget::globalFontSize = DEFAULT_FONT_SIZE;


fg::Widget::Widget()
    : isFontSet(false)
{
    std::string fontPath = RESOURCE_PATH + "/fonts/" + globalFontName;
    fontPath.append(".ttf");

    /* Load font from gloabl font path. */
    if (font.loadFromFile(fontPath))
    {
        isFontSet = true;
    }

    /* Set widget text font size. */
    widgetTextFontSize = globalFontSize;
}

fg::Widget::Widget(sf::Vector2f _position, sf::Vector2f _dimension)
    : Widget()
{
    /* Set the position and dimension vector. */
    position = _position;
    dimension = _dimension;
}

void fg::Widget::Draw(sf::RenderWindow& window)
{
    /* Display widget. */
    window.draw(*pShape);
    
    /* Display widget title. */
    if (IsWidgetTitleEnabled() == true)
    {
        window.draw(GetWidgetText());
    }
}

void fg::Widget::SetWidgetText(std::string sText, sf::Color textColor)
{
    try
    {
        if (isFontSet)
        {
            widgetText.setFont(font);
            widgetText.setString(sText);
            widgetText.setCharacterSize(widgetTextFontSize);
            widgetText.setFillColor(textColor);
            widgetTextColor = textColor;

            /* Positioning of text at widget's center. */
            PositionWidgetTextAtCenter();

            EnableWidgetTitle();
        }
        else
        {
            std::ostringstream oss;
            oss << "[" << __func__ << ":" << __LINE__ << "]";
            oss << " FAILED! FONT PARAMETERS NOT SET!";
            throw oss.str();
        }
    }
    catch(std::exception& e)
    {
        throw;
    }
}

void fg::Widget::SetWidgetTitleOrigin(float xPos, float yPos)
{
    widgetText.setOrigin(xPos, yPos);
}

void fg::Widget::SetWidgetTitlePosition(float xPos, float yPos)
{
    widgetText.setPosition(xPos, yPos);
}

void fg::Widget::SetWidgetInitText(const std::string& sText)
{
    sWidgetText = sText;
    widgetText.setString(sWidgetText);

    /* Positioning of text at widget's center. */
    PositionWidgetTextAtCenter();
}

void fg::Widget::SetWidgetTextFontSize(int size)
{
    widgetTextFontSize = size;
    widgetText.setCharacterSize(widgetTextFontSize);
}

void fg::Widget::PositionWidgetTextAtCenter()
{
    sf::FloatRect titleBounds = GetWidgetTitleBounds();
    SetWidgetTitleOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    SetWidgetTitlePosition(position.x + dimension.x / 2.0f, position.y + dimension.y / 2.0f);
}

void fg::Widget::SetMouseState(bool state)
{
    mouseHovered = state;

    sf::Event& event = GetCurrentEvent();
    if (event.type == sf::Event::MouseButtonPressed)
        mouseClicked = state;
    else if (event.type == sf::Event::MouseButtonReleased)
        mouseReleased = state;
}

std::string fg::Widget::GetWidgetParamStr(fg::Widget::Param param)
{
    std::string sParam = "";
    switch (param)
    {
        case Param::TYPE:
            sParam.assign("typ");
            break;
        
        case Param::POSITION:
            sParam.assign("pos");
            break;
        
        case Param::DIMENSION:
            sParam.assign("dmn");
            break;

        case Param::COLOR:
            sParam.assign("clr");
            break;

        case Param::TEXT_COLOR:
            sParam.assign("tclr");
            break;

        default:
            sParam.assign("None");
            break;
    }

    return sParam;
}

fg::Widget::Param fg::Widget::GetWidgetParam(const std::string& sParam)
{
    Param param;

    if (sParam == "typ")
        param = Param::TYPE;
    else if (sParam == "pos")
        param = Param::POSITION;
    else if (sParam == "dmn")
        param = Param::DIMENSION;
    else if (sParam == "clr")
        param = Param::COLOR;
    else if (sParam == "tclr")
        param = Param::TEXT_COLOR;
    else
        param = Param::NONE;

    return param;
}

fg::Widget::Type fg::Widget::GetWidgetType(const std::string& sType)
{
    Widget::Type type = Widget::Type::NONE;
    std::string _sType(sType);

    std::transform(_sType.begin(), _sType.end(), _sType.begin(), [](char c)
    {
        return std::tolower(c);
    });

    if (_sType == "button")
        type = Widget::Type::BUTTON;
    else if (_sType == "textbox")
        type = Widget::Type::TEXTBOX;
    else if (_sType == "title")
        type = Widget::Type::TITLE;

    return type;
}

sf::Color fg::Widget::GetSFMLColor(const std::string& sColor)
{
    sf::Color sfColor = sf::Color::White;
    std::string _sColor(sColor);

    /* In case of RGBA values. */
    if (_sColor.find(":") != std::string::npos)
    {
        sfColor.r = std::stoi(_sColor.substr(0, _sColor.find(":")));
        _sColor = _sColor.substr(_sColor.find(":") + 1);

        sfColor.g = std::stoi(_sColor.substr(0, _sColor.find(":")));
        _sColor = _sColor.substr(_sColor.find(":") + 1);

        sfColor.b = std::stoi(_sColor.substr(0, _sColor.find(":")));
        _sColor = _sColor.substr(_sColor.find(":") + 1);

        sfColor.a = std::stoi(_sColor);
    }
    else
    {
        std::transform(_sColor.begin(), _sColor.end(), _sColor.begin(), [](char c)
        {
            return std::tolower(c);
        });

        if (_sColor == "white")
            sfColor = sf::Color::White;
        else if (_sColor == "black")
            sfColor = sf::Color::Black;
        else if (_sColor == "red")
            sfColor = sf::Color::Red;
        else if (_sColor == "green")
            sfColor = sf::Color::Green;
        else if (_sColor == "blue")
            sfColor = sf::Color::Blue;
        else if (_sColor == "yellow")
            sfColor = sf::Color::Yellow;
        else if (_sColor == "magenta")
            sfColor = sf::Color::Magenta;
        else if (_sColor == "cyan")
            sfColor = sf::Color::Cyan;
        else if (_sColor == "transparent")
            sfColor = sf::Color::Transparent;
    }

    return sfColor;
}

sf::Vector2f fg::Widget::GetVector2f(const std::string& sVector2)
{
    return sf::Vector2f {
        std::stof(sVector2.substr(0, sVector2.find(":"))),
        std::stof(sVector2.substr(sVector2.find(":") + 1))
    };
}

void fg::Widget::SetGlobalFont(const std::string sFontName)
{
    globalFontName = sFontName;
}

void fg::Widget::SetGlobalFontSize(uint16_t fontSize)
{
    globalFontSize = fontSize;
}

