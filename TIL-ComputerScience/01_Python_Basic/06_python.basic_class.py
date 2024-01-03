class TestClass:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_age(self):
        print("I am", self.age)

    def get_name(self):
        print("My name is", self.name)

    def __del__(self):
        print("Into the dust")


test = TestClass("Peter", 185, 25)
test.get_age()
test.get_name()