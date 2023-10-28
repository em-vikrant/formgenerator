/* FILE: FormGenerator.cpp
 * FormGenertor class implementation.
 */

/* STD includes. */
#include <iostream>

/* FG includes. */
#include <FormGenerator/Button.hpp>
#include <FormGenerator/TextBox.hpp>
#include <FormGenerator/FormGenerator.hpp>


fg::FormGenerator::FormGenerator(std::string sAppPath)
    : formTitle("Untitled"), isLive(false), configFlag(false)
{
    sAppName = sAppPath;
    sAppName = sAppName.substr(sAppName.find_last_of("/") + 1);

    /* Configure the project. */
    pConfig = std::make_shared<fg::utils::Config>();
    
    /* On successful configuration of application. */
    if (pConfig->ConfigureApp(sAppName))
    {
        /* Get the form dimensions. */
        std::string sFormDimension = pConfig->GetValueFromKey("fdm");
        width = std::stoi(sFormDimension.substr(0, sFormDimension.find(":")));
        height = std::stoi(sFormDimension.substr(sFormDimension.find(":") + 1));

        /* Get the font & font size. */
        std::string font = pConfig->GetValueFromKey("fnt");
        uint16_t fontSize = std::stoi(pConfig->GetValueFromKey("fsz"));

        /* Set gloabl font parameters for widgets. */
        oWidgetManager.SetGlobalFontParms(font, fontSize);

        /* Add widgets to widget manager for each config key. */
        for (std::string key : pConfig->GetSubJsonKeys())
        {
            bool ret = oWidgetManager.AddWidget(key, pConfig->GetValuesFromKey(key));
            widgetKeys.push_back({key, ret});
        }

        configFlag = true;
    }
}

fg::FormGenerator::~FormGenerator()
{
}

// TODO: better design thinking for below function.
void fg::FormGenerator::SetWidgetInitText(const std::string sWidgetKey, const std::string sText)
{
    for(auto itr = widgetKeys.begin(); itr != widgetKeys.end(); itr++)
    {
        if (itr->first == sWidgetKey && itr->second)
        {
            oWidgetManager[sWidgetKey]->SetWidgetInitText(sText);
            break;
        }
    }
}

bool fg::FormGenerator::Create(std::string title)
{
    bool ret = false;

    /* Create form if application is configured successfully. */
    if (configFlag)
    {
        formTitle = sf::String(title);
        formWindow.create(sf::VideoMode(width, height), formTitle);

        /* Set form live. */
        isLive = true;
        ret = true;
    }

    return ret;
}

void fg::FormGenerator::Display()
{
    /* Fill the from with background color. */
    formWindow.clear(sf::Color::White);

    /* Draw widgets on form. */
    for (auto key : widgetKeys)
    {
        if (key.second)
        {
            fg::Widget& widget = *(oWidgetManager[key.first]);
            if (widget.IsLive())
            {
                widget.Draw(formWindow);
            }
        }
    }

    /* Render the form. */
    formWindow.display();
}

void fg::FormGenerator::Close()
{
    if (IsLive() == false)
        formWindow.close();
}

void fg::FormGenerator::Update()
{
    if (formWindow.isOpen())
    {
        while (formWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    UnLive();
                    break;

                case sf::Event::MouseButtonPressed:
                case sf::Event::MouseButtonReleased:
                case sf::Event::TextEntered:
                    {
                        for (auto key : widgetKeys)
                        {
                            if (key.second)
                            {
                                fg::Widget& widget = *(oWidgetManager[key.first]);
                            
                                /* 1. Let the widget handle events at their own will. */
                                widget.SetCurrentEvent(event);

                                /* 2. Set the mouse state. */
                                widget.SetMouseState(widget.IsMouseOver(formWindow));

                                /* Let the widget act accordingly. */
                                widget.TakeAction();
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        }
    }
}

