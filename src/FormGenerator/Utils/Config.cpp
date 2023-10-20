/* FILE: Config.cpp
 * Config class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>
#include <fstream>

/* FG includes. */
#include <FormGenerator/Utils/Config.hpp>


fg::utils::Config::Config()
{
    std::string rootCfgFile = std::string(ROOT_PATH) + "/" + CONFIG_FILE;
    fg::utils::Json rootNode;
    
    isConfigPresent = false;
    fg::utils::Json::Read(rootNode, rootCfgFile);
    // rootNode.Display();

    /* Fetch app name list from the config file. */
    if (rootNode.CheckIfKeyExists("app"))
    {
        if (rootNode["app"].CheckIfKeyExists("dir"))
        {
            appDir = std::string(ROOT_PATH) + "/" + rootNode["app"]["dir"].GetString();

            /* Get the current application name and config paths. */
            for (int idx = 0; idx < rootNode["app"].GetValueCount(); idx++)
            {
                std::string appId = "app" + std::to_string(idx);
                if (rootNode["app"].CheckIfKeyExists(appId))
                {
                    if (rootNode["app"][appId].CheckIfKeyExists("title"))
                    {
                        std::string sAppPath = appDir + "/" +
                                rootNode["app"][appId]["title"].GetString() + "/" +
                                CONFIG_FILE;
                        std::ifstream f(sAppPath);
                        if (f.good())
                        {
                            appTitle = rootNode["app"][appId]["title"].GetString();
                            appConfig = sAppPath;
                            isConfigPresent = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

bool fg::utils::Config::ConfigureCurrentApp()
{
    if (!isConfigPresent)
        return false;
    
    std::cout << "CONFIG, Configuring app = " << appTitle << std::endl;
    appNode = std::make_shared<fg::utils::Json>();
    fg::utils::Json::Read(*appNode, appConfig);
    // appJson.Display();
    return true;
}

std::string fg::utils::Config::GetValueFromKey(const std::string& key) const
{
    std::string value = "";
    fg::utils::Json node = *appNode;
    
    if (node.CheckIfKeyExists(key))
    {
        value.assign(node[key].GetString());
    }

    return value;
}

std::vector<std::pair<std::string, std::string>> 
fg::utils::Config::GetValuesFromKey(const std::string& key) const
{
    fg::utils::Json node = *appNode;
    std::vector<std::pair<std::string, std::string>> valueVec;

    if (node.CheckIfKeyExists(key))
    {
        fg::utils::Json subNode = node.objectsVec[node.objectsMap[key]].second;
        for (auto property : subNode.objectsVec)
        {
            /* Fill value vector with key values of subjson. */
            if (property.second.GetType() == fg::utils::Json::Type::STRING)
            {
                valueVec.emplace_back(property.first, property.second.GetString());
            }
        }
    }

    return valueVec;
}
