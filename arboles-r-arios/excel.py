import pandas as pd
import json

# f = open('benchmark_preorden.json', 'r')
# data = json.load(f)
# df = pd.DataFrame(data)
# df.to_excel('preorden.xlsx', index=False)

# f2 = open('benchmark_niveles.json', 'r')
# data2 = json.load(f2)
# df2 = pd.DataFrame(data2)
# df2.to_excel('niveles.xlsx', index=False)

f3 = open('benchmark_buscar.json', 'r')
data3 = json.load(f3)
df3 = pd.DataFrame(data3)
df3.to_excel('buscar.xlsx', index=False)