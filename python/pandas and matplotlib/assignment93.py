import matplotlib.pyplot as plt
import pandas as pd
data={'year':[2020,2021,2022,2023,2024,2025],
'it':[56,78,90,65,87,55],
'civil':[45,68,76,34,90,78]}
df=pd.DataFrame(data)
df.plot(x='year',y=['it','civil'])
plt.xlabel('Year')
plt.ylabel('IT & CIVIL')
plt.title('It v/s Civil')
plt.show()