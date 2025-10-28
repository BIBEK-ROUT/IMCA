import matplotlib.pyplot as plt
import numpy as np
x1=np.array([160,165,170,180,185])
y1=np.array([55,58,69,63,70])
x2=np.array([150,175,134,156,167])
y2=np.array([45,67,89,54,88])
plt.scatter(x1,y1,color='blue',edgecolor='black',label='First')
plt.scatter(x2,y2,color='red',edgecolor='black',label='Second')
plt.xlabel('Height in(cm)')
plt.ylabel('Weight in (kg)')
plt.title('Height v/s Weight')
plt.legend()
plt.show()