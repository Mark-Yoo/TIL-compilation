class A:
    def __init__(self, name):
        print("class A init")
        self.name = name

    def test1(self):
        print("this is test1 function from class A")
        print("so my name is", self.name)
        return 0


# To inherit from its parent, append brackets with parent classes name in it
# when init, use super method to approach parent's variables
class B(A):
    def __init__(self):
        super().__init__("Peter")

    def test2(self):
        print("this is test2 function from class B")
        print("so I would like to get name from A", self.name)


nameGenerator = B()
nameGenerator.test1()
nameGenerator.test2()