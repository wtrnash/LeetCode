"""
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

"""

# 解答：首先记录每行开始的索引，用current记录当前的长度和，由于每两个单词之间至少有一个空格，所以记录长度时先加上该空格。
# 等current 加上第i个单词 超过了maxWidth的长度，即说明该行已满。然后由于之前每个单词加了一个空格，用current 减去单词数计算当前的空格数
# 然后空格数除以(单词数-1)是单词之间的空格数，只有一个单词要单独处理，全部把空格放后面；然后由于题意要求是左边比右边空格多，而且
# 是下述的形式，比如5个空格，3个单词，那么空格分布是2 2 1而不是 3 1 1。 所以在所有单词中间加上了基准空格后
# 再给前面余下的空格的数量的单词 空格数 +1
# 最后一行也要单独处理
class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        current = 0
        space = 0
        space_between_words = 0
        left_space = 0
        start = 0
        result = []
        for i in range(len(words)):
            if current + len(words[i]) > maxWidth:
                word_nums = i - start
                current = current - word_nums
                space = maxWidth - current
                if word_nums == 1:
                    space_between_words = space
                else:
                    space_between_words = space // (word_nums - 1)
                    left_space = space - space_between_words * (word_nums - 1)
                
                temp = []
                for j in range(start, i - 1):
                    temp.append(words[j])
                    if j < start + left_space:
                        temp.append(" " * (space_between_words + 1))
                    else:
                        temp.append(" " * space_between_words)
                
                temp.append(words[i - 1])
                if word_nums == 1:
                    temp.append(" " * space)
                
                result.append("".join(temp))
                start = i
                current = len(words[i]) + 1
            else:
                current = current + len(words[i]) + 1
        
        temp = []
        for j in range(start, len(words) - 1):
            temp.append(words[j] + " ")
        
        temp.append(words[len(words) - 1] + (maxWidth - (current - 1)) * " ")
        result.append("".join(temp))
        
        return result