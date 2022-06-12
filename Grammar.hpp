#ifndef __GRAMMAR_HPP
#define __GRAMMAR_HPP
#include <iostream>
#include "String.hpp"
#include "Stack.hpp"

/// class representing context-free grammar having rules for word generation
class Grammar
{
    struct Letter
    {
        String str;
        bool terminal;
        bool space;

    public:
        Letter() {}
        Letter(const String &s, bool t, bool sp = true) : str(s), terminal(t), space(sp) {}
        bool operator==(const Letter &other) const
        {
            return str == other.str && terminal == other.terminal;
        }
    };
    const String initVar;
    Vector<Vector<Letter>> rules;

protected:
    /// adds a new rule to the list of rules; multiple rules are allowed divided by '|' and after each letter (0|1|2) must be typed specifying if the letter is variable (1), terminal with space (1) or terminal without space (2)
    Grammar &addRule(String rule);

public:
    /// constructor of grammar based on initial variable ('S' by default)
    Grammar(const String &start = "S") : initVar(start) {}
    /// get random word from the language of the grammar
    void generateWord(String &buf) const;
};

#endif