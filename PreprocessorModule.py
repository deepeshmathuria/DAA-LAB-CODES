import pandas as pd
import numpy as np
import logging
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from src.DataCLRModules.LowVarianceFilter import LowVarianceFilterModule
from src.DataCLRModules.HighCorrelationFilter import HighCorrelationFilterModule
from src.DataCLRModules.RandomForestFeatureSelector import RandomForestFeatureSelectorModule


def preProcessData(filepath, n_features, n_labels, enable_low_variance_filter, enable_high_correlation_filter,
                   enable_random_forest_feature_selection, test_train_split_ratio=0.7):
    supervised = True
    data = pd.read_csv(filepath)
    data.dropna(thresh=2)  ##data cleanup for null entries
    logging.info("Data Size", len(data))
    logging.info("Data Shape", data.shape)
    if (n_labels == 0):
        supervised = False

    if (supervised == True):  ##data slicing
        # Features = data.values[0:n_features - 1]
        # Labels = data.values[n_features:-1]
        Features, Labels = data.iloc[:, :n_features].values, data.iloc[:, n_features:].values
        X_train, X_test, y_train, y_test = train_test_split(
            Features, Labels, test_size=0.3,
            stratify=Labels, random_state=0
        )

        if (enable_low_variance_filter == True):
            Features = LowVarianceFilterModule.removeLowVarianceColumns(Features)
        if (enable_high_correlation_filter == True):
            Features = HighCorrelationFilterModule.removeHighCorrelationFilters(Features)
        if (enable_random_forest_feature_selection == True):
            Features = RandomForestFeatureSelectorModule.removeUnimportantFeaturesWithLessPurity(Features, Labels)

        return (Features, Labels)

    else:
        Features = data.values[0:n_features - 1]
        return Features
