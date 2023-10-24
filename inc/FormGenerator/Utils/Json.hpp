/* File: Json.hpp
 * Header file for json class.
 */

#ifndef JSON_H
#define JSON_H

/* STD includes. */
#include <string>

/* FG includes. */
#include <FormGenerator/Constants.hpp>
#include <FormGenerator/Utils/Config.hpp>


namespace fg::utils
{
    class Json;
}

/* Brief: Json class. */
class fg::utils::Json
{
    public:
        Json();

        /* Enum class for key type specification. */
        enum class Type { STRING, OBJECT, ARRAY };

        void SetString(const std::string& sString);
        void SetType(Type type);

        std::string GetString() const;
        Type GetType() const;
        int GetValueCount() const;

        bool CheckIfKeyExists(const std::string& name) const;

        static bool Read(Json& node, const std::string& fileName, const char sep = ',');

        void Display(uint8_t indentLevel = 0);

        friend class Config;

    private:
        /* Data members. */
        Type objType;                   /*! Object type of node. */
        int valueCount;                 /*! Value count in a node. */
        std::string value;              /*! Value part as string. */
        std::vector<std::pair<std::string, Json>> objectsVec;   /*! Objects vector. */
        std::unordered_map<std::string, size_t> objectsMap;     /*! Objects map to objects vector. */

        /* Private methods. */
        Json& operator[](const std::string& name);
};

#endif // JSON_H
