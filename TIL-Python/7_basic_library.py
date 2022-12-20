import matplotlib.pyplot as plt
import random

plt.plot([1, 5, 7, 3, 7])
plt.show()

# 꺾은선 그래프
sales = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul']
month = [ 3, 5, 4, 7, 8, 5, 6]
plt.figure(dpi=150)
plt.title('Monthly sales')
plt.plot(sales, month, color='y', label='stock level')
plt.legend(loc='lower right')
plt.xlabel('month')
plt.ylabel('amount')
plt.show()

# bar형 그래프
sales = [1, 3, 6, 5, 7]
# month = [3, 4, 5, 6, 7]
plt.title('Monthly Sales')
# plt.bar(range(3, 8), sales, color='b')
plt.barh(range(3, 8), sales, color='b')
plt.show()

b_type = [20, 21, 39, 11]
b_type_name = ['A-type', 'B-type', 'O-type', 'AB-type']
plt.pie(b_type, labels=b_type_name, autopct='%1.1f%%')
plt.show()

# basic scatter plot with python
mathScore = [80, 20, 50, 20, 10, 50, 60, 30, 60]
engScore = [90, 40, 60, 40, 10, 30, 50, 70, 90]
plt.scatter(mathScore, engScore, color='red', alpha=0.5)
plt.xlabel('Math Score')
plt.ylabel('English Score')
plt.show()

# scatter plot with colormap
height, weight = [], []
for i in range(100):
    height.append(random.randint(100, 200))
    weight.append(random.randint(20, 100))
plt.title('Corelation among height and weight')
plt.scatter(height, weight, c=height, cmap='RdPu')
plt.xlabel('height')
plt.ylabel('weight')
plt.show()

singer = ['A', 'B', 'C', 'D', 'E']
week1 = [42, 50, 10, 92, 86]
week2 = [52, 50, 13, 65, 72]
plt.title('Total vote from each week')
plt.plot(singer, week1)
plt.plot(singer, week2)
plt.legend()
plt.show()

height1, weight2, score = [], [], []
for i in range(100):
    height1.append(random.randint(100, 200))
    weight2.append(random.randint(20, 100))
    score.append(random.randint(1, 1000))
plt.title('Relation in between height and weight')
plt.scatter(height1, weight2, s=score, c=score, cmap='rainbow', alpha=0.6)
plt.xlabel('height')
plt.ylabel('weight')
plt.colorbar(label='physical education score')
plt.show()

employee = ['a', 'b', 'c']
incentive2018 = [50, 90, 32]
incentive2019 = [20, 65, 92]

plt.title('Employee additionally paid')
plt.bar(range(1, 8, 3), incentive2018, label='2018')
plt.bar(range(2, 9, 3), incentive2019, lable='2019')
plt.xticks(range(1, 8, 3), employee)
plt.legend()
plt.show()