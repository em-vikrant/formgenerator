// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/FormGenerator.hpp>
#include <FormGenerator/Utils/Logger.hpp>


int main(int argc, char *argv[])
{
    fg::FormGenerator form(argv[0]);

    form.SetWidgetInitText("H0", "Registration Form");
    
    form.SetWidgetInitText("H1", "Name");
    form.SetWidgetInitText("T1", "Input name here!");
    
    form.SetWidgetInitText("H2", "Roll No");
    form.SetWidgetInitText("T2", "Input roll no. here!");
    
    form.SetWidgetInitText("H3", "Address");
    form.SetWidgetInitText("T3", "Input address here!");

    form.SetWidgetInitText("B1", "Submit");

    if (form.Create("Test App"))
    {
        while (form.IsLive() == true)
        {
            form.Update();
            form.Display();
        }

        form.Close();
    }
    else
        std::cerr << "Failed to create form!\n";

    return 0;
}
