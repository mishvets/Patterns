#include <iostream>
#include <map>
#include <utility>

using namespace std;

constexpr auto delimiter = " ";
constexpr auto delimiterLen = 1;

struct Sentence
{
    struct WordToken
    {
        bool capitalize;
    };

    Sentence(const string &text) : m_text(text)
    {
    }

    WordToken &operator[](size_t index)
    {
        auto it = m_tokenMap.find(index);
        if (m_tokenMap.end() == it)
        {
            m_tokenMap.insert(pair<size_t, WordToken>(index, WordToken{false}));
        }
        return m_tokenMap.at(index);
    }

    string str() const
    {
        string out{m_text};
        size_t tokenNumber = 0;
        size_t posStart = 0;
        size_t posEnd = 0;
        for (auto token : m_tokenMap)
        {
            if (posEnd == string::npos)
            {
                break;
            }

            while (token.first > tokenNumber && (posEnd = m_text.find(delimiter, posStart)) != string::npos)
            {
                posStart = posEnd + delimiterLen;
                ++tokenNumber;
            }

            if (token.first == tokenNumber)
            {
                posEnd = m_text.find(delimiter, posStart);
                auto length = posEnd == string::npos ? m_text.length() : posEnd;
                for (size_t i = posStart; i <= length; i++)
                {
                    out[i] = token.second.capitalize ? toupper(out[i]) : out[i];
                }
                posStart = posEnd + delimiterLen;
                ++tokenNumber;
            }
        }
        return out;
    }

private:
    map<size_t, WordToken> m_tokenMap;
    string m_text{};
    size_t m_length;
};

int main()
{
    Sentence sentence("hello word hello Word");
    sentence[0].capitalize = true;
    sentence[1].capitalize = true;
    sentence[5].capitalize = true;

    cout << sentence.str() << endl;
    return 0;
}