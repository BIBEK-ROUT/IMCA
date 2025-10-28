import matplotlib.pyplot as plt
import numpy as np
data=np.random.randn(1000)
plt.hist(data,bins=40,color='yellow', edgecolor='black')
plt.xlabel('Vlaues')
plt.ylabel('Frequency')
plt.title('No. of Values generated')
plt.legend()
plt.show()