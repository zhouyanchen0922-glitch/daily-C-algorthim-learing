#设计一个类
class Student:
    name = None
    gender = None
    age = None
    nationality = None
    native_place = None

#创建一个对象
st_1 = Student()

#对象属性进行赋值
st_1.name = "A"
st_1.age = 13
print(st_1.name)
print(st_1.age)

#类里的函数叫做方法
#用类方法的self访问类中成员的变量
class Student:
    name = None  #表示学生姓名(name是一个成员变量）

    # 是一个成员方法
    def say_hi(self):
        print(self.name)

stu = Student()
stu.name = "A"
stu.say_hi()




