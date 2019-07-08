import numpy as np
import pandas as pd


correlation_threshold = 0.5

def removeHighCorrelationColumns(features):
    corr = features.corr()
    corr_triu = corr.where(~np.tril(np.ones(corr.shape)).astype(np.bool))   #taking upper triangle only for the symmetric matrix
    corr_triu = corr_triu.stack()
    feature_frame = corr_triu[corr_triu > 0.3].to_frame()




