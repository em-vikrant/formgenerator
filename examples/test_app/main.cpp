// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/FormGenerator.hpp>


int main(int argc, char *argv[])
{
    fg::FormGenerator form(argv[0]);
    std::cout << "Test App" << std::endl;

    if (form.Create("My Test Form"))
    {
        form.SetWidgetInitText("B1", "MYB1");
        form.SetWidgetInitText("T1", "Write here!");

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
