#include "Grammar.hpp"

Grammar &Grammar::addRule(String rule)
{
    char *ruleBeg = rule.c_str();
    char *ruleEnd = ruleBeg;
    char *const LeftVar = ruleBeg;
    while (*ruleEnd && *ruleEnd != '-')
        ++ruleEnd;
    assert(*ruleEnd);
    *ruleEnd++ = '\0';
    while (*ruleEnd)
    {
        ruleBeg = ++ruleEnd;
        Vector<Letter> tmp;
        tmp.push_back(Letter(LeftVar, false));
        while (*ruleEnd && *ruleEnd != '|')
        {
            while (*ruleEnd && *ruleEnd != '(')
                ++ruleEnd;
            assert(*ruleEnd);
            *ruleEnd++ = '\0';
            tmp.push_back(Letter(ruleBeg, *ruleEnd != '0', *ruleEnd != '2'));
            ++ruleEnd;
            ruleBeg = ++ruleEnd;
        }
        rules.push_back(tmp);
    }
    return *this;
}

void Grammar::generateWord(String &buf) const
{
    buf = String();
    Stack<Letter> st;
    st.push(Letter(initVar, false));
    Letter read("", true);
    while (!st.empty())
    {
        read = st.top();
        st.pop();
        if (read.terminal)
        {
            if (*read.str.c_str())
            {
                buf += read.str;
                if (read.space)
                    buf += " ";
            }
        }
        else
        {
            unsigned num = rand() % rules.size();
            while (!((rules[num])[0].str == read.str &&
                     (rules[num])[0].terminal == read.terminal))
                num = rand() % rules.size();
            for (unsigned i = rules[num].size() - 1; i > 0; --i)
                st.push(rules[num][i]);
        }
    }
}