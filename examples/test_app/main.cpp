// This is a example file to check the FormGenerator library
#include <iostream>
#include <FormGenerator/Utils/Json.hpp>
#include <FormGenerator/Utils/Config.hpp>
#include <FormGenerator/FormGenerator.hpp>

int main()
{
    fg::FormGenerator form;
    std::cout << "Test App" << std::endl;

    // form.Create("Test Application Form");
    fg::utils::Config config;
    config.ConfigureCurrentApp();

    std::vector<std::string> keysVec = {"B1", "T1"};    
    std::for_each(keysVec.begin(), keysVec.end(), [&](std::string& key)
    {
        std::cout << "MAIN, Fetching values of " << key << std::endl;
        for (auto kvPair : config.GetValuesFromKey(key))
        {
            std::cout << kvPair.first << " = " << kvPair.second << std::endl;
        }
    });

    return 0;
}
