// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/FormGenerator.hpp>

int main()
{
    fg::FormGenerator form;
    std::cout << "Hello World!" << std::endl;
    form.Create("My Form", static_cast<fg::FormDimensions>(fg::FormDimensions{600, 400}));

    std::cout << "Adding a button for testing\n";
    form.AddWidget(fg::WidgetType::WG_Button, "My Button", 100.0f, 100.0f);

    while (form.IsLive() == true)
    {
        form.Update();
        form.Display();
    }

    form.Close();
    return 0;
}
