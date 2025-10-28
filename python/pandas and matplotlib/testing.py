import pandas as pd
import numpy as np
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

print(df.loc[0,"Age"])            # row by label/index (if index labels are integers this is label-based)
print(df.iloc[1,2])           # row by integer position (0-based)
print(df.loc[0, "Name"])    # scalar by label
print(df.iloc[0, 1])       # scalar by position

# fast accessors for single scalar
print(df.at[0,"City"])     # label-based scalar access
print(df.iat[0, 1])         # integer-pos-based scalar access
