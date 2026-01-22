#python基本方法
from ctypes import pythonapi
from operator import index

#strip方法
my_str = "  fid s sda  "
new_my_str = my_str.strip()#不传入参数，去掉首尾空格
print(new_my_str)
my2_str =  "12sfeafeq21"
new2_str = my2_str.strip("12")#去除my_str首尾的12
print(new2_str)

#split方法
my_str = "  fid s sda  "
new_my_str = my_str.split(" ")#依据split方法将字符串按空格分成list
print(new_my_str)

#replace方法
my_str = "itfa ifatit sfaitdsf"
new_my_str = my_str.replace("it", "程序")
print(new_my_str)

#统计字符串中某个字符串的次数，count()
my_str = "itfa ifatit sfaitdsf"
count = my_str.count("it")
print(count)

#统计字符串的长度，len()
num = len(my_str)
print(num)

#方法index()查找特定字符串的下标
my3_str = "asdfghjkl"
num  = my3_str.index("f")
print(num)

#序列的切片操作（从指定元素开始，到指定位置结束）
#起始下标：表示从何处开始，可以留空，留空表示从头开始
#结束下标：表示从何处结束，可以留空，留空表示从末尾结束
#步长：取元素的间隔（N表示跳过N-1个元素取)
my_list = [0,1,2,3,4,5,6,7,8,9]
result = my_list[1:4] #从下标1开始取，取到4不包含4，步长为1，可以省略
print(result)


#从头开始，到末尾结束，步长为1（切片）
my_list = [0,1,2,3,4,5,6,7,8,9]
result = my_list[:]
print(result)

#从头开始，到尾结束，步长为2
my_list = [0,1,2,3,4,5,6,7,8,9]
result2 = my_list[::2]
print(result2)

#步长为-1，等同于将序列反转
my_list = [0,1,2,3,4,5,6,7,8,9]
result3 = my_list[::-1]
print(result3)

#集合用{},无序，所以不支持下标索引

#在集合中用.add()方法添加新的元素
my_set = {0,1,2,3,4,5,6,7,8,9,9}
my_set.add("python")
print(my_set)

#在集合中用.remove()方法移除元素
my_set = {0,1,2,3,4,5,6,7,8,9,"python"}
my_set.remove("python")
print(my_set)

#集合中用.pop()方法随机取出一个元素
my_set = {0,1,2,3,4,5,6,7,8,9,"python"}
num = my_set.pop()
print(num)
print(my_set)#取出的元素将不会在集合中

#集合1.difference(集合2)，功能：取出集合1和集合2的差集(集合1没有集合2有的)
set1 = {1,2,3}
set2 = {1,2,4}
set3 = set1.difference(set2)
print(set3)  #结果{3}

#集合1.difference_update(集合2)
#功能：在集合1内删除与集合2相同的元素
set1 = {1,3,5}
set2 = {1,2,4}
set1.difference_update(set2)
print(set1)

#集合1.union(集合2)
#功能：将集合1和集合2组成新的集合
set1 = {1,3,5}
set2 = {1,2,4}
set3 = set1.union(set2)
print(set3)

#集合不支持下标索引，不能使用while循环
#但是可以使用for循环

#字典的组成：key+value，功能：找key取value
#python中字典的key不能重复
dict1 = {"Q":99,"A":88}
score = dict1["Q"]
print(score)
#字典的key和value可以是任意数据(key不可为字典)

#定义嵌套字典
stu_score_dict = {
    "Q":{
        "语文":68,
        "数学":98,
        "英语":78
    },
    "A":{
        "语文":67,
        "数学":78,
        "英语":98
    },
    "F":{
        "语文":98,
        "数学":64,
        "英语":88
    }
}
#看Q的语文成绩
score= stu_score_dict["Q"]["语文"]
print(score)

#获取全部的key,方法.keys()
keys = stu_score_dict.keys()
print(keys)

import json
#准备列表，列表每一个元素都是字典，将其转换为JSON
data = [{"name":"张","age":13},{"name":"私发","age":14},{"name":"讲台","age":46}]
json_data = json.dumps(data)
print(json_data)
