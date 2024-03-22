#include "string.h"
#include <cstring>

namespace HomeMadeString
{
    String::String()
    {
        elementNum = 0;
        pData = nullptr;
    }

    String::String(const char *original)
    {
        elementNum = strlen(original);
        pData = new char[elementNum + 1];
        strcpy(pData, original);
    }

    String::String(char c, unsigned times)
    {
        elementNum = times;

        pData = new char[elementNum + 1];

        for (size_t i = 0; i < elementNum; i++)
            pData[i] = c;

        pData[elementNum] = '\0';
    }

    String::String(const String &original)
    {
        pData = nullptr;
        copy(*this, original);
    }

    String::~String()
    {
        delete[] pData;
    }

    void String::print(std::ostream &os) const
    {
        os << getCString();
    }

    const char *String::getCString() const
    {
        if (pData == nullptr)
            return "";
        return pData;
    }

    size_t String::getLength() const
    {
        return elementNum;
    }

    void String::copy(String &Dest, const String &Src)
    {
        if (&Src == &Dest)
            return;

        Dest.elementNum = Src.elementNum;

        delete[] Dest.pData;

        Dest.pData = new char[Dest.elementNum + 1];

        strcpy(Dest.pData, Src.getCString());
    }

    bool String::compare(const String &s1, const String &s2)
    {
        return strcmp(s1.getCString(), s2.getCString()) == 0;
    }

    String String::concatenate(const String &s1, const String &s2)
    {
        String res;

        res.elementNum = s1.elementNum + s2.elementNum;

        res.pData = new char[res.elementNum + 1];

        strcpy(res.pData, s1.getCString());
        strcat(res.pData, s2.getCString());

        return res;
    }

    char String::at(unsigned idx) const
    {
        if (idx >= elementNum)
            throw "String overindexed!";

        return pData[idx];
    }
}