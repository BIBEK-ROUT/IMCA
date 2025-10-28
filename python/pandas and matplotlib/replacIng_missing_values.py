import pandas as pd
import numpy as np

# Step 1 — Create DataFrame with missing values
df = pd.DataFrame({
    "Name": ["Alice", "Bob", None, "David"],
    "Age": [25, np.nan, 35, 40],
    "City": ["New York", "Paris", None, None]
})
print("Original DataFrame:\n", df)

# Step 2 — Detect Missing Values
print("\nCheck where values are missing:\n", df.isnull())

# Step 3 — Count Missing Values per Column
print("\nCount of missing values per column:\n", df.isnull().sum())

# Step 4 — Remove Rows with Missing Values
df_drop = df.dropna()
print("\nAfter removing rows with missing values:\n", df_drop)

# Step 5 — Replace Missing Values
df_fill = df.fillna({
    "Name": "Unknown",                  # Replace missing Name with 'Unknown'
    "Age": df["Age"].mean(),             # Replace missing Age with average age
    "City": "Not Specified"               # Replace missing City with 'Not Specified'
})
print("\nAfter replacing missing values:\n", df_fill)
