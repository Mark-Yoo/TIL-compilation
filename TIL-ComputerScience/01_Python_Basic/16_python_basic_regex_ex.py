import re

# # Find any alphabets in lowercase
# p = re.compile("[a-z]+")
# m = p.search("5 python")
# # start of where the pattern matched (in index)
# print(m.start())
# # end of where the patter matched (in index)
# print(m.end())
# print(m.start() + m.end())


# p = re.compile("a[a-c]{3,}")
# print(p.match("acccb"))
# print(p.match("a....b"))
# print(p.match("aaaaab"))
# print(p.match("abc"))


data = """
park 010-1234-5678
kim 010-1111-2222"""
p = re.compile('(\w+)\s(\d+[-]\d+)[-](\d+)')
print(p.sub("\g<2>-**** \g<1>", data))
print(p.match('park 010-1234-5678'))
