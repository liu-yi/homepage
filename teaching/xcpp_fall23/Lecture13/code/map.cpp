#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    // 内定一段文本
    std::string text = "C++ is a powerful language. C++ is used for various applications. Applications written in C++ include games and software.";

    // 统计每个单词出现的次数
    // std::unordered_map<std::string, int> wordCount;
    std::map<std::string, int> wordCount;

    // 统计每个单词出现的次数
    size_t pos = 0;
    while (pos < text.size())
    {
        // 找到下一个单词的起始位置
        size_t start = text.find_first_not_of(". \t\n", pos);
        if (start >= text.size())
        {
            break;
        }

        // 找到下一个单词的结束位置
        size_t end = text.find_first_of(". \t\n", start);

        // 提取单词
        std::string word = text.substr(start, end - start);

        // 将单词转换为小写以保持一致性
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // 更新单词出现次数
        wordCount[word]++;

        // 移动到下一个单词
        pos = end;
    }

    // 使用自定义比较函数按照出现次数从高到低排序
    auto compareByCount = [](const auto &a, const auto &b)
    {
        return a.second > b.second;
    };

    cout << "original: " << endl;
    for (const auto &pair : wordCount)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 将map转换为vector，并使用std::sort排序
    std::vector<std::pair<std::string, int>> sortedWords(wordCount.begin(), wordCount.end());
    std::sort(sortedWords.begin(), sortedWords.end(), compareByCount);

    // 输出排序后的结果
    std::cout << "单词出现次数统计：" << std::endl;
    for (const auto &pair : sortedWords)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
