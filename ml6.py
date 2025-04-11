# Write a program to implement Categorical Encoding, One-hot Encoding

import pandas as pd  # Make sure this line is at the top

# Sample data
data = {'Category': ['A', 'B', 'A', 'C', 'B']}

# Create DataFrame
df = pd.DataFrame(data)

# --- Categorical Encoding (Label Encoding) ---
category_mapping = {'A': 0, 'B': 1, 'C': 2}
df['Category_Encoded'] = df['Category'].map(category_mapping)

print("Categorical (Label) Encoded DataFrame:")
print(df)

# --- One-Hot Encoding ---
df_onehot = pd.get_dummies(df['Category'], prefix='Category')

print("\nOne-Hot Encoded DataFrame:")
print(df_onehot)



# # Output:
# Categorical (Label) Encoded DataFrame:
#   Category  Category_Encoded
# 0        A                 0
# 1        B                 1
# 2        A                 0
# 3        C                 2
# 4        B                 1

# One-Hot Encoded DataFrame:
#    Category_A  Category_B  Category_C
# 0           1           0           0
# 1           0           1           0
# 2           1           0           0
# 3           0           0           1
# 4           0           1           0
