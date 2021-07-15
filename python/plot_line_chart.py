import numpy as np
import matplotlib.pyplot as plt

# 这里导入你自己的数据
x = np.arange(1, 10, 0.01)
y1 = np.log2(x)
y2 = x

assert len(x) == len(y1) and len(x) == len(y2)

# 开始画图
plt.title('O(log n) vs. O(n)')
plt.plot(x, y1, color='red', label='O(log n)')
plt.plot(x, y2, color='blue', label='O(n)')
# 显示图例
plt.legend()

plt.xlabel('x')
plt.ylabel('y')
plt.show()
