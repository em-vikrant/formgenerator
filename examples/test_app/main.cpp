// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/FormGenerator.hpp>

int main()
{
    fg::FormGenerator form;
    std::cout << "Hello World!" << std::endl;
    form.Create("My Form", static_cast<fg::FormDimensions>(fg::FormDimensions{800, 600}));

    form.AddWidget(fg::WidgetType::WG_Button, "My Button", 300.0f, 500.0f);
    form.AddWidget(fg::WidgetType::WG_TextBox, "My TextBox", 250.0f, 400.0f);

    while (form.IsLive() == true)
    {
        form.Update();
        form.Display();
    }

    form.Close();
    return 0;
}
