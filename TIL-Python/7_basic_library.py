import matplotlib.pyplot as plt
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

mathScore = [80, 20, 50, 20, 10, 50, 60, 30, 60]
engScore = [90, 40, 60, 40, 10, 30, 50, 70, 90]
plt.scatter(mathScore, engScore, color='red', alpha=0.5)
plt.xlabel('Math Score')
plt.ylabel('English Score')
plt.show()