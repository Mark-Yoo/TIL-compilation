import matplotlib.pyplot as plt
plt.plot([1, 5, 7, 3, 7])
plt.show()

sales = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul']
month = [ 3, 5, 4, 7, 8, 5, 6]
plt.figure(dpi=150)
plt.title('Monthly sales')
plt.plot(sales, month, color='y', label='stock level')
plt.legend(loc='lower right')
plt.show()