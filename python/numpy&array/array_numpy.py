import numpy as np
arr=np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15])
print(arr)
n=arr.reshape(3,5)
print(n)
import pandas as pd

mydata = {
    'student-name': ["abc", "xyz"],
    'roll_number': [11, 12]
}
dataset = pd.DataFrame(mydata)
print(dataset)
data=[1,2,3,4,5,6,7,8,9,10]
dframe = pd.DataFrame(data, columns=['numbers'])
print(dframe)
dframe['squared'] = dframe['numbers'] ** 2
print(dframe)