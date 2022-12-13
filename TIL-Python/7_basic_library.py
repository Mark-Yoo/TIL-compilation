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