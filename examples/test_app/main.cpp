// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/FormGenerator.hpp>


int main(int argc, char *argv[])
{
    fg::FormGenerator form(argv[0]);
    std::cout << "Test App" << std::endl;

    if (form.Create("My Test Form"))
    {
        form.SetWidgetInitText("H0", "Registration Form");
        
        form.SetWidgetInitText("H1", "Name");
        form.SetWidgetInitText("T1", "Write your name here!");
        
        form.SetWidgetInitText("H2", "Roll No");
        form.SetWidgetInitText("T2", "Write your roll no. here!");
        
        form.SetWidgetInitText("H3", "Address");
        form.SetWidgetInitText("T3", "Write your address here!");
        
        form.SetWidgetInitText("B1", "Submit");

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
