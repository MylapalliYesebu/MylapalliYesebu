# Write a program to Implement Support Vector Machines and Principle Component Analysis
import numpy as np
import matplotlib.pyplot as plt

# Generate a sample dataset (100 samples with 3 features)
np.random.seed(0)
data = np.random.rand(100, 3)

# Step 1: Standardize the data (mean=0, variance=1)
mean = np.mean(data, axis=0)
std_dev = np.std(data, axis=0)
standardized_data = (data - mean) / std_dev

# Step 2: Calculate the covariance matrix
cov_matrix = np.cov(standardized_data, rowvar=False)

# Step 3: Compute the eigenvalues and eigenvectors of the covariance matrix
eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)

# Step 4: Sort eigenvalues and corresponding eigenvectors in descending order
sorted_indices = np.argsort(eigenvalues)[::-1]
eigenvalues = eigenvalues[sorted_indices]
eigenvectors = eigenvectors[:, sorted_indices]

# Step 5: Select the top k eigenvectors to retain k principal components
k = 2  # Choose the number of principal components
top_k_eigenvectors = eigenvectors[:, :k]

# Step 6: Project the data onto the new feature space
pca_data = standardized_data.dot(top_k_eigenvectors)

# Optional: Visualize the reduced data
plt.scatter(pca_data[:, 0], pca_data[:, 1], color='teal', alpha=0.7)
plt.title('PCA of Sample Data')
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.grid(True)
plt.show()
