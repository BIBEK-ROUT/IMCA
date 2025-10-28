import matplotlib.pyplot as plt
plt.style.use('ggplot')  # Set the style to 'ggplot'
# Data
'''x = [1, 2, 3, 4, 5]
y = [10, 20, 25, 30, 40]

# Create plot
plt.plot(x, y)

# Show the plot
plt.show()
# Data'''
x = [1, 2, 3, 4, 5]
y = [10, 20, 25, 30, 40]

# Create plot with style
plt.plot(x, y, marker='o', linestyle='-', color='b', label='Sales', markeredgecolor='red')
plt.legend()  # Show legend
# Labels and title
plt.xlabel("X Axis - Days")
plt.ylabel("Y Axis - Sales")
plt.title("Sales Over Days")

# Show
plt.show()
