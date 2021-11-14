#include <iostream>
#include <vector>
#include <string>

class CombinationIterator {
public:
    std::vector<int> ptr;
    bool m_has_next = true;
    std::string m_next_str = "";
    std::string m_characters;
    int m_comboLength;
    int m_char_length;
    std::vector<int> m_last_run;
    std::vector<int> m_last_shown;

public:
    CombinationIterator(std::string characters, int combinationLength) {
        this->m_comboLength = combinationLength;
        this->m_characters = characters;
        this->ptr.reserve(combinationLength);
        this->m_char_length = characters.length();

        for (int i = 0; i < this->m_comboLength; i++)
        {
            this->ptr.push_back(i);
        }

        this->getNext();
        if (this->m_next_str != "") this->m_has_next = true;

        this->m_last_run.reserve(combinationLength);
        for (int i = 0; i < this->m_comboLength; i++)
        {
            this->m_last_run.push_back(this->m_char_length + i - this->m_comboLength);
        }
    }

    void getNext() {
        for (int i : this->ptr)
        {
            this->m_next_str += this->m_characters[i];
        }
    }

    std::string next() {
        std::string current = this->m_next_str;
        this->m_last_shown = this->ptr;
        this->m_next_str = "";
        for (int i = this->m_comboLength - 1; i >= 0; i--)
        {
            std::cout << "Currently on index " << i << std::endl;
            if (this->ptr[i] < this->m_char_length + i - this->m_comboLength)
            {
                this->ptr[i] += 1;
                for (int j = i + 1; j < this->m_comboLength; j++)
                {
                    
                    this->ptr[j] = this->ptr[j - 1] + 1;
                }
                break;
            }
        }
        this->getNext();
        if (current == this->m_next_str) this->m_has_next = false;
        return current;
    }

    bool hasNext() {

        if (this->m_last_run == this->m_last_shown) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    

    std::string txt = "abcde";
    int n = 2;

    CombinationIterator it(txt, n);
    int i = 0;
    while (i < 11)
    {
        std::string tmp = it.next();
        std::cout << tmp << std::endl;
        bool flag = it.hasNext();
        std::cout << flag << std::endl;
        i++;
    }
}
