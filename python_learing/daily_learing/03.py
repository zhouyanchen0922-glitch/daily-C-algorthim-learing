#使用构造方法对成员变量进赋值
#构造方法：__init__(self)

class Student:
    def __init__(self,name,age):
        self.name = name  ##使用__init__(self),不需要提前声明申明成员变量
        self.age = age

stu = Student("A","21")


#继承（单继承）
#父类名
class Phone:
    IMEI = None
    producer = "HH"

    def call_by_4g(self):
        self.IMEI = "A"

#子类名
class Phone2022(Phone):
    face_id = "10001"

    def call_by_5g(self):
        print("2022的新功能")

phone = Phone2022()
print(phone.producer)
phone.call_by_5g()
#单继承是一个子类继承了一个父类
#多继承是一个子类继承了多个父类

#复写：子类对父类的成员变量或者成员方法的改写
class phone:
    producer = "HH"
    def call_by_5g(self):
        print("使用5g网络进行通话")

class Phone2022(Phone):
    producer = "AA"  #使用复写对父类producer的改写
    def call_by_5g(self):
        print("使用5g网络进行通话和视频") #使用复写对父类成员方法进行改写

myphone = Phone2022()
print(myphone.producer)
myphone.call_by_5g()

#对基础数据类型进行注解
var_1: int = 10
var_2: float = 20.0
var_3: bool = True
var_4: str = "sfrdcg"

#对类的对象数据
class Student:
    pass
stu: Student = Student()

#多态：使用同样的函数，传入不同的对象，得到不同的状态
#以父类做申明的定义
#以子类做实际的工作
#达到同一个行为，不同的状态
class Animal:
    def speak(self):
        pass  #空实现
              #抽象类，顶层设计

class Dog(Animal):
    def speak(self):
        print("汪汪汪")

class Cat(Animal):
    def speak(self):
        print("喵喵喵")

def make_noise(animal):
    animal.speak()  #具体子类实现（实现标准）

dog = Dog()
cat = Cat()
make_noise(dog)
make_noise(cat)
