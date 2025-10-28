import matplotlib.pyplot as plt
import numpy as np

# Sample data
x = np.arange(1, 6)
y = np.array([3, 7, 2, 5, 8])

# 1. Line Plot
plt.figure(figsize=(10, 6))
plt.plot(x, y, color='blue', linestyle='--', linewidth=2, marker='o', markersize=8,
         markerfacecolor='yellow', markeredgecolor='red', label='Line Plot Example')
plt.title('Line Plot Example', fontsize=16)
plt.xlabel('X-axis', fontsize=12)
plt.ylabel('Y-axis', fontsize=12)
plt.legend()
plt.grid(True)
plt.show()
# 2. Bar Graph
plt.figure(figsize=(10, 6))
plt.bar(x, y, color='skyblue', edgecolor='black', width=0.5, align='center', label='Bar Example')
plt.title('Bar Graph Example', fontsize=16)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.show()

# 3. Scatter Plot
plt.figure(figsize=(10, 6))
plt.scatter(x, y, color='red', marker='D', s=100, edgecolor='black', alpha=0.7, label='Scatter Example')
plt.title('Scatter Plot Example', fontsize=16)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.grid(True)
plt.show()

# 4. Histogram
data = np.random.randn(1000)  # Normal distribution data
plt.figure(figsize=(10, 6))
plt.hist(data, bins=20, color='purple', edgecolor='black', alpha=0.7, rwidth=0.9)
plt.title('Histogram Example', fontsize=16)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.grid(axis='y', alpha=0.75)
plt.show()

# 5. Pie Chart
sizes = [20, 30, 25, 25]
labels = ['Apples', 'Bananas', 'Cherries', 'Dates']
colors = ['gold', 'lightgreen', 'lightcoral', 'lightskyblue']
explode = (0, 0.1, 0, 0)  # "explode" 2nd slice

plt.figure(figsize=(8, 8))
plt.pie(sizes, labels=labels, colors=colors, explode=explode, autopct='%1.1f%%',
        shadow=True, startangle=90)
plt.title('Pie Chart Example', fontsize=16)
plt.show()
