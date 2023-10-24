/* File: Config.hpp
 * Header file for config class.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* STD includes. */
#include <string>
#include <vector>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Utils/Json.hpp>


namespace fg::utils
{
    class Json;
    class Config;
}

/* Brief: Config class. */
class fg::utils::Config
{
    public:
        Config();

        bool ConfigureApp(const std::string& sAppName);
        
        /* Get value from a key present at root level. */
        std::string GetValueFromKey(const std::string& key) const;

        /* Get all keys that are sub json node type. */
        std::vector<std::string> GetSubJsonKeys() const;

        /* Get values from a key in case its a sub node. */
        std::vector<std::pair<std::string, std::string>> 
        GetValuesFromKey(const std::string& key) const;

    private:
        std::shared_ptr<fg::utils::Json> appNode;           /*! Act as root node for the application. */
        std::vector<std::pair<std::string, bool>> appsVec;  /*! List of all the apps and the config file flag. */
        std::string appDir;                                 /*! Directory containing application. */
        std::string appConfig;                              /*! Application config file path. */
        std::string appTitle;                               /*! Application title. */
};

#endif // CONFIG_H
