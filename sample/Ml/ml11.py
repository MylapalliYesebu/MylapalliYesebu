# Write a program to Implement Support Vector Machines and Principle Component Analysis

import pandas as pd
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report

# Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target

# Standardize the features
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Apply PCA (reduce to 2 components for visualization)
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

# Split the dataset
X_train, X_test, y_train, y_test = train_test_split(X_pca, y, test_size=0.2, random_state=42)

# Train Support Vector Machine (SVM)
svm = SVC(kernel='linear')  # You can change kernel: 'linear', 'rbf', etc.
svm.fit(X_train, y_train)

# Predict and evaluate
y_pred = svm.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))


# Accuracy: 0.9

# Classification Report:
#                precision    recall  f1-score   support

#            0       1.00      1.00      1.00        10
#            1       0.88      0.78      0.82         9
#            2       0.83      0.91      0.87        11

#     accuracy                           0.90        30
#    macro avg       0.90      0.90      0.90        30
# weighted avg       0.90      0.90      0.90        30
