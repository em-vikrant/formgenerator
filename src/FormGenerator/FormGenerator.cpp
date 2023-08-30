/* FILE: FormGenerator.cpp
 * FormGenertor class implementation.
 */

/* STD includes. */
#include <iostream>

/* FG includes. */
#include "FormGenerator/Button.hpp"
#include "FormGenerator/TextBox.hpp"
#include "FormGenerator/FormGenerator.hpp"


fg::FormGenerator::FormGenerator()
{
    this->formTitle = sf::String("Untitled");
    isLive = false;
}

fg::FormGenerator::~FormGenerator()
{
}

void fg::FormGenerator::Create(std::string title, fg::FormDimensions dimensions)
{
    this->formTitle = sf::String(title);
    formWindow.create(sf::VideoMode(dimensions.width, dimensions.height), formTitle); 
    isLive = true;
}

void fg::FormGenerator::Display()
{
    /* Fill the from with background color. */
    formWindow.clear(sf::Color::White);

    /* Draw widgets on form. */
    for (auto widget : widgetVector)
    {
        if (widget->IsLive())
        {
            widget->Draw(formWindow);
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
                        for (auto widget : widgetVector)
                        {
                            /* 1. Let the widget handle events at their own will. */
                            widget->SetCurrentEvent(event);

                            /* 2. Set the mouse state. */
                            widget->SetMouseState(widget->IsMouseOver(formWindow));

                            /* Let the widget act accordingly. */
                            widget->TakeAction();
                        }
                    }
                    break;

                default:
                    break;
            }
        }
    }
}

void fg::FormGenerator::AddWidget(fg::WidgetType widgetType, std::string title, float xPos, float yPos)
{
    if (widgetType == fg::WidgetType::WG_Button)
    {
        widgetVector.push_back(std::make_shared<fg::Button>(xPos, yPos, title));
    }
    else if (widgetType == fg::WidgetType::WG_TextBox)
    {
        widgetVector.push_back(std::make_shared<fg::TextBox>(xPos, yPos, title));
    }
}
