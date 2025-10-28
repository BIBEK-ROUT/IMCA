import matplotlib.pyplot as plt
import numpy as np

# Sample data
categories = ['A', 'B', 'C', 'D']
values = [10, 15, 7, 12]
errors = [1.5, 2.0, 1.0, 1.2]  # error bars

# Create figure
fig, ax = plt.subplots(figsize=(8, 6))

bars = ax.bar(
    x=categories,               # X positions (can be array-like)
    height=values,              # Heights of bars
    width=0.6,                   # Width of bars
    bottom=2,                    # Where bars start (offset)
    align='center',              # 'center' or 'edge'
    color='skyblue',             # Single color for all bars
    edgecolor='black',           # Border color of bars
    linewidth=1.5,               # Border thickness
    tick_label=categories,       # Labels for x-axis
    label='My Data',             # Legend label
    alpha=0.85,                  # Transparency (0 to 1)
    zorder=3,                    # Drawing order
    hatch='//',                  # Pattern fill
    orientation='vertical',      # 'vertical' or 'horizontal'
)

# Adding error bars manually
ax.errorbar(categories, values, yerr=errors, fmt='none', ecolor='red', capsize=5)

# Add title and labels
ax.set_title("Bar Chart Example with All Parameters", fontsize=14, fontweight='bold')
ax.set_xlabel("Categories")
ax.set_ylabel("Values")

# Add legend
ax.legend()

# Grid for clarity
ax.grid(True, which='major', axis='y', linestyle='--', alpha=0.7)

# Show plot
plt.show()
