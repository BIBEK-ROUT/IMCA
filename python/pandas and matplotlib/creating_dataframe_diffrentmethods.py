#creating dataframes using diffrent methods
import numpy as np
import pandas as pd
dataframe=pd.DataFrame(
    {
        "Name":["Alice","bob"],
        "age":[20,21]
    }
)
print(dataframe)
#from numpyarray
arr=np.array([[1,2],[3,4]])
df2=pd.DataFrame(arr,columns=['A','B'])
print(df2)
print(dataframe.loc[0,["Name","age"]])
print(dataframe.iloc[0,1])