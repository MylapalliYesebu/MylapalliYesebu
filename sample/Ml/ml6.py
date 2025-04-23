# Experiment-6: Write a program to implement Categorical Encoding, One- hot Encoding

import pandas as pd

# Sample data
data = {'Category': ['A', 'B', 'A', 'C', 'B']}

# Creating DataFrame
df = pd.DataFrame(data)

# Categorical encoding using dictionary mapping
category_mapping = {'A': 0, 'B': 1, 'C': 2}
df['Category_Encoded'] = df['Category'].map(category_mapping)

print("Categorical Encoding:")
print(df)

# One-hot encoding using pandas
df_encoded = pd.get_dummies(df[['Category']], prefix='Category')
print("\nOne-hot Encoding:")
print(df_encoded)

# Output:
# Categorical Encoding:
#   Category  Category_Encoded
# 0        A                 0
# 1        B                 1
# 2        A                 0
# 3        C                 2
# 4        B                 1

# One-hot Encoding:
#    Category_A  Category_B  Category_C
# 0        True       False       False
# 1       False        True       False
# 2        True       False       False
# 3       False       False        True
# 4       False        True       False