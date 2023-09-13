import pandas as pd
import json

f = open('benchmark_preorden.json', 'r')
f2 = open('benchmark_niveles.json', 'r')

data = json.load(f)
data2 = json.load(f2)

df = pd.DataFrame(data)
df.to_excel('preorden.xlsx', index=False)

df2 = pd.DataFrame(data2)
df2.to_excel('niveles.xlsx', index=False)