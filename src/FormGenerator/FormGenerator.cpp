/* FILE: FormGenerator.cpp
 * FormGenertor class implementation.
 */

/* STD includes. */
#include <iostream>

/* FG includes. */
#include "FormGenerator/FormGenerator.hpp"
#include "FormGenerator/Button.hpp"


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
        sf::Event event;
        while (formWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                UnLive();
            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                for (auto widget : widgetVector)
                {
                    if (widget->IsMouseOver(formWindow))
                    {
                        widget->TakeAction();
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                for (auto widget : widgetVector)
                {
                    if (widget->IsMouseOver(formWindow))
                    {
                        // Button released
                        widget->TakeAction();
                    }
                }
            }
        }
    }
}

void fg::FormGenerator::AddWidget(fg::WidgetType widgetType, std::string title, float xPos, float yPos)
{
    if (widgetType == fg::WidgetType::WG_Button)
    {
        widgetVector.push_back(new fg::Button(xPos, yPos, title));
    }
    else if (widgetType == fg::WidgetType::WG_TextBox)
    {
    }
}
