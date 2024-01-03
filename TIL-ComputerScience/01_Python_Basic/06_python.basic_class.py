class TestClass:
    count = 0

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_age(self):
        print("I am", self.age)

    def get_name(self):
        print("My name is", self.name)

    @staticmethod
    def test_static():
        print("Testing Static Methods")

    # Class method can get to other variables inside class when staticmethod can't
    @classmethod
    def test_class_method(cls):
        print("class method")
        print("count :::", cls.count)

    def __del__(self):
        print("Into the dust")


test = TestClass("Peter", 185, 25)
test.get_age()
test.get_name()
TestClass.test_static()
TestClass.test_class_method()