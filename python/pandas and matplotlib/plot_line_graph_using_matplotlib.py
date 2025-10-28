import pandas as pd
import matplotlib.pyplot as plt
dataset={
    'Year': [2020, 2021, 2022, 2023, 2024],
    'covid-data':[25,35,17,20,18],
    'heart-disease':[80,95,70,115,140],
}
dframe=pd.DataFrame(dataset)
dframe.plot(x='Year', y=['covid-data', 'heart-disease'], title='Infected over time')
plt.show()