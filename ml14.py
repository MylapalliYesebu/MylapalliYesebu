# Write a program to Implement Support Vector Machines and Principle Component Analysis
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn import svm
from sklearn.decomposition import PCA
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Step 1: Load a dataset (Iris dataset as an example)
iris = datasets.load_iris()
X = iris.data
y = iris.target

# Step 2: Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 3: Implement Principal Component Analysis (PCA)
n_components = 2  # Reduce to 2 dimensions for visualization
pca = PCA(n_components=n_components)
X_train_pca = pca.fit_transform(X_train)
X_test_pca = pca.transform(X_test)

# Step 4: Visualize the PCA-reduced data (optional)
plt.figure(figsize=(8, 6))
colors = ['navy', 'turquoise', 'darkorange']
lw = 2

for color, i, target_name in zip(colors, [0, 1, 2], iris.target_names):
    plt.scatter(X_train_pca[y_train == i, 0], X_train_pca[y_train == i, 1],
                color=color, alpha=0.8, lw=lw, label=target_name)

plt.legend(loc='best', shadow=False, scatterpoints=1)
plt.title('PCA of IRIS dataset')
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.grid(True)
plt.show()

# Step 5: Implement Support Vector Machine (SVM) with the PCA-reduced data
clf = svm.SVC(kernel='linear', C=1)
clf.fit(X_train_pca, y_train)

# Step 6: Make predictions and evaluate the SVM model
y_pred = clf.predict(X_test_pca)
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy of SVM with PCA: {:.2f}%".format(accuracy * 100))
