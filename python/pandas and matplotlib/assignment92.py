import matplotlib.pyplot as plt
import pandas as pd
data={'year':[2020,2021,2022,2023,2024,2025],
'it':[65,80,89,100,90,75]}
df=pd.DataFrame(data)
df.plot.bar(x='year',y=['it'], color='red')
plt.xlabel('Year')
plt.ylabel('IT')
plt.title('IT demand')
plt.show()