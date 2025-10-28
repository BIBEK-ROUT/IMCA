import pandas as pd
import numpy as np   # often used alongside pandas
s = pd.Series([10, 20, 30], index=['a','b','c'], name='score')
print(s)
# a    10 
# b    20
# c    30
# Name: score, dtype: int64
df = pd.DataFrame({
    "Name": ["Alice", "Bob", "Charlie","doom","tony","bruce"],
    "Age": [25, 30, 35,40,45,50],
    "City": ["New York", "Paris", "London","tokyo","kathmandu","africa"]
})
print(df)
print(df.head())        # first 5 rows
print(df.tail(6))       # last 2 rows
print(df.shape)         # (rows, columns)
print(df.columns)       # Index of column names
print(df.dtypes)        # data types of each column
print(df.info())        # concise summary (non-null counts)
print(df.describe())    # numeric summary (count, mean, std, etc.)
print("new part")
print(df["Name"])           # one column -> Series
print(df[["Name","Age"]])   # multiple columns -> DataFrame

print(df.loc[0])            # row by label/index (if index labels are integers this is label-based)
print(df.iloc[0])           # row by integer position (0-based)
print(df.loc[0, "Name"])    # scalar by label
print(df.iloc[0, 1])       # scalar by position

# fast accessors for single scalar
print(df.at[0, "Name"])     # label-based scalar access
print(df.iat[0, 1])         # integer-pos-based scalar access

print("new data of f2:")
rows = [
    {"Name": "Alice", "Age": 25},
    {"Name": "Bob", "Age": 30, "City": "Paris"},
    {"Name": "Charlie", "City": "London"}
]
df2 = pd.DataFrame(rows)
print(df2)
print(df2.head())        # first 5 rows
print(df2.tail(2))       # last 2 rows
print(df2.shape)         # (rows, columns)
print(df2.columns)       # Index of column names
print(df2.dtypes)        # data types of each column
print(df2.info())        # concise summary (non-null counts)
print(df2.describe())    # numeric summary (count, mean, std, etc.)
print("new data of f3:")
arr = np.array([[1,2,3],[4,5,6]])
df3 = pd.DataFrame(arr, columns=['A','B','c'])
print(df3)
print(df3.head())        # first 5 rows
print(df3.tail(2))       # last 2 rows
print(df3.shape)         # (rows, columns)
print(df3.columns)       # Index of column names
print(df3.dtypes)        # data types of each column
print(df3.info())        # concise summary (non-null counts)
print(df3.describe())    # numeric summary (count, mean, std, etc.)