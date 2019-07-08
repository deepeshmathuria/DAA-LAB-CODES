from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
import pandas as pd
import matplotlib as plt

def getColumns(n):
    column = []
    for i in range(1,n):
        column.append('principal component '+ i)
    return column


def performPCA(features, components):
    columns = getColumns(components)
    pca = PCA(n_components=components)
    X = StandardScaler().fit_transform(features)
    pca_result = pca.fit_transform(X)
    principalDf = pd.DataFrame(data = pca_result
                               , columns = columns)
    return principalDf
