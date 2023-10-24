/* FILE: Json.cpp
 * Json class implementation.
 */

/* STD includes. */
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

/* FG includes. */
#include <FormGenerator/Utils/Json.hpp>


fg::utils::Json::Json()
{
    valueCount = 0;
}

void fg::utils::Json::SetString(const std::string& sString)
{
    value = sString;
}

void fg::utils::Json::SetType(fg::utils::Json::Type type)
{
    objType = type;
}

std::string fg::utils::Json::GetString() const
{
    return value;
}

fg::utils::Json::Type fg::utils::Json::GetType() const
{
    return objType;
}

int fg::utils::Json::GetValueCount() const
{
    return valueCount;
}

bool fg::utils::Json::CheckIfKeyExists(const std::string& name) const
{
    return (objectsMap.count(name) > 0);
}

fg::utils::Json& fg::utils::Json::operator[](const std::string& name)
{
    /* Check if already exists. If not then add it. */
    if (objectsMap.count(name) == 0)
    {
        objectsMap[name] = objectsVec.size();
        objectsVec.push_back({name, Json()});
    }

    return objectsVec[objectsMap[name]].second;
}

bool fg::utils::Json::Read(fg::utils::Json& rootNode, const std::string& fileName, const char sep)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        return false;
    }

    std::stack<std::pair<uint8_t, std::reference_wrapper<Json>>> stkPath;
    std::reference_wrapper<Json> currentNode = rootNode;
    std::string sPropName = "";
    std::string sPropValue = "";
    uint8_t currLevel = 0;

    /* Push first node on stack. */
    stkPath.push({currLevel, rootNode});

    /* Parse file. */
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);

        /* Remove white spaces from both ends of the string. */
        auto trim = [](std::string& s)
        {
            s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
            s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
        };

        /* Remove quotes from both ends of the string. */
        auto trimQuotes = [](std::string& s)
        {
            s.erase(0, s.find_first_not_of("\""));
            s.erase(s.find_last_not_of("\"") + 1);
        };

        trim(line);

        /* Process line. */
        if (!line.empty())
        {
            size_t x = line.find_first_of(":");
            if (x != std::string::npos)
            {
                sPropName = line.substr(0, x);
                trim(sPropName);
                trimQuotes(sPropName);

                sPropValue = line.substr(x + 1, line.size());
                trim(sPropValue);
                trimQuotes(sPropName);

                bool bInQuotes = false;
                std::string sToken;

                /* Parse value portion char by char. */
                for (const auto c : sPropValue)
                {
                    if (c == '\"')
                    {
                        bInQuotes = !bInQuotes;
                    }
                    else if (bInQuotes)
                    {
                        sToken.append(1, c);
                    }
                    else if (c == sep)
                    {
                        trim(sToken);
                        /* Set value for key node. */
                        Json& node = stkPath.top().second.get()[sPropName];
                        node.SetType(Type::STRING);
                        node.SetString(sToken);
                        node.valueCount++;
                        currentNode.get().valueCount++;
                        sToken.clear();
                    }
                    else if (c == '{')
                    {
                        /* Entered sub json level. */
                        Json& node = stkPath.top().second.get()[sPropName];
                        node.SetType(Type::OBJECT);
                        stkPath.push({currLevel, node});
                        currLevel++;
                        currentNode.get().valueCount++;
                        currentNode = node;
                    }
                    else if (c == '}')
                    {
                        /* When sub json level processed. */
                        stkPath.pop();
                        currLevel--;

                        if (!stkPath.empty())
                            currentNode = stkPath.top().second.get();
                    }
                }

                /* Check if residual token is filled.  If yes, then add it. */
                if (!sToken.empty())
                {
                    trim(sToken);
                    Json& node = stkPath.top().second.get()[sPropName];
                    node.SetType(Type::STRING);
                    node.SetString(sToken);
                    node.valueCount++;
                    currentNode.get().valueCount++;
                }
            }
            else
            {
                if (line[0] == '{')
                {
                    /* Entered sub json level. */
                    if (stkPath.top().first != 0)
                    {
                        Json& node = stkPath.top().second.get()[sPropName];
                        node.SetType(Type::OBJECT);
                        stkPath.push({currLevel, node});
                        currentNode.get().valueCount++;
                        currentNode = node;
                    }

                    currLevel++;
                }
                else if (line[0] == '}')
                {
                    /* When sub json level processed. */
                    stkPath.pop();
                    currLevel--;

                    if (!stkPath.empty())
                        currentNode = stkPath.top().second.get();
                }
                else
                {
                    sPropName = line;
                }
            }
        }
    }

    /* Close file. */
    file.close();

    return true;
}

void fg::utils::Json::Display(uint8_t indentLevel)
{
    for (auto property : objectsVec)
    {
        std::cout << std::string(indentLevel, '\t');
        std::cout << property.first;
        if (property.second.GetType() == Type::STRING)
            std::cout << " : ";
        else if (property.second.GetType() == Type::OBJECT)
            std::cout << "\n";
        
        /* For a string type key value property. */
        if (property.second.objectsVec.empty())
        {
            std::cout << property.second.GetString() << "\n";
        }
        /* In case of sub json. */
        else
        {
            property.second.Display(indentLevel + 1);
        }
    }
}
