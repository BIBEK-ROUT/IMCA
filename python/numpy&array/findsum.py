import numpy as np
demo_arr=np.array([5,3,75,2,8])
demo_arr1=np.array()
min_value=min(demo_arr)
max_value=max(demo_arr)
total_value=sum(demo_arr)
cumilative=0
print("minmum value of the array is:",min_value)
print("maximum value of the array is:",max_value)
print("total value of the array is:",total_value)   
print("Cumulative sum of the array:")
for i in demo_arr:
    cumilative=cumilative+i
    demo_arr1.append(cumilative)
    print(cumilative)
