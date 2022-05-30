#ifndef __GRAMMAR_HPP
#define __GRAMMAR_HPP
#include <iostream>
#include "String.hpp"
#include "Stack.hpp"

class Grammar
{
    struct Letter
    {
        String str;
        bool terminal;
        bool space;

    public:
        Letter() {}
        Letter(const String &s, bool t, bool sp = true) : str(s), terminal(t) {}
        bool operator==(const Letter &other) const
        {
            return str == other.str && terminal == other.terminal;
        }
    };
    const String initVar;
    Vector<Vector<Letter>> rules;

protected:
    Grammar &addRule(String rule);

public:
    Grammar(const String &start = "S") : initVar(start) {}
    void generateWord(String &buf) const;
};

#endif